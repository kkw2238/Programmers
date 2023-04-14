/*
	https://school.programmers.co.kr/learn/courses/30/lessons/181187
*/

#include <string>
#include <vector>

using namespace std;

long long getPoint(long long r, bool addOutline)
{
    long long result = 0;

    for (long long x = -r; x <= 0; ++x)
    {
        long long beforeSqrt = (r - x) * (r + x);
        long long y = sqrtl(beforeSqrt);

        result += (y * 2 + 1) * 2;

        if (!addOutline && (y * y) == beforeSqrt)
        {
            result -= 4;
        }
    }

    return result - (2 * r + 1);
}

long long solution(int r1, int r2) {
    return getPoint(r2, true) - getPoint(r1, false) + 4;
}