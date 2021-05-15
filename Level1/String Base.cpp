/*
	https://programmers.co.kr/learn/courses/30/lessons/12918
*/

#include <string>

using namespace std;

const int A_LENGTH = 4;
const int B_LENGTH = 6;

const bool IsRightLength(const string& s)
{
	return s.length() == A_LENGTH || s.length() == B_LENGTH;
}

bool solution(string s) {
	if (!IsRightLength(s))
	{
		return false;
	}

	for (char c : s) 
	{
		if (!isdigit(c)) 
		{
			return false;
		}
	}

	return true;
}