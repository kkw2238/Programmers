/*
	https://programmers.co.kr/learn/courses/30/lessons/12939
*/
#include <string>
#include <set>
#include <algorithm>

using namespace std;

set<int> DistributeString(string s) {
	set<int> result;
	auto spaceIter = s.begin();
	auto startIter = spaceIter;

	while (true) {
		spaceIter = find(startIter, s.end(), ' ');
		result.insert(stoi(string(startIter, spaceIter)));
		if (spaceIter == s.end()) break;
		startIter = spaceIter + 1;
	}
	return result;
}

string solution(string s) {
	string answer = "";
	set<int> distributedString = DistributeString(s);
	answer += to_string(*distributedString.begin()) + ' ' + to_string(*distributedString.rbegin());

	return answer;
}
