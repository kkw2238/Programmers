/*
	https://programmers.co.kr/learn/courses/30/lessons/12932
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
	// ���ڿ��� ��ȯ
	string str = to_string(n);
	vector<int> answer(str.length());

	// str�� rbegin���� rend���� ��ȸ�ϸ� ���ڸ� int������ ��ȯ
	::transform(str.rbegin(), str.rend(), answer.begin(), [](const char c) {
		return c - '0';
	});

	return answer;
}