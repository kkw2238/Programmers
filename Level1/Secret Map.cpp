/*
	https://programmers.co.kr/learn/courses/30/lessons/17681
*/

#include <string>
#include <vector>

using namespace std;

string GetMapLine(const int n, int mapLine1, int mapLine2) {
	string result(n, ' ');
	// 비트 OR 연산을 통해 비트를 합친다.
	int finallyMapLine = mapLine1 | mapLine2;

	for (int i = 1; i <= n; ++i)
	{
		// 제일 오른쪽 비트가 1인 경우 
		if (finallyMapLine & 1)
		{
			result[n - i] = '#';
		}
		else
		{
			result[n - i] = ' ';
		}
		// 비트를 오른쪽으로 한칸 민다.
		finallyMapLine = finallyMapLine >> 1;
	}

	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> result_map;

	for (int line = 0; line < arr1.size(); ++line)
	{
		result_map.emplace_back(GetMapLine(n, arr1[line], arr2[line]));
	}

	return result_map;
}