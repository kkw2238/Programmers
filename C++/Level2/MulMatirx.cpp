/*
	https://programmers.co.kr/learn/courses/30/lessons/12949
*/

#include <vector>

using namespace std;

vector<vector<int>> operator*(const vector<vector<int>>& l, const vector<vector<int>>& r)
{
	vector<vector<int>> result(l.size(), vector<int>(r[0].size()));

	for (int y = 0; y < result.size(); ++y)
	{
		for (int x = 0; x < result[y].size(); ++x)
		{
			int sum = 0;

			for (int rowIndex = 0; rowIndex < r.size(); ++rowIndex)
			{
				sum += l[y][rowIndex] * r[rowIndex][x];
			}

			result[y][x] = sum;
		}
	}

	return result;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	return arr1 * arr2;
}
// 예전 코드
//#include <vector>
//
//using namespace std;
//
//vector<int> MulVector(const vector<int> lValue, const vector<vector<int>>& rValue) {
//	vector<int> result(rValue[0].size());
//
//	for (int i = 0; i < rValue[0].size(); ++i) {
//		for (int j = 0; j < lValue.size(); ++j) {
//			result[i] += lValue[j] * rValue[j][i];
//		}
//	}
//
//	return result;
//}
//
//vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
//	vector<vector<int>> answer;
//
//	for (vector<int> vi : arr1) {
//		answer.push_back(MulVector(vi, arr2));
//	}
//
//	return answer;
//}