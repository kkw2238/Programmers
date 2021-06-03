/*
	https://programmers.co.kr/learn/courses/30/lessons/42626
*/

#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int NewScoville(int most, int secondly) {
	return most + secondly * 2;
}

int solution(vector<int> scoville, int K) {
	multiset<int> basket(scoville.begin(), scoville.end());

	int answer = 0;
	while (find_if(basket.begin(), basket.end(), [&K](int a) { return a < K; }) != basket.end()) {
		if (basket.size() <= 1) return -1;
		auto most = basket.begin();
		auto secondly = ++(basket.begin());

		basket.insert(NewScoville(*most, *secondly));
		basket.erase(most, ++secondly);

		++answer;
	}

	return answer;
}