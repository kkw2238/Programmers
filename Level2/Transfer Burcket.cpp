/*
	https://programmers.co.kr/learn/courses/30/lessons/60058
*/

#include <string>
#include <vector>

using namespace std;

const char RB = ')', LB = '(';

int FinduIndex(const string& str) {
	int rightBracket = 0, leftBracket = 0;

	for (const char c : str) {
		if (c == RB) ++rightBracket;
		else ++leftBracket;

		if (rightBracket == leftBracket) break;
	}

	return rightBracket + leftBracket;
}

bool IsRightString(const string& str) {
	int rightBracket = 0, leftBracket = 0;

	for (const char c : str) {
		if (c == RB) ++rightBracket;
		else ++leftBracket;

		if (rightBracket > leftBracket) return false;
	}

	return true;
}

string MakeReverseBrackets(const string& str) {
	string result = str.substr(1, str.length() - 2);
	for (char& c : result) {
		if (c == RB) c = LB;
		else c = RB;
	}

	return result;
}

string MakeRightBrackets(const string& str) {
	if (str.empty()) return "";

	int uIndex = FinduIndex(str);
	string u = str.substr(0, uIndex), v = str.substr(uIndex);

	if (!IsRightString(u)) return "(" + MakeRightBrackets(v) + ")" + MakeReverseBrackets(u);
	else return u + MakeRightBrackets(v);
}

string solution(string p) {
	if (p.empty()) return p;

	string answer = "";

	answer = MakeRightBrackets(p);

	return answer;
}