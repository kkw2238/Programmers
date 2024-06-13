/*
	[(2017년)KAKAO BLIND RECRUITMENT] [1차] 캐시
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

	// 캐시 버퍼가 0인 경우 모든 경우에 대해 CACHE_MISS가 발생하기 때문에 바로 반환
	if (cacheSize == 0) return cities.size() * CACHE_MISS;

	for (string& str : cities) {
		// 대소문자 구분이 없어야 하기에 모든 문자열을 소문자로 변환
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		auto iter = find(caches.begin(), caches.end(), str);

		// 캐시에 존재할 경우( CACHE_HIT의 경우 )
		if (iter != caches.end()) {
			// 해당 문자를 다시 맨 뒤로 이동
			caches.erase(iter);
			caches.push_back(str);

			result += CACHE_HIT;
		}
		// 캐시에 존재하지 않을 경우 ( CACHE_MISS의 경우 ) 
		else {
			// 맨 뒤에 문자열을 추가
			caches.push_back(str);

			// 캐시 버퍼를 초과한 경우, 가장 오랫동안 사용안한 캐시를 제거
			if (caches.size() > cacheSize) caches.pop_front();

			result += CACHE_MISS;
		}
	}
	return result;
}