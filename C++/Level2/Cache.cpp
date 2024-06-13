/*
	https://programmers.co.kr/learn/courses/30/lessons/17680
*/

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

	// 캐시 사이즈가  0인 경우 항상 캐시 미스
	if (cacheSize == 0)
	{
		return cities.size() * CACHE_MISS;
	}

	for (string& city : cities)
	{		
		// 소문자로 통일 하여 캐시 저장 및 탐색
		transform(city.begin(), city.end(), city.begin(), tolower);
		auto iter = find(LRU.begin(), LRU.end(), city);
		
		// 찾지 못한 경우
		if (iter == LRU.end())
		{
			// 캐시가 꽉 찬 경우
			if (LRU.size() == cacheSize)
			{
				// 가장 오랫동안 찾지 않은 캐시를 삭제
				LRU.pop_front();
			}
			answer += CACHE_MISS;
		}
		// 찾은 경우
		else
		{
			// 삭제 후 나중에 맨뒤에 추가
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