/*
	https://programmers.co.kr/learn/courses/30/lessons/12981
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	set<string> chain;

	int count = 1;

	string* beforeWord = nullptr;

	for (string& s : words) {
		if (beforeWord != nullptr) {
			if (*(*beforeWord).rbegin() != s[0] || chain.find(s) != chain.end())
				break;
		}
		chain.insert(s);
		beforeWord = &s;
		++count;
	}

	if (count > words.size())
		return vector<int>(2, 0);

	answer = { count % n == 0 ? n : count % n, (count - 1 + n) / n };
	return answer;
}
