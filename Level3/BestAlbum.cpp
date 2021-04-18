//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//class Music {
//public:
//	Music() = default;
//	Music(int play_Count, int unique_Number)
//		: play_Count(play_Count), unique_Number(unique_Number) {}
//
//	static bool Compare(Music& a, Music& b) {
//		if (a.play_Count != b.play_Count) return a.play_Count > b.play_Count;
//		else return a.unique_Number < b.unique_Number;
//	}
//public:
//	int play_Count;
//	int unique_Number;
//};
//
//class Album {
//public:
//	Album() = default;
//	Album(const vector<string>& genres, const vector<int> play_Counts) {
//		for (int i = 0; i < genres.size(); ++i) {
//			musicsAtGenres[genres[i]].emplace_back(play_Counts[i], i);
//			if (totalPlayCount.find(genres[i]) == totalPlayCount.end()) totalPlayCount[genres[i]] = 0;
//
//			totalPlayCount[genres[i]] += play_Counts[i];
//		}
//	}
//
//	void AlbumSort() {
//		for (pair<const string, vector<Music>>& musics : musicsAtGenres) {
//			sort(musics.second.begin(), musics.second.end(), Music::Compare);
//		}
//	}
//
//	vector<string> SortGenresByTotalPlay() {
//		vector<string> result(totalPlayCount.size());
//		vector<pair<string, int>> genresNPlayCounts;
//
//		for (pair<const string, int>& music : totalPlayCount)
//			genresNPlayCounts.emplace_back(music.first, music.second);
//
//		sort(genresNPlayCounts.begin(), genresNPlayCounts.end(), [](pair<string, int>& a, pair<string, int>& b) { return a.second > b.second; });
//		transform(genresNPlayCounts.begin(), genresNPlayCounts.end(), result.begin(), [](pair<string, int>& a) { return a.first; });
//
//		return result;
//	}
//
//	vector<int> GetAlbumTracks() {
//		vector<int> result;
//		vector<string> sortedGenres = SortGenresByTotalPlay();
//
//		for (const string& genre : sortedGenres) {
//			int size = (musicsAtGenres[genre].size() > 1) ? 2 : 1;
//			for (int i = 0; i < size; ++i)
//				result.push_back(musicsAtGenres[genre][i].unique_Number);
//		}
//
//		return result;
//	}
//
//public:
//	map<string, vector<Music>> musicsAtGenres;
//	map<string, int> totalPlayCount;
//};
//
//vector<int> solution(vector<string> genres, vector<int> plays) {
//	vector<int> answer;
//
//	Album album(genres, plays);
//	album.AlbumSort();
//	answer = album.GetAlbumTracks();
//
//	return answer;
//}



#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

constexpr int MAXIMUM_RECORD_COUNT = 2;

class Music
{
public:
    Music(int number, int count) : 
        unique_Number(number), play_Count(count) { }

    bool operator<(const Music& otherMusic) const
    {
        if (play_Count != otherMusic.play_Count)
        {
            return play_Count > otherMusic.play_Count;
        }

        return unique_Number < otherMusic.unique_Number;
    }

public:
    int unique_Number = 0;
    int play_Count = 0;
};

using MusicChart = map<string, pair<int, set<Music>>>;

vector<int> solution(vector<string> genres, vector<int> plays) {
    MusicChart musicChart;
    vector<pair<string, pair<int, set<Music>>>> musics;
    vector<int> answer;

    for (int i = 0; i < genres.size(); ++i)
    {
        musicChart[genres[i]].first += plays[i];
        musicChart[genres[i]].second.insert(Music(i, plays[i]));

        // 2개가 넘어간 경우 - 3번째 내용물을 지운다 최대 2번 연산 보장
        if (musicChart[genres[i]].second.size() > MAXIMUM_RECORD_COUNT)
        {
            auto iter = musicChart[genres[i]].second.end();
            advance(iter, -1);
            musicChart[genres[i]].second.erase(iter);
        }
    }

    copy(musicChart.begin(), musicChart.end(), back_inserter(musics));
    sort(musics.begin(), musics.end(), [](pair<string, pair<int, set<Music>>>& a, pair<string, pair<int, set<Music>>>& b) {
        return a.second.first > b.second.first;
    });

    for (auto music : musics)
    {
        for (Music musicData : music.second.second) {
            answer.push_back(musicData.unique_Number);
        }
    }

    return answer;
}


/*
장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시,
노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

1.속한 노래가 많이 재생된 장르를 먼저 수록합니다.
2.장르 내에서 많이 재생된 노래를 먼저 수록합니다.
3.장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 
베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

제한사항
 genres[i]는 고유번호가 i인 노래의 장르입니다.
plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
장르 종류는 100개 미만입니다.
장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
모든 장르는 재생된 횟수가 다릅니다.

*/

#include "../../Util.h"

int main()
{
    vector<string> genres{ "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays{ 500, 600, 150, 800, 2500 };

    cout << solution(genres, plays);
}