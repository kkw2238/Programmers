/*
	https://programmers.co.kr/learn/courses/30/lessons/43165
*/

#include <vector>

using namespace std;

int FindTarget(const vector<int>& numbers, const int nowSum, const int target, const int nowIndex)
{
	if (nowIndex == numbers.size())
	{
		return nowSum == target;
	}

	return FindTarget(numbers, nowSum + numbers[nowIndex], target, nowIndex + 1) +
		FindTarget(numbers, nowSum - numbers[nowIndex], target, nowIndex + 1);
}

int solution(vector<int> numbers, int target) {
	return FindTarget(numbers, 0, target, 0);
}

/* 예전 코드
#include <vector>

using namespace std;

int DFS(const vector<int>& numbers, const int sum, const int target, const int index) {
	int result = 0;

	if (index == numbers.size())
	{
		return sum == target ? 1 : 0;
	}

	result += DFS(numbers, sum + numbers[index], target, index + 1);
	result += DFS(numbers, sum - numbers[index], target, index + 1);

	return result;
}


int solution(vector<int> numbers, int target) {
	return DFS(numbers, 0, target, 0);
}
*/
