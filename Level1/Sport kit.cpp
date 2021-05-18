/*
	https://programmers.co.kr/learn/courses/30/lessons/42862
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> clothes(n, 1);

	sort(reserve.begin(), reserve.end());

	for (int lostStudent : lost)
	{
		--clothes[lostStudent - 1];
	}

	for (int reserveStudent : reserve)
	{
		++clothes[reserveStudent - 1];
		if (clothes[reserveStudent - 1] == 1)
		{
			continue;
		}

		if (reserveStudent > 1 && clothes[reserveStudent - 2] == 0)
		{
			++clothes[reserveStudent - 2];
		}
		else if (reserveStudent < n - 1 && clothes[reserveStudent] == 0)
		{
			++clothes[reserveStudent];
		}
	}

	return count_if(clothes.begin(), clothes.end(), [](int a) {return a > 0; });
}