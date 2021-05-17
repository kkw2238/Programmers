/*
	https://programmers.co.kr/learn/courses/30/lessons/12982
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
	// �ʿ� ������ ���� ������ ����
	sort(d.begin(), d.end());

	// ���� ������ - �Ǵ� �ε����� Ž��
	auto iter = find_if(d.begin(), d.end(), [&budget](const int price) 
	{
		budget -= price;
		return budget < 0;
	});

	return distance(d.begin(), iter);
}