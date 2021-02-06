/*
	https://programmers.co.kr/learn/courses/30/lessons/12941
*/

#include <functional>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int Combination(vector<int> A, vector<int> B, int beforeSumNum, int index) {
	int result = 0;
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), less<int>());

	for (int i = 0; i < A.size(); ++i)
		result += A[i] * B[i];

	return result;
}

int solution(vector<int> A, vector<int> B)
{
	return Combination(A, B, 0, 0);
}