/*
	[(2017��)KAKAO BLIND RECRUITMENT] [1��] ĳ��
	https://programmers.co.kr/learn/courses/30/lessons/17680
*/
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	const int CACHE_HIT = 1, CACHE_MISS = 5;
	int result = 0;
	list<string> caches;

	// ĳ�� ���۰� 0�� ��� ��� ��쿡 ���� CACHE_MISS�� �߻��ϱ� ������ �ٷ� ��ȯ
	if (cacheSize == 0) return cities.size() * CACHE_MISS;

	for (string& str : cities) {
		// ��ҹ��� ������ ����� �ϱ⿡ ��� ���ڿ��� �ҹ��ڷ� ��ȯ
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		auto iter = find(caches.begin(), caches.end(), str);

		// ĳ�ÿ� ������ ���( CACHE_HIT�� ��� )
		if (iter != caches.end()) {
			// �ش� ���ڸ� �ٽ� �� �ڷ� �̵�
			caches.erase(iter);
			caches.push_back(str);

			result += CACHE_HIT;
		}
		// ĳ�ÿ� �������� ���� ��� ( CACHE_MISS�� ��� ) 
		else {
			// �� �ڿ� ���ڿ��� �߰�
			caches.push_back(str);

			// ĳ�� ���۸� �ʰ��� ���, ���� �������� ������ ĳ�ø� ����
			if (caches.size() > cacheSize) caches.pop_front();

			result += CACHE_MISS;
		}
	}
	return result;
}