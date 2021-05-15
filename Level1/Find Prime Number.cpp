/*
	https://programmers.co.kr/learn/courses/30/lessons/12921
*/

#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
	vector<int> primeNumbers(1, 2);

	// ¦���� 2�� �����ϰ�� ���� �Ҽ��� �ƴϱ⿡ Ȧ���� �Ǻ�
	for (int number = 3; number <= n; number += 2)
	{
		// �Ҽ� ���θ� �Ǻ��ϴµ� �־� �����ٱ����� Ȯ���ϸ� �ȴ�.
		const int SQRT_NUMBER = sqrt(number);

		// �Ҽ��� �Ǻ��� ���ڵ��� ��Ȱ��
		for (int primeNumber : primeNumbers)
		{
			// number�� ������ �Ҽ��� ������ ������ ��� ���� ���� �Ѿ
			if (number % primeNumber == 0)
			{
				break;
			}
			// primeNumber�� number�� �������� �Ѿ ��� => number�� �Ҽ��� �Ǹ� 
			else if (primeNumber > SQRT_NUMBER)
			{
				// ������ ���� primeNumbers�� �����صд�.
				primeNumbers.push_back(number);
				break;
			}
		}
	}

	return static_cast<int>(primeNumbers.size());
}