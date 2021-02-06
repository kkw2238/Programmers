#include <vector>

using namespace std;

#include <iostream>
vector<int> MulVector(const vector<int> lValue, const vector<vector<int>>& rValue) {
	vector<int> result(rValue[0].size());

	for (int i = 0; i < rValue[0].size(); ++i) {
		for (int j = 0; j < lValue.size(); ++j) {
			result[i] += lValue[j] * rValue[j][i];
		}
	}

	return result;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (vector<int> vi : arr1) {
		answer.push_back(MulVector(vi, arr2));
	}

	return answer;
}