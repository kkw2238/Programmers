/*
	https://programmers.co.kr/learn/courses/30/lessons/12977
*/

#include <vector>
#include <cmath>

using namespace std;

const bool IsFrimeNumber(const int num) {
	int sqrtNum = sqrt(num);

	for (int i = 2; i <= sqrtNum; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int solution(vector<int> nums) {
	int result = 0;

	for (int first = 0; first < nums.size() - 2; ++first)
	{
		for (int second = first + 1; second < nums.size() - 1; ++second)
		{
			for (int third = second + 1; third < nums.size(); ++third)
			{
				result += IsFrimeNumber(nums[first] + nums[second] + nums[third]);
			}
		}
	}

	return result;
}