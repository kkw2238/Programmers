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

// X#���� Ư�� ���ڿ��� ��ȯ ( C#�� ���� ���̽��� ó���ϱ� �����ϱ� ����� ���� )
string ConvertMellody(string s)
{
	int index = s.find('#');

	// '#'�� ã�� ���� �� ���� �ݺ�
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
	// XX�� YY�� ������ N�ʷ� ȯ��
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

	// mellody�� playŸ�� ��ŭ �÷��ش�
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

		// mellody�� ����ִ� ���
		if (mellodies.mellody.find(m) != string::npos)
		{
			// music�� ����
			musics.emplace_back(mellodies);
		}
	}
	
	// ��ġ�ϴ� �뷡�� ���� ��� None�� ��ȯ
	if (musics.empty())
	{
		return "(None)";
	}

	// ������ �����ؾ� �ϱ⿡ stable_sort���
	stable_sort(musics.begin(), musics.end());

	// ���� ����� �׻� 0�� �ε����� �����Ѵ�.
	return musics[0].name;
}

/* ���� �ڵ�
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