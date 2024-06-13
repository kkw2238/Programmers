/*
	https://programmers.co.kr/learn/courses/30/lessons/12909
*/
#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	int left = 0, right = 0;

	for (char c : s) {
		(c == '(') ? ++left : ++right;
		if (right > left) return false;
	}

	return left == right;
}