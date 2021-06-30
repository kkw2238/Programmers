/*
	https://programmers.co.kr/learn/courses/30/lessons/42586
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int delayBeforeProgressTime = 0;
	int delayProgressCount = 0;

	for (int i = 0; i < progresses.size(); ++i)
	{
		int remainTime = (100 - progresses[i]);
		int finishTime = (remainTime / speeds[i]) + (int)(remainTime % speeds[i] != 0);

		if (finishTime > delayBeforeProgressTime)
		{
			if (delayProgressCount > 0)
			{
				answer.push_back(delayProgressCount);
			}

			delayBeforeProgressTime = finishTime;
			delayProgressCount = 1;
		}
		else
		{
			++delayProgressCount;
		}
	}

	answer.push_back(delayProgressCount);

	return answer;
}

/* 예전 코드
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> finishTimes(progresses.size());
	int time = 1;

	for (size_t i = 0; i < progresses.size(); ++i) {
		int left = 100 - progresses[i];
		finishTimes[i] = left % speeds[i] == 0 ? left / speeds[i] : left / speeds[i] + 1;
	}

	for (size_t j = 1; j < progresses.size(); ++j) {
		if (finishTimes[j - 1] >= finishTimes[j]) {
			++time;
			finishTimes[j] = finishTimes[j - 1];
		}
		else {
			answer.push_back(time);
			time = 1;
		}
	}
	answer.push_back(time);

	return answer;
}
*/