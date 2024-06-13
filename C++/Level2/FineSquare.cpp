/*
	https://programmers.co.kr/learn/courses/30/lessons/62048
*/

#include <algorithm>

using namespace std;

long long solution(int w, int h) {
	if (w < h)
	{
		swap(w, h);
	}

	long double answer = 0.0;
	double div = (double)(h) / (double)(w);

	for (double d = 1; d <= (double)w; ++d)
	{
		answer += ceill(d * div) - floorl((d - 1) * div);
	}

	return (long long)w * (long long)h - answer;
}

//#include <cmath>
//using namespace std;
//
//long long solution(int w, int h)
//{
//	long long result = 0;
//	int width = w > h ? w : h;
//	int height = w > h ? h : w;
//
//	double a = (double)height / (double)width;
//
//	for (double i = 1; i <= width; ++i) {
//		result += ceil(a * i) - floor(a * (i - 1));
//	}
//
//	return (long long)w * (long long)h - result;
//}