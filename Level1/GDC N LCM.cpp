/*
	https://programmers.co.kr/learn/courses/30/lessons/12940
*/
#include <vector>
#include <algorithm>

using namespace std;

/* 
	��Ŭ����� ȣ����	:
		a�� b�� ���� �ִ� ������� a�� (b % a) = r�� �ִ� ������� ����. ( ��, a < b )
		�̷��� ������ ���� a �� (a % r) = r0�� �ִ� ������� ������ 
		���������� r % r0 == 0�϶� r0�� a �� b�� �ִ� ������̴�.

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