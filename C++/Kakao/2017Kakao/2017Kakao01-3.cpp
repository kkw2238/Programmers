/*
	{(2017년)KAKAO BLIND RECRUITMENT] {1차] 셔틀버스
	https://programmers.co.kr/learn/courses/30/lessons/17678
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 스트링 형태로 되어있는 시간을 unsigned int 형의 분단위로 변환 ex) "09:00" = 540
vector<unsigned int> translateTimeToUint(int n, int t, vector<string>& timetable) {
	vector<unsigned int> result;
	const int minBusTime = 540;

	for (string& time : timetable) {
		auto iter = find(time.begin(), time.end(), ':');
		unsigned int translatedTime = stoi(string(time.begin(), iter)) * 60 + stoi(string(iter + 1, time.end()));

		// 버스 막차 이후의 승객에 대해서는 무시해도 되므로 막차 이전의 승객에 대해서만 저장
		if (translatedTime <= minBusTime + (n - 1) * t) result.push_back(translatedTime);
	}

	return result;
}

// unsigned int 형으로 이루어진 분단위 시간을 다시 string 형으로 변환 ex) 720 = "12:00"
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

	// 탑승한 인원
	size_t crewsCount = 0;

	// 정류장에 빨리 도착한 순서대로 승객을 정렬
	sort(translatedTimetable.begin(), translatedTimetable.end());

	// 우린 가장 늦게 타는 방법을 원하기 때문에 막차 직전 버스까지에 대한 승객들만 처리
	for (int i = 0; i < n - 1; ++i) {
		// 승객이 모두 탑승한 경우 for문을 빠져나가게 처리
		if (crewsCount >= translatedTimetable.size()) break;

		unsigned int busTime = minBusTime + t * i;

		// 승객들 중 버스 시간보다 늦게 온 손님을 탐색
		auto iter = find_if(translatedTimetable.begin() + crewsCount, translatedTimetable.end(),
			{&busTime](unsigned int time) { return time > busTime; });

		// 위에서 발견한 손님의 순서를 보고 순서가 최대 탑승 인원보다 큰 경우 최대 탑승 인원까지만 계산
		crewsCount += (distance(translatedTimetable.begin() + crewsCount, iter) >= m) ? m : distance(translatedTimetable.begin(), iter);
	}

	// 만약 막차를 기다리는 승객이 최대 탑승 인원보다 큰 경우 마지막 승객에서 1분 일찍 와야함
	if (m <= translatedTimetable.size() - crewsCount) answer = translatedTimetable{crewsCount + m - 1] - 1;
	// 여유가 있을 경우 막차를 탄다.
	else answer = minBusTime + t * (n - 1);

	return translateTimeToString(answer);
}