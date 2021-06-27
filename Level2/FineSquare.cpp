/*
	https://programmers.co.kr/learn/courses/30/lessons/62048
*/

#include <algorithm>

using namespace std;

double Euclidean(int a, int b)
{
	int min_Num = min(a, b);
	int max_Num = max(a, b);

	while (max_Num % min_Num != 0)
	{
		max_Num = max_Num % min_Num;
		swap(max_Num, min_Num);
	}

	return min_Num;
}

long long solution(int w, int h) {
    double div = h / (double)w;
	const double GDC = Euclidean(w, h);
	
	div* GDC;


    return (double)w * (double)h;
}

int main()
{
    solution(8, 12);
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