/*
    https://school.programmers.co.kr/learn/courses/30/lessons/148652
*/

#include <string>
#include <vector>

using namespace std;

int range(long long target, int n, long long totalRange)
{
    long long targetPos = 1;
    for (int i = 0; i < n; ++i)
    {
        targetPos *= 5;
        if (targetPos > target)
        {
            n = i;
        }
    }
}

int solution(int n, long long l, long long r) {
    long long length = 1;

    for (int i = 0; i < n; ++i)
    {
        length *= 5;
    }

    return range(0, length, l, r);
}