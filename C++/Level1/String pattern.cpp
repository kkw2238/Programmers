/*
	https://programmers.co.kr/learn/courses/30/lessons/12922
*/

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	const string STRING_PATTERN = "����";
	string answer = "";

	for (int i = 0; i < n / 2; ++i)
	{
		answer += STRING_PATTERN;
	}

	if (n % 2 == 1)
	{
		answer += "��";
	}

	return answer;
}