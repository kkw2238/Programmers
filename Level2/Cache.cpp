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

	// ĳ�� �����  0�� ��� �׻� ĳ�� �̽�
	if (cacheSize == 0)
	{
		return cities.size() * CACHE_MISS;
	}

	for (string& city : cities)
	{		
		// �ҹ��ڷ� ���� �Ͽ� ĳ�� ���� �� Ž��
		transform(city.begin(), city.end(), city.begin(), tolower);
		auto iter = find(LRU.begin(), LRU.end(), city);
		
		// ã�� ���� ���
		if (iter == LRU.end())
		{
			// ĳ�ð� �� �� ���
			if (LRU.size() == cacheSize)
			{
				// ���� �������� ã�� ���� ĳ�ø� ����
				LRU.pop_front();
			}
			answer += CACHE_MISS;
		}
		// ã�� ���
		else
		{
			// ���� �� ���߿� �ǵڿ� �߰�
			LRU.erase(iter);
			answer += CACHE_HIT;
		}

		LRU.push_back(city);
	}

	return answer;
}


/* ���� �ڵ�
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