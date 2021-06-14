/*
	https://programmers.co.kr/learn/courses/30/lessons/42578
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

const int CLOTHE_NAME = 0;
const int CATEGORY = 1;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, vector<string>> clothesCategory;

	for (const vector<string>& cloth : clothes)
	{
		clothesCategory[cloth[CATEGORY]].push_back(cloth[CLOTHE_NAME]);
	}

	for (auto [category, clothesInCategory] : clothesCategory)
	{
		answer *= clothesInCategory.size() + 1;
	}

	return answer - 1;
}