/*
	https://programmers.co.kr/learn/courses/30/lessons/43105
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int LEFT(const int x) { return x; }
const int RIGHT(const int x) { return x + 1; }

int solution(vector<vector<int>> triangle) {
	const size_t height = triangle.size();
	vector<int> totalData(height);

	totalData[0] = triangle[0][0];

	for (size_t i = 0; i < height - 1; ++i) {
		vector<int> tmpDatas(i + 2, 0);
		for (size_t j = 0; j <= i; ++j) {
			int leftValue = totalData[j] + triangle[i + 1][LEFT(j)];
			int rightValue = totalData[j] + triangle[i + 1][RIGHT(j)];

			tmpDatas[LEFT(j)] = tmpDatas[LEFT(j)] < leftValue ? leftValue : tmpDatas[LEFT(j)];
			tmpDatas[RIGHT(j)] = tmpDatas[RIGHT(j)] < rightValue ? rightValue : tmpDatas[RIGHT(j)];
		}
		totalData = tmpDatas;
	}

	return *max_element(totalData.begin(), totalData.end());
}