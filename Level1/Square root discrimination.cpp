/*
	https://programmers.co.kr/learn/courses/30/lessons/12934
*/

#include <math.h>
/*
	SQRT(n) ^ 2 = n인 성질을 이용하여 판별
*/

long long solution(long long n) {
	const long long SQRT = sqrt(n);

	// SQRT^2이 n일 경우
	if ((SQRT * SQRT) == n)
	{
		return (SQRT + 1) * (SQRT + 1);
	}

	return -1;
}