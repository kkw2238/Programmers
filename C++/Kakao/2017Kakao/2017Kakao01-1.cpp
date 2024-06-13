/*
	{(2017��)KAKAO BLIND RECRUITMENT] {1��] �߼� Ʈ����
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
		// �α� �����͸� ���� hh:mm:ss.sss ���¸� ms���·� ����
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

		// �ش� �ð��� ���� �ð����� ���� 1�� �̳��� �ִ��� �Ǵ�
		if (deltaTime < MS && deltaTime >= 0) return true;

		// �ش� �ð��� �α� ���� �ð����� ���� 1�� �̳��� �ִ��� �Ǵ�
		else if (deltaTime + mProcessingTime < MS && deltaTime + mProcessingTime >= 0) return true;

		// �ش� �ð��� ���� ���ο� �ִ��� �Ǵ� ex) 00:01:00.000 0.001s, 00:01:01.499 3.0s�� ���� ������ �Ǵ� �Ұ����� ��� �Ǵ�.
		else if (GetStartTime() <= startTime && GetEndTime() >= startTime) return true;

		return false;
	}

	int CountLogInTime(vector<Log>& logs) {
		int result = 0;
		int logInTimeCount{2] = { 0, 0 };

		for (int i = 0; i < logs.size(); ++i) {
			if (GetStartTime() - logs{i].GetEndTime() > MS) continue;
			if (logs{i].GetStartTime() - GetEndTime() > MS) break;

			// �� �α��� ���۰� ���� ���ؼ��� �Ǵ�
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