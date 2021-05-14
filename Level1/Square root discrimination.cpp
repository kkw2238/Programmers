/*
	https://programmers.co.kr/learn/courses/30/lessons/12934
*/

#include <math.h>
/*
	SQRT(n) ^ 2 = n�� ������ �̿��Ͽ� �Ǻ�
*/

long long solution(long long n) {
	const long long SQRT = sqrt(n);

	// SQRT^2�� n�� ���
	if ((SQRT * SQRT) == n)
	{
		return (SQRT + 1) * (SQRT + 1);
	}

	return -1;
}