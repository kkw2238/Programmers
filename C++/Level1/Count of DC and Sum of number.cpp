/*
    https://programmers.co.kr/learn/courses/30/lessons/77884
*/

#include <math.h>

using namespace std;

int GetCountOfDC(const int num)
{
    const int SQRT = sqrt(num);
    int count = 0;

    for (int i = SQRT; i >= 1; --i)
    {
        if (num % i == 0) 
        {
            count += 2;
        }
    }
    
    if (SQRT * SQRT == num)
    {
        --count;
    }

    return count;
}

int solution(int left, int right) {
    int answer = 0;

    for (left; left <= right; ++left)
    {
        if (GetCountOfDC(left) % 2 == 0)
        {
            answer += left;
        }
        else
        {
            answer -= left;
        }
    }

    return answer;
}