/*
	https://programmers.co.kr/learn/courses/30/lessons/12940
*/
#include <vector>
#include <algorithm>

using namespace std;

/* 
	유클리디안 호제법	:
		a와 b에 대한 최대 공약수는 a와 (b % a) = r의 최대 공약수와 같다. ( 단, a < b )
		이러한 성질에 따라 a 와 (a % r) = r0의 최대 공약수가 같으며 
		최종적으로 r % r0 == 0일때 r0이 a 와 b의 최대 공약수이다.

*/
int Euclidean(int a, int b)
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

vector<int> solution(int n, int m) {
	const int GDC = Euclidean(n, m);

	return vector<int>{GDC, n* m / GDC};
}