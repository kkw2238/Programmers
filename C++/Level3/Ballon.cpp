/*
	https://programmers.co.kr/learn/courses/30/lessons/68646
*/

#include <vector>

using namespace std;

const int MAXIMUM = 1000000001;

int GetBallonCount(const int ballonNum, int& smallestNum)
{
	if (ballonNum < smallestNum)
	{
		smallestNum = ballonNum;
		return 0;
	}

	return 1;
}

const bool IsLive(const pair<int, int>& side_count)
{
	if (side_count.first == -1 || side_count.second == -1)
	{
		return false;
	}

	return side_count.first == 0 || side_count.second == 0;
}

int solution(vector<int> a) {
	int answer = 0;
	int left_Smallest_Ballon = MAXIMUM;
	int right_Smallest_Ballon = MAXIMUM;

	vector<pair<int, int>> side_SmallCount(a.size(), pair(-1, -1));

	for (int i = 0; i < a.size(); ++i)
	{
		int leftIndex = i;
		int rightIndex = a.size() - 1 - i;

		side_SmallCount[leftIndex].first = GetBallonCount(a[leftIndex], left_Smallest_Ballon);
		side_SmallCount[rightIndex].second = GetBallonCount(a[rightIndex], right_Smallest_Ballon);
		
		if (IsLive(side_SmallCount[leftIndex]))
		{
			++answer;
		}
		if ((leftIndex != rightIndex) && IsLive(side_SmallCount[rightIndex]))
		{
			++answer;
		}
	}
	
	return answer;
}