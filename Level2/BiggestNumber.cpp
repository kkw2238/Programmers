/*
	https://programmers.co.kr/learn/courses/30/lessons/42883
*/

#include "../../Util.h"

/*
	어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

	예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다.

	이 중 가장 큰 숫자는 94 입니다.

	문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다.

	number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

*/

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

#include <iostream>
int main()
{
	string number = "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998";
	int k = 1;

	cout << solution(number, k);
}

/*
	"4177252841" k = 4
	"77252841" k = 2




*/