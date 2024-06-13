/*
	https://programmers.co.kr/learn/courses/30/lessons/1845
*/

#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
	set phonketmons(nums.begin(), nums.end());
	if (phonketmons.size() > nums.size() / 2)
	{
		return nums.size() / 2;
	}
	return phonketmons.size();
}

/* 예전 코드
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	set<int> p(nums.begin(), nums.end());
	return p.size() > nums.size() / 2 ? nums.size() / 2 : p.size();
}
*/