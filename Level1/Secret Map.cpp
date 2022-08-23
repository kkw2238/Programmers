/*
	https://programmers.co.kr/learn/courses/30/lessons/17681
*/

#include <string>
#include <vector>

using namespace std;

string GetMapLine(const int n, int mapLine1, int mapLine2) {
	string result(n, ' ');
	// ��Ʈ OR ������ ���� ��Ʈ�� ��ģ��.
	int finallyMapLine = mapLine1 | mapLine2;

	for (int i = 1; i <= n; ++i)
	{
		// ���� ������ ��Ʈ�� 1�� ��� 
		if (finallyMapLine & 1)
		{
			result[n - i] = '#';
		}
		else
		{
			result[n - i] = ' ';
		}
		// ��Ʈ�� ���������� ��ĭ �δ�.
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