/*
	https://programmers.co.kr/learn/courses/30/lessons/43104
*/
#include <vector>

using namespace std;

long long solution(int N) {
	vector<long long> length = { 0 , 1 };

	for (int i = 1; i <= N; ++i)
		length.push_back(length{i] + length{i - 1]);

	return length{N + 1] * 2 + length{N] * 2;
}
