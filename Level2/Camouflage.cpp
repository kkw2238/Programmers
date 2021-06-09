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
		answer *= clothesInCategory.size();
	}

	if (clothesCategory.size() > 1)
	{
		answer += clothes.size();
	}

	return answer;
}

/* 예전 코드
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	const int CATEGORY = 1, CLOTH = 0;
	int cases = 1;

	map<string, vector<string>> clotheCategory;
	vector<int> clothInCategoryCounts;
	vector<string> category;

	for (vector<string>& cloth : clothes)  clotheCategory[cloth[CATEGORY]].emplace_back(cloth[CLOTH]);
	for (pair<string, vector<string>> categoryAndClothes : clotheCategory) 	cases *= (categoryAndClothes.second.size() + 1);

	return cases - 1;
}
*/