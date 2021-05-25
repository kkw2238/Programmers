/*
	https://programmers.co.kr/learn/courses/30/lessons/17683
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
enum { START_TIME_H = 0, START_TIME_M = 3, END_TIME_H = 6, END_TIME_M = 9, NAME_START = 12 };

map<string, string> convert_mellody{ pair("C#", "H"), pair("D#", "I"), pair("F#", "J"), pair("G#", "K"), pair("A#", "L"), pair("E#", "M") };

struct MusicInfo
{
	int playTime;
	string name;
	string mellody;

	const bool operator<(const MusicInfo& other) const
	{
		return playTime > other.playTime;
	}
};

// X#들을 특정 문자열로 변환 ( C#과 같은 케이스를 처리하기 용이하기 만들기 위함 )
string ConvertMellody(string s)
{
	int index = s.find('#');

	// '#'을 찾지 못할 때 까지 반복
	while (index != string::npos)
	{
		string mellody = convert_mellody[s.substr(index - 1, 2)];
		s.replace(index - 1, 2, mellody);
		index = s.find('#', index);
	}

	return s;
}

int GetPlayTime(const string& musicInfo)
{
	// XX분 YY초 구조를 N초로 환산
	int startTime = stoi(musicInfo.substr(START_TIME_H, 2)) * 60 + stoi(musicInfo.substr(START_TIME_M, 2));
	int	endTime = stoi(musicInfo.substr(END_TIME_H, 2)) * 60 + stoi(musicInfo.substr(END_TIME_M, 2));

	return endTime - startTime;
}

MusicInfo ConvertMusicInfoToMellodies(const string musicinfo)
{
	int playTime = GetPlayTime(musicinfo);
	int findMellodyStart = musicinfo.find(',', NAME_START) + 1;
	string name = musicinfo.substr(NAME_START, findMellodyStart - NAME_START - 1);
	string mellody = ConvertMellody(musicinfo.substr(findMellodyStart));

	// mellody를 play타임 만큼 늘려준다
	for (int length = mellody.length(); length < playTime; length *= 2)
	{
		mellody.append(mellody);
	}

	return MusicInfo{ playTime, name, mellody.substr(0, playTime) };
}

string solution(string m, vector<string> musicinfos) {
	vector<MusicInfo> musics;

	m = ConvertMellody(m);

	for (const string& musicinfo : musicinfos)
	{
		MusicInfo mellodies = ConvertMusicInfoToMellodies(musicinfo);

		// mellody가 들어있는 경우
		if (mellodies.mellody.find(m) != string::npos)
		{
			// music에 저장
			musics.emplace_back(mellodies);
		}
	}
	
	// 일치하는 노래가 없을 경우 None을 반환
	if (musics.empty())
	{
		return "(None)";
	}

	// 순서를 유지해야 하기에 stable_sort사용
	stable_sort(musics.begin(), musics.end());

	// 최종 결과는 항상 0번 인덱스에 존재한다.
	return musics[0].name;
}

/* 예전 코드
* 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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
		ConvertTimeStringToInt(partedMusicinfo[StartTime], startH, startM);
		ConvertTimeStringToInt(partedMusicinfo[EndTime], endH, endM);

		mPlayTime = (endH - startH) * 60 + (endM - startM);
		mMusicName = partedMusicinfo[Title];

		MakeSheet(partedMusicinfo[MusicCode]);
	}

	void ConvertTimeStringToInt(const string time, int& hour, int& minute) {
		auto iter = find(time.begin(), time.end(), ':');
		hour = stoi(string(time.begin(), iter));
		minute = stoi(string(iter + 1, time.end()));
	}

	void MakeSheet(string& musicCode) {
		TranslateSheet(musicCode);

		for (size_t i = 0; i < mPlayTime / musicCode.length(); ++i) mMusicSheet += musicCode;
		mMusicSheet += string(musicCode.begin(), musicCode.begin() + (mPlayTime % musicCode.length()));
	}

	vector<string> partitionInfo(const string& musicInfo) {
		vector<string> result(MAX_INFO_COUNT);
		auto iter = musicInfo.begin();

		for (int i = 0; i < MAX_INFO_COUNT; ++i) {
			auto next = find(iter, musicInfo.end(), ',');
			result[i] = string(iter, next);
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
		musics.emplace_back(musicinfos[i]);

	string answer = "";
	int time = -1;

	TranslateSheet(m);

	for (size_t i = 0; i < musics.size(); ++i) {
		if (!musics[i].melodyInSheet(m)) continue;

		if (time < musics[i].mPlayTime) {
			answer = musics[i].mMusicName;
			time = musics[i].mPlayTime;
		}
	}

	if (answer == "") answer = "(None)";

	return answer;
}
*/