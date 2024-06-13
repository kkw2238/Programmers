/*
	https://programmers.co.kr/learn/courses/30/lessons/12982
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
	// 필요 예산을 낮은 순으로 정렬
	sort(d.begin(), d.end());

	// 남은 예산이 - 되는 인덱스를 탐색
	auto iter = find_if(d.begin(), d.end(), [&budget](const int price) 
	{
		budget -= price;
		return budget < 0;
	});

	return distance(d.begin(), iter);
}