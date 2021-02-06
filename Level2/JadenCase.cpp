/*
	https://programmers.co.kr/learn/courses/30/lessons/12951
*/
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string s) {
	bool isFirstWord = true;
	transform(s.begin(), s.end(), s.begin(), [&isFirstWord](char c) {
		if (c == ' ') {
			isFirstWord = true;
			return c;
		}
		else if (isFirstWord) {
			isFirstWord = false;
			return static_cast<char>(toupper(c));
		}
		else {
			return static_cast<char>(tolower(c));
		}

	});

	return s;
}