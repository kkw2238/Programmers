/*
    https://school.programmers.co.kr/learn/courses/30/lessons/148652
*/

#include <string>
#include <cmath>
#include <vector>

using namespace std;

int oneCount[6]{ 0, 1, 2, 2, 3, 4 };

int range(long long target, int n)
{
    if (target <= 5)
    {
        return oneCount[target];
    }

    long long demoninator = (long long)(pow(5, n));
    int result = pow(4, n) * oneCount[(target / demoninator)];

    if ((target / demoninator) == 2)
    {
        return result;
    }
    else
    {
        result += range(target % demoninator, n - 1);
    }

    return result;
}

int getExponent(long long n)
{
    long long num = 1;
    for (int i = 1; i < n; ++i)
    {
        num *= 5;

        if (num > n)
        {
            return i - 1;
        }
    }

    return -1;
}

int solution(int n, long long l, long long r) {
    return range(r, getExponent(r)) - range(l - 1, getExponent(l - 1));
}