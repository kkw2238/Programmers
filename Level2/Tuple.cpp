/*
	https://programmers.co.kr/learn/courses/30/lessons/64065
*/

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> DistributeSubset(string& s)
{
	vector<vector<int>> subsets;
	vector<int> subset;
	int num;

	s = s.substr(1, s.length() - 1);

	istringstream is(s);

	while (!is.fail())
	{
		switch (is.get())
		{
		case '{':
		case ',':
			break;

		case '}':
			subsets.emplace_back(subset);
			is.get();
			subset.clear();
			break;

		default:
			is.unget();
			is >> num;
			subset.push_back(num);
		}
	}

	return subsets;
}

vector<int> solution(string s) {
	vector<int> result;
	vector<vector<int>> subsets = DistributeSubset(s);
	map<int, bool> alreadyInserted;

	sort(subsets.begin(), subsets.end(), [](const vector<int>& a, const vector<int>& b) {
		return a.size() < b.size();
	});

	for (const vector<int>& vi : subsets)
	{
		for (const int num : vi)
		{
			if (!alreadyInserted[num])
			{
				result.emplace_back(num);
				alreadyInserted[num] = true;
			}
		}
	}

	return result;
}

/* 예전 코드
#include <string>
#include <vector>
#include <unordered_set>

#include <algorithm>

using namespace std;

vector<int> GetSet(string s) {
	vector<int> result;
	auto iter = s.begin() + 1;
	auto finditer = iter;

	while (finditer != s.end()) {
		finditer = find(iter, s.end(), ',');
		result.push_back(stoi(string(iter, finditer)));

		if (finditer != s.end()) {
			iter = finditer + 1;
		}
	}

	return result;
}

vector<vector<int>> DistributeString(string s) {
	vector<vector<int>> distributedString;
	s.erase(s.begin());

	while (!s.empty()) {
		auto iter = find(s.begin(), s.end(), '}') + 1;
		distributedString.push_back(GetSet(string(s.begin(), iter)));

		if (iter != s.end()) {
			s.erase(s.begin(), iter + 1);
		}
		else
			s.clear();
	}

	return distributedString;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> result = DistributeString(s);

	sort(result.begin(), result.end(), [](vector<int>& a, vector<int>& b) {
		return a.size() < b.size();
	});

	for (vector<int> v : result) {
		for (int o : v) {
			auto iter = find(answer.begin(), answer.end(), o);
			if (iter == answer.end())
				answer.push_back(o);
		}
	}

	return answer;
}
*/