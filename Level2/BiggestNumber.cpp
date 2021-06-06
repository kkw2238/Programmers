/*
	https://programmers.co.kr/learn/courses/30/lessons/42883
*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

	for (int i = 0; i < number.length() - 1; ++i)
	{
		if (number[i] < number[i + 1] && k > 0)
		{
			number.erase(i--, 1);
			--k;
		}
		
		if (number.length() - i <= k)
		{
			number.erase(i);
		}
	}

	return number;
}

/* 예전 코드
#include <string>
#include <vector>

using namespace std;

#define ToNumber(x) x - '0'

const int ZERO = '0';

string solution(string number, int k) {

	while (k > 0)
	{
		for (int i = 0; i < number.length() - 1 && k != 0;)
		{
			if (ToNumber(number[i]) < ToNumber(number[i + 1]))
			{
				number.erase(i, 1);
				i = 0;
				--k;
			}
			else
			{
				++i;
			}
		}

		if (k > 0) 
		{
			number.erase(number.length() - 1);
			--k;
		}
	}

	return number;
}
*/