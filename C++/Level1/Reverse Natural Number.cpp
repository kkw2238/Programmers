/*
	https://programmers.co.kr/learn/courses/30/lessons/12932
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
	// 문자열로 변환
	string str = to_string(n);
	vector<int> answer(str.length());

	// str의 rbegin부터 rend까지 순회하며 문자를 int형으로 변환
	::transform(str.rbegin(), str.rend(), answer.begin(), [](const char c) {
		return c - '0';
	});

	return answer;
}