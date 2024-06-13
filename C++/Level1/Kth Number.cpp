/*
	https://programmers.co.kr/learn/courses/30/lessons/42748
*/
#include <vector>
#include <algorithm>

using namespace std;

enum { START_INDEX, END_INDEX, K_INDEX };

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (const vector<int>& command : commands)
	{
		const vector<int> COMMAND{ command[START_INDEX] - 1, command[END_INDEX], command[K_INDEX] - 1 };
		vector<int> cuttedArray(array.begin() + COMMAND[START_INDEX], array.begin() + COMMAND[END_INDEX]);

		sort(cuttedArray.begin(), cuttedArray.end());

		answer.emplace_back(cuttedArray[COMMAND[K_INDEX]]);
	}

	return answer;
}
