#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> movie)
{
	vector<string> result;
	map<string, int> bookCount;
	vector<pair<string, int>> sortedBookCount;

	for (const string& s : movie)
	{
		bookCount[s]++;
	}

	for (auto& data : bookCount)
	{
		sortedBookCount.push_back(data);
	}

	sort(sortedBookCount.begin(), sortedBookCount.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		return a.second > b.second;
	});

	for (auto sortedData : sortedBookCount)
	{
		result.emplace_back(sortedData.first);
	}

	return result;
}
