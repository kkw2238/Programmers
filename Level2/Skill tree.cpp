/*
	https://programmers.co.kr/learn/courses/30/lessons/49993
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsAbleSkillTree(const string skill, const string& skill_tree)
{
	int skill_index = -2;

	for (const char c : skill)
	{
		// 스킬 순서대로 탐색
		int now_Skill_Index = skill_tree.find(c);

		// 현재 탐색한 스킬이 스킬트리에서 발견된 경우
		if (now_Skill_Index != string::npos)
		{
			// 스킬 순서가 잘 못된 경우( 후행 스킬이 선행 스킬보다 앞선 경우, 선행 스킬을 배우지 않은 경우 ) 
			if (now_Skill_Index < skill_index || skill_index == string::npos)
			{
				return false;
			}
		}
		
		skill_index = now_Skill_Index;
	}

	return true;
}

int solution(string skill, vector<string> skill_trees) {
	return count_if(skill_trees.begin(), skill_trees.end(), [&skill](const string& skill_tree) 
	{
		return IsAbleSkillTree(skill, skill_tree);
	});
}

/* 예전 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (string& str : skill_trees) {

		auto iter = str.begin();
		for (char c : skill) {
			auto newiter = find(str.begin(), str.end(), c);

			if (newiter < iter) break;

			if (iter == str.end() && newiter != str.end()) break;

			if (c == skill[skill.size() - 1]) ++answer;

			iter = newiter;
		}
	}

	return answer;
}
*/