#include <vector>

using namespace std;

int Find_BiggestSumNumbers(const vector<int>& numbers)
{
	int biggestSumNumber = numeric_limits<int>::min();

	for (int i = 0; i < numbers.size(); ++i)
	{
		int sum = 0;

		for (int j = i; j < numbers.size(); ++j)
		{
			sum += numbers[j];

			if (sum > biggestSumNumber)
			{
				biggestSumNumber = sum;
			}
		}
	}

	return biggestSumNumber;
}

int Find_DP_BiggstSumNumber(const vector<int>& numbers)
{
	int sum = 0;
	int result = numeric_limits<int>::min();

	for (int number : numbers)
	{
		// ���ݱ��� �������� ������ ��� �ٽ� ���ϱ� ����
		sum = max(0, sum) + number;
		/*
			1. sum�� �����̸�, number�� ������ ���
				|number| < |sum| ��� 
				sum = number�� �Ǳ⿡ ������ sum������ �� ũ��.

				|number| > |sum| ��� 
				sum = number�� ������ sum������ �۾�������,
				������ result������ Ŀ���� ���� �Ұ����ϱ⿡ ���� ����.

			2. sum�� �����̸�, number�� ����� ���
				sum�� 0���� �ʱ�ȭ �ϰ� number�� ���ϴ� ���� ���� �� ũ��.
		
			3. sum�� ����̸�, number�� ����� ���
				�� ���� ���� ������� result���� ū ��� ���� ����⿡ ������ ����.

			4. sum�� ����̸�, number�� ������ ���
				�� ���� ���� ��� ���� result�� ���� �������� ������
				����ؼ� �� �س�����.
		*/
		result = max(sum, result);
	}

	return result;
}