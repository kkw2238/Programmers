/*
	https://programmers.co.kr/learn/courses/30/lessons/12924
*/

#include <vector>

using namespace std;

int DFS(const vector<int>& numbers, const int sum, const int target, const int index) {
	int result = 0;

	if (index == numbers.size()) {
		return sum == target ? 1 : 0;
	}

	result += DFS(numbers, sum + numbers[index], target, index + 1);
	result += DFS(numbers, sum - numbers[index], target, index + 1);

	return result;
}


int solution(vector<int> numbers, int target) {
	return DFS(numbers, 0, target, 0);
}