/*
	https://programmers.co.kr/learn/courses/30/lessons/12935
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	auto iter = min_element(arr.begin(), arr.end());
	arr.erase(iter);

	if (arr.size() == 0)
	{
		return vector{ -1 };
	}
	return arr;
}