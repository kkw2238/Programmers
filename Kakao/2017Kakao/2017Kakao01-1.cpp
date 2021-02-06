/*
	{(2017년)KAKAO BLIND RECRUITMENT] {1차] 추석 트래픽
	https://programmers.co.kr/learn/courses/30/lessons/17676
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MS = 1000;

class Log {
public:
	Log(string& data) {
		// 로그 데이터를 분해 hh:mm:ss.sss 형태를 ms형태로 변경
		auto iter = find(data.begin(), data.end(), ' ');
		auto next = find(iter + 1, data.end(), ':');

		mEndTime += stoi(string(iter + 1, next)) * 3600 * MS;
		iter = next;

		next = find(iter + 1, data.end(), ':');
		mEndTime += stoi(string(iter + 1, next)) * 60 * MS;
		iter = next;

		next = find(iter + 1, data.end(), ' ');
		mEndTime += static_cast<int>(stod(string(iter + 1, next)) * MS);
		iter = next;

		mProcessingTime = static_cast<int>(stod(string(iter + 1, data.end() - 1)) * MS) - 1;
	}

	int GetStartTime() const {
		return mEndTime - mProcessingTime;
	}

	int GetEndTime() const {
		return mEndTime;
	}

	bool LogInTime(const int startTime) const {
		const int deltaTime = GetStartTime() - startTime;

		// 해당 시간이 시작 시간으로 부터 1초 이내에 있는지 판단
		if (deltaTime < MS && deltaTime >= 0) return true;

		// 해당 시간이 로그 종료 시간으로 부터 1초 이내에 있는지 판단
		else if (deltaTime + mProcessingTime < MS && deltaTime + mProcessingTime >= 0) return true;

		// 해당 시간이 영역 내부에 있는지 판단 ex) 00:01:00.000 0.001s, 00:01:01.499 3.0s와 같이 위에서 판단 불가능한 경우 판단.
		else if (GetStartTime() <= startTime && GetEndTime() >= startTime) return true;

		return false;
	}

	int CountLogInTime(vector<Log>& logs) {
		int result = 0;
		int logInTimeCount{2] = { 0, 0 };

		for (int i = 0; i < logs.size(); ++i) {
			if (GetStartTime() - logs{i].GetEndTime() > MS) continue;
			if (logs{i].GetStartTime() - GetEndTime() > MS) break;

			// 각 로그의 시작과 끝에 대해서만 판단
			logInTimeCount{0] += logs{i].LogInTime(this->GetStartTime());
			logInTimeCount{1] += logs{i].LogInTime(this->GetEndTime());
		}

		return max(logInTimeCount{0], logInTimeCount{1]);
	}

public:
	int mEndTime = 0, mProcessingTime = 0;
};

int solution(vector<string> lines) {
	int answer = 0;
	int tmp = 0;

	vector<Log> logs(lines.begin(), lines.end());

	for (int i = 0; i < logs.size(); ++i) {
		tmp = logs{i].CountLogInTime(logs);
		answer = max(answer, tmp);
	}

	return answer;
}