/*
	{(2017��)KAKAO BLIND RECRUITMENT] {3��] ��ݱװ�
	https://programmers.co.kr/learn/courses/30/lessons/17683
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// #(�ø�ǥ)�� ���� ġȯ�ϴ� �Լ� ex) C# -> c
void TranslateSheet(string& sheet) {
	auto iter = sheet.begin();

	while (true) {
		iter = find(iter, sheet.end(), '#');
		if (iter != sheet.end()) {
			*(iter - 1) = tolower(*(iter - 1));
			sheet.erase(iter);
		}
		else return;
	}
}

class music {
public:
	const int MAX_INFO_COUNT = 4;

	enum { StartTime, EndTime, Title, MusicCode };
	music(string& musicinfo) {
		int startM, startH;
		int endM, endH;

		vector<string> partedMusicinfo = partitionInfo(musicinfo);
		ConvertTimeStringToInt(partedMusicinfo{StartTime], startH, startM);
		ConvertTimeStringToInt(partedMusicinfo{EndTime], endH, endM);

		mPlayTime = (endH - startH) * 60 + (endM - startM);
		mMusicName = partedMusicinfo{Title];

		MakeSheet(partedMusicinfo{MusicCode]);
	}

	// "HH:MM"������ String�� Int������ �ٲ�
	void ConvertTimeStringToInt(const string time, int& hour, int& minute) {
		auto iter = find(time.begin(), time.end(), ':');
		hour = stoi(string(time.begin(), iter));
		minute = stoi(string(iter + 1, time.end()));
	}

	// �ð���ŭ ��ǥ�� �̾� �����ų� �߶� �Ǻ� ����
	void MakeSheet(string& musicCode) {
		TranslateSheet(musicCode);

		for (size_t i = 0; i < mPlayTime / musicCode.length(); ++i) mMusicSheet += musicCode;
		mMusicSheet += string(musicCode.begin(), musicCode.begin() + (mPlayTime % musicCode.length()));
	}

	// ',(��ǥ)' �������� �����͸� ������
	vector<string> partitionInfo(const string& musicInfo) {
		vector<string> result(MAX_INFO_COUNT);
		auto iter = musicInfo.begin();

		for (int i = 0; i < MAX_INFO_COUNT; ++i) {
			auto next = find(iter, musicInfo.end(), ',');
			result{i] = string(iter, next);
			iter = next != musicInfo.end() ? next + 1 : musicInfo.end();
		}

		return result;
	}

	bool melodyInSheet(string& melody) {
		if (mMusicSheet.find(melody) != -1) return true;
		return false;
	}

public:
	int mPlayTime = 0;
	string mMusicName = "";
	string mMusicSheet = "";
};

string solution(string m, vector<string> musicinfos) {
	vector<music> musics;
	for (int i = 0; i < musicinfos.size(); ++i)
		musics.emplace_back(musicinfos{i]);

	string answer = "";
	int time = -1;

	TranslateSheet(m);

	for (size_t i = 0; i < musics.size(); ++i) {
		if (!musics{i].melodyInSheet(m)) continue;

		if (time < musics{i].mPlayTime) {
			answer = musics{i].mMusicName;
			time = musics{i].mPlayTime;
		}
	}

	if (answer == "") answer = "(None)";

	return answer;
}