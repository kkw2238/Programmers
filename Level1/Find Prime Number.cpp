/*
	https://programmers.co.kr/learn/courses/30/lessons/12921
*/

#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
	vector<int> primeNumbers(1, 2);

	// 짝수는 2를 제외하고는 전부 소수가 아니기에 홀수만 판별
	for (int number = 3; number <= n; number += 2)
	{
		// 소수 여부를 판별하는데 있어 제곱근까지만 확인하면 된다.
		const int SQRT_NUMBER = sqrt(number);

		// 소수로 판별난 숫자들을 재활용
		for (int primeNumber : primeNumbers)
		{
			// number가 기존의 소수와 나누어 떨어질 경우 다음 수로 넘어감
			if (number % primeNumber == 0)
			{
				break;
			}
			// primeNumber이 number의 제곱근을 넘어간 경우 => number는 소수로 판명 
			else if (primeNumber > SQRT_NUMBER)
			{
				// 재사용을 위해 primeNumbers에 저장해둔다.
				primeNumbers.push_back(number);
				break;
			}
		}
	}

	return static_cast<int>(primeNumbers.size());
}