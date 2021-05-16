/*
	https://programmers.co.kr/learn/courses/30/lessons/12903
*/

#include <string>

using namespace std;

string solution(string s) {
	const size_t LENGTH = s.length();
	int offset = 0;
	int count = 0;

	if (LENGTH % 2 == 1)
	{
		offset = LENGTH / 2;
		count = 1;
	}
	else 
	{
		offset = LENGTH / 2 - 1;
		count = 2;
	}

	return s.substr(offset, count);
}