/*
	https://programmers.co.kr/learn/courses/30/lessons/12930
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	int index = 0;

	for (char& c : s) 
	{
		// 공백 만날시 index를 초기화
		if (c == ' ') 
		{
			index = 0;
			continue;
		}
		
		// 각 문자열의 홀수번째 문자는 대문자로 변환 
		if (index % 2 == 0)
		{
			c = toupper(c);
		}
		// 그 외의 경우 소문자로 변환
		else
		{
			c = tolower(c);
		}

		++index;
	}

	return s;
}