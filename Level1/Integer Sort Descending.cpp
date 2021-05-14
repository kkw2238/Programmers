/*
	https://programmers.co.kr/learn/courses/30/lessons/12933
*/

#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	// 문자열로 변환
	string numStr = to_string(n);

	// 변환한 문자열을 내림차순으로 정렬
	sort(numStr.begin(), numStr.end(), greater<char>());

	// 정렬한 문자를 long long 형변환
	return stoll(numStr);
}