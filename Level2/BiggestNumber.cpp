/*
	https://programmers.co.kr/learn/courses/30/lessons/42883
*/

#include "../../Util.h"

/*
	� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

	���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�.

	�� �� ���� ū ���ڴ� 94 �Դϴ�.

	���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�.

	number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

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