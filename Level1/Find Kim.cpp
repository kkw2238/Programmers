#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
	const string NAME = "Kim";
	int kimsIndex = distance(seoul.begin(), find(seoul.begin(), seoul.end(), NAME));

	return  "�輭���� " + to_string(kimsIndex) + "�� �ִ�";
}