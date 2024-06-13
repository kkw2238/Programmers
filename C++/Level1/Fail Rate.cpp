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
		// �� ���������� �ӹ��� �ִ� ������ ���� ���Ѵ�.
		int stageUserCount = count(stages.begin() + stages.size() - totalUser, stages.end(), stage);

		// ���� ���������� ������ ������ 0���� �� ( x / 0 = INF ��� )
		if (totalUser > 0) 
		{
			// ������ = ���� ���� / ���� �������� ������ �� ������ ��
			failRatePerStage[stage - 1] = pair(stage, static_cast<double>(stageUserCount) / totalUser);
		}
		// ������ 0���� ��� ������ 0.0 ����
		else
		{
			failRatePerStage[stage - 1] = pair(stage, 0.0);
		}

		// �� ������ ���� ���������� �ӹ��� �ִ� ���� ��ŭ ���ҽ����ش�. 
		totalUser -= stageUserCount;
	}

	// �Ʒ��� ���� �������� ���� 
	sort(failRatePerStage.begin(), failRatePerStage.end(), [](pair<int, double>& a, pair<int, double>& b) 
	{
		// �������� ���� ��� �������� �ε����� ������������ ����
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		// �� ���� ��� �������� ���� ������������ ����
		return a.second > b.second;
	});

	for (int stage = 0; stage < N; ++stage)
	{
		result.push_back(failRatePerStage[stage].first);
	}

	return result;
}