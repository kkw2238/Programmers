/*
	https://programmers.co.kr/learn/courses/30/lessons/12939
*/
#include <string>
#include <sstream>

using namespace std;

const int INTEGER_MAX = 2147483647;

string solution(string s) {
	stringstream ss(s);
	int min_Num = INTEGER_MAX;
	int max_Num = -INTEGER_MAX;

	while (!ss.eof())
	{
		int num = 0;

		ss >> num;

		if (num < min_Num)
		{
			min_Num = num;
		}
		if (num > max_Num)
		{
			max_Num = num;
		}
	}

	return to_string(min_Num) + " " + to_string(max_Num);
}

/* 예전 코드
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
*/