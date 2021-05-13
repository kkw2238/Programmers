/*
	https://programmers.co.kr/learn/courses/30/lessons/12947
*/
#include <vector>

using namespace std;

bool solution(int x) {
	int digit = 0;
	int memX = x;

	while(x > 0)
	{
		digit += x % 10;
		x /= 10;
	}
	return memX % digit == 0;
}