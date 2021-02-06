#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Music {
public:
	Music() = default;
	Music(int play_Count, int unique_Number)
		: play_Count(play_Count), unique_Number(unique_Number) {}

	static bool Compare(Music& a, Music& b) {
		if (a.play_Count != b.play_Count) return a.play_Count > b.play_Count;
		else return a.unique_Number < b.unique_Number;
	}
public:
	int play_Count;
	int unique_Number;
};

class Album {
public:
	Album() = default;
	Album(const vector<string>& genres, const vector<int> play_Counts) {
		for (int i = 0; i < genres.size(); ++i) {
			musicsAtGenres[genres[i]].emplace_back(play_Counts[i], i);
			if (totalPlayCount.find(genres[i]) == totalPlayCount.end()) totalPlayCount[genres[i]] = 0;

			totalPlayCount[genres[i]] += play_Counts[i];
		}
	}

	void AlbumSort() {
		for (pair<const string, vector<Music>>& musics : musicsAtGenres) {
			sort(musics.second.begin(), musics.second.end(), Music::Compare);
		}
	}

	vector<string> SortGenresByTotalPlay() {
		vector<string> result(totalPlayCount.size());
		vector<pair<string, int>> genresNPlayCounts;

		for (pair<const string, int>& music : totalPlayCount)
			genresNPlayCounts.emplace_back(music.first, music.second);

		sort(genresNPlayCounts.begin(), genresNPlayCounts.end(), [](pair<string, int>& a, pair<string, int>& b) { return a.second > b.second; });
		transform(genresNPlayCounts.begin(), genresNPlayCounts.end(), result.begin(), [](pair<string, int>& a) { return a.first; });

		return result;
	}

	vector<int> GetAlbumTracks() {
		vector<int> result;
		vector<string> sortedGenres = SortGenresByTotalPlay();

		for (const string& genre : sortedGenres) {
			int size = (musicsAtGenres[genre].size() > 1) ? 2 : 1;
			for (int i = 0; i < size; ++i)
				result.push_back(musicsAtGenres[genre][i].unique_Number);
		}

		return result;
	}

public:
	map<string, vector<Music>> musicsAtGenres;
	map<string, int> totalPlayCount;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	Album album(genres, plays);
	album.AlbumSort();
	answer = album.GetAlbumTracks();

	return answer;
}