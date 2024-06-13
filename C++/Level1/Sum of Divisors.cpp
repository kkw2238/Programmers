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
			// n / i == 0인 경우 i도 약수이며 (n / i)도 n 약수이다.
			answer += i + (n / i);

			// 제곱근의 경우 정보가 2중으로 들어가기에 1번 제거
			if (i * i == n)
			{
				answer -= i;
			}
		}
	}

	return answer;
}
//12 1 12 2 6 3 4 