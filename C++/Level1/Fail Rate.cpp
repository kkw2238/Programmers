/*
	https://programmers.co.kr/learn/courses/30/lessons/42889
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	int totalUser = stages.size();
	vector<pair<int, double>> failRatePerStage(N);
	vector<int> result;

	for (int stage = 1; stage <= N; ++stage)
	{
		// 각 스테이지에 머물러 있는 유저의 수를 구한다.
		int stageUserCount = count(stages.begin() + stages.size() - totalUser, stages.end(), stage);

		// 현재 스테이지를 지나간 유저가 0명일 때 ( x / 0 = INF 대비 )
		if (totalUser > 0) 
		{
			// 실패율 = 현재 유저 / 현재 스테지를 지나간 총 유저의 수
			failRatePerStage[stage - 1] = pair(stage, static_cast<double>(stageUserCount) / totalUser);
		}
		// 유저가 0명일 경우 실패율 0.0 삽입
		else
		{
			failRatePerStage[stage - 1] = pair(stage, 0.0);
		}

		// 총 유저를 현재 스테이지에 머물러 있는 유저 만큼 감소시켜준다. 
		totalUser -= stageUserCount;
	}

	// 아래와 같은 조건으로 정렬 
	sort(failRatePerStage.begin(), failRatePerStage.end(), [](pair<int, double>& a, pair<int, double>& b) 
	{
		// 실패율이 같은 경우 스테이지 인덱스를 오름차순으로 정렬
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		// 그 외의 경우 실패율에 따라 내림차순으로 정렬
		return a.second > b.second;
	});

	for (int stage = 0; stage < N; ++stage)
	{
		result.push_back(failRatePerStage[stage].first);
	}

	return result;
}