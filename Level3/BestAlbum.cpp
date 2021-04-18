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

        // 2���� �Ѿ ��� - 3��° ���빰�� ����� �ִ� 2�� ���� ����
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
�帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ���,
�뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.

1.���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
2.�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
3.�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.

�뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, 
����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���
 genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
genres�� plays�� ���̴� ������, �̴� 1 �̻� 10,000 �����Դϴ�.
�帣 ������ 100�� �̸��Դϴ�.
�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
��� �帣�� ����� Ƚ���� �ٸ��ϴ�.

*/

#include "../../Util.h"

int main()
{
    vector<string> genres{ "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays{ 500, 600, 150, 800, 2500 };

    cout << solution(genres, plays);
}