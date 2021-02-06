/*
	https://programmers.co.kr/learn/courses/30/lessons/12945
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	const unsigned int Division = 1234567;
	vector<unsigned int> val = { 0 , 1 };

	for (int i = 2; i < n + 1; ++i) {
		val.push_back((val[i - 2] + val[i - 1]) % Division);
	}

	return *(val.end() - 1);
}