#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

const int CACHE_HIT = 1;
const int CACHE_MISS = 5;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	list<string> LRU;

	if (cacheSize == 0)
	{
		return cities.size() * CACHE_MISS;
	}

	for (string& city : cities)
	{		
		transform(city.begin(), city.end(), city.begin(), tolower);
		auto iter = find(LRU.begin(), LRU.end(), city);
		
		if (iter == LRU.end())
		{
			if (LRU.size() == cacheSize)
			{
				LRU.pop_front();
			}
			answer += CACHE_MISS;
		}
		else
		{
			LRU.erase(iter);
			answer += CACHE_HIT;
		}

		LRU.push_back(city);
	}

	return answer;
}


/* 예전 코드
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	const int CACHE_HIT = 1, CACHE_MISS = 5;
	int result = 0;
	list<string> caches;

	for (string& str : cities) {
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		auto iter = find(caches.begin(), caches.end(), str);

		if (iter != caches.end()) {
			caches.erase(iter);
			caches.push_back(str);

			result += CACHE_HIT;
		}
		else {
			caches.push_back(str);
			if(caches.size() > cacheSize) caches.pop_front();

			result += CACHE_MISS;
		}
	}

	if (cacheSize == 0) return cities.size() * CACHE_MISS;
	return result;
}
*/