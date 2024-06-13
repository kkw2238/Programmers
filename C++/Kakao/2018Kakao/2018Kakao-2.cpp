/*
	{(2018년)KAKAO BLIND RECRUITMENT] 실패율
	https://programmers.co.kr/learn/courses/30/lessons/42889
*/
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

const bool IsSame(const double a, const double b) {
	double difference = a > b ? a - b : b - a;
	return difference <= numeric_limits<double>::epsilon();
}

const bool SortByCondition(const pair<int, double>& a, const pair<int, double>& b) {
	if (IsSame(a.second, b.second)) return a.first < b.first;
	return a.second > b.second;
}

double aDivisionByb(const int a, const int b) {
	if (b == 0) return 0.0;
	return static_cast<double>(a) / static_cast<double>(b);
}

vector<int> DistributestayStages(const int N, vector<int>& stages) {
	vector<int> stayStages(N, 0);
	for (int n : stages) ++stayStages{n - 1];
	return stayStages;
}

vector<pair<int, double>> StayDivisionClear(const vector<int>& stayPeople, const int totalPlayer) {
	vector<pair<int, double>> divisionedVal;
	int tryPeople = 0;
	for (int i = 0; i < stayPeople.size() - 1; ++i) {
		divisionedVal.emplace_back(i + 1, aDivisionByb(stayPeople{i], totalPlayer - tryPeople));
		tryPeople += stayPeople{i];
	}
	return divisionedVal;
}

vector<int> MoveOnlyKeyToVector(vector<pair<int, double>>& pairs) {
	vector<int> onlyKeyVector;
	for (const pair<int, double>& pair : pairs) onlyKeyVector.push_back(pair.first);

	return onlyKeyVector;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> stageStayPeople = DistributestayStages(N + 1, stages);
	vector<pair<int, double>> stageToCalculResult = StayDivisionClear(stageStayPeople, stages.size());

	sort(stageToCalculResult.begin(), stageToCalculResult.end(), SortByCondition);

	return MoveOnlyKeyToVector(stageToCalculResult);
}