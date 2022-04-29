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
		// 지금까지 누적합이 음수인 경우 다시 더하기 시작
		sum = max(0, sum) + number;
		/*
			1. sum이 음수이며, number가 음수인 경우
				|number| < |sum| 라면 
				sum = number이 되기에 기존의 sum값보다 더 크다.

				|number| > |sum| 라면 
				sum = number로 오히려 sum값보다 작아지지만,
				기존의 result값보다 커지는 것이 불가능하기에 문제 없다.

			2. sum이 음수이며, number가 양수인 경우
				sum을 0으로 초기화 하고 number를 더하는 것이 수가 더 크다.
		
			3. sum이 양수이며, number가 양수인 경우
				두 수를 더한 결과값이 result보다 큰 경우 덮어 씌우기에 문제가 없다.

			4. sum이 양수이며, number가 음수인 경우
				두 수를 더한 결과 값은 result에 덮어 씌워지진 않지만
				계속해서 더 해나간다.
		*/
		result = max(sum, result);
	}

	return result;
}