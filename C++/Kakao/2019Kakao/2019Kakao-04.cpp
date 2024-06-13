#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Node {
public:
	Node() = default;

	void Insert(const string& str, int index) {
		c = str[index];

		if (str.length() <= index + 1) return;

		nextNode[str[index + 1]].Insert(str, index + 1);
		++count;
	}

	int Find(const string& str, int index) {
		if (str.length() <= index + 1) return count;
		return nextNode[str[index + 1]].Find(str, index + 1);
	}
public:
	char c = ' '; 
	map<char, Node> nextNode;
	int count = 0;
};

class Trie {
public:
	Trie() = default;
	Trie(const vector<string>& strings) {
		for (const string& str : strings) {
			node[str[0]].Insert(str, 0);
		}
	}

	void Insert(const string& str) {
		node[str[0]].Insert(str, 0);
		++totalNodeCount;
	}

	int Find(const string& str) {
		if (str.empty()) return totalNodeCount;
		return node[str[0]].Find(str, 0);
	}
public:
	map<char, Node> node;
	int totalNodeCount = 0;
};

string FindJokerPosition(string& query) {
	string eraseJoker;

	if (query.at(0) == '?' && query.at(query.length() - 1) == '?') return "";
	else if (query.at(0) == '?') reverse(query.begin(), query.end());

	eraseJoker = query.substr(0, query.find_first_of('?'));
	return eraseJoker;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	map<int, Trie> musicDic, musicReverseDic;

	for (string& str : words) {
		musicDic[str.length()].Insert(str);
		reverse(str.begin(), str.end());
		musicReverseDic[str.length()].Insert(str);
	}

	for (string& query : queries) {
		if (musicDic.find(query.length()) == musicDic.end()) answer.push_back(0);
		else if (query[0] == '?') answer.push_back(musicReverseDic[query.length()].Find(FindJokerPosition(query)));
		else answer.push_back(musicDic[query.length()].Find(FindJokerPosition(query)));
	}

	return answer;
}