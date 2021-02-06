/*
	https://programmers.co.kr/learn/courses/30/lessons/62048
*/
#include <cmath>
using namespace std;

long long solution(int w, int h)
{
	long long result = 0;
	int width = w > h ? w : h;
	int height = w > h ? h : w;

	double a = (double)height / (double)width;

	for (double i = 1; i <= width; ++i) {
		result += ceil(a * i) - floor(a * (i - 1));
	}

	return (long long)w * (long long)h - result;
}