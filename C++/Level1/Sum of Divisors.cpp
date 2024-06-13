/*
	https://programmers.co.kr/learn/courses/30/lessons/12928
*/

#include <math.h>

using namespace std;

int solution(int n) {
	int answer = 0;
	const int SQRT = sqrt(n);

	for (int i = 1; i <= SQRT; ++i) 
	{
		if (n % i == 0) 
		{
			// n / i == 0�� ��� i�� ����̸� (n / i)�� n ����̴�.
			answer += i + (n / i);

			// �������� ��� ������ 2������ ���⿡ 1�� ����
			if (i * i == n)
			{
				answer -= i;
			}
		}
	}

	return answer;
}
//12 1 12 2 6 3 4 