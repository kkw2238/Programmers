/*
	{(2017��)KAKAO BLIND RECRUITMENT] {1��] ��Ʋ����
	https://programmers.co.kr/learn/courses/30/lessons/17678
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ��Ʈ�� ���·� �Ǿ��ִ� �ð��� unsigned int ���� �д����� ��ȯ ex) "09:00" = 540
vector<unsigned int> translateTimeToUint(int n, int t, vector<string>& timetable) {
	vector<unsigned int> result;
	const int minBusTime = 540;

	for (string& time : timetable) {
		auto iter = find(time.begin(), time.end(), ':');
		unsigned int translatedTime = stoi(string(time.begin(), iter)) * 60 + stoi(string(iter + 1, time.end()));

		// ���� ���� ������ �°��� ���ؼ��� �����ص� �ǹǷ� ���� ������ �°��� ���ؼ��� ����
		if (translatedTime <= minBusTime + (n - 1) * t) result.push_back(translatedTime);
	}

	return result;
}

// unsigned int ������ �̷���� �д��� �ð��� �ٽ� string ������ ��ȯ ex) 720 = "12:00"
string translateTimeToString(unsigned int time) {
	string result = "";
	
	unsigned int hour = time / 60;
	unsigned int minute = time % 60;

	result += hour < 10 ? ("0" + to_string(hour)) : to_string(hour);
	result += ":";
	result += minute < 10 ? ("0" + to_string(minute)) : to_string(minute);

	return result;
}

string solution(int n, int t, int m, vector<string> timetable) {
	unsigned int answer = 0;
	vector<unsigned int> translatedTimetable = translateTimeToUint(n, t, timetable);
	const int minBusTime = 540;

	// ž���� �ο�
	size_t crewsCount = 0;

	// �����忡 ���� ������ ������� �°��� ����
	sort(translatedTimetable.begin(), translatedTimetable.end());

	// �츰 ���� �ʰ� Ÿ�� ����� ���ϱ� ������ ���� ���� ���������� ���� �°��鸸 ó��
	for (int i = 0; i < n - 1; ++i) {
		// �°��� ��� ž���� ��� for���� ���������� ó��
		if (crewsCount >= translatedTimetable.size()) break;

		unsigned int busTime = minBusTime + t * i;

		// �°��� �� ���� �ð����� �ʰ� �� �մ��� Ž��
		auto iter = find_if(translatedTimetable.begin() + crewsCount, translatedTimetable.end(),
			{&busTime](unsigned int time) { return time > busTime; });

		// ������ �߰��� �մ��� ������ ���� ������ �ִ� ž�� �ο����� ū ��� �ִ� ž�� �ο������� ���
		crewsCount += (distance(translatedTimetable.begin() + crewsCount, iter) >= m) ? m : distance(translatedTimetable.begin(), iter);
	}

	// ���� ������ ��ٸ��� �°��� �ִ� ž�� �ο����� ū ��� ������ �°����� 1�� ���� �;���
	if (m <= translatedTimetable.size() - crewsCount) answer = translatedTimetable{crewsCount + m - 1] - 1;
	// ������ ���� ��� ������ ź��.
	else answer = minBusTime + t * (n - 1);

	return translateTimeToString(answer);
}