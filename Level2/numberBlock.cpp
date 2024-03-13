/*
    https://programmers.co.kr/learn/courses/30/lessons/12923
*/

#include <vector>
#include <cmath>

using namespace std;

int getMeasure(long long n)
{
    int sqrtN = sqrtl(n);
    int biggest = 1;

    for (int i = 2; i <= sqrtN + 1; ++i)
    {
        if (n % i == 0)
        {
            if (n / i <= 10000000)
            {
                return n / i;
            }
            biggest = i;
        }
    }

    return biggest;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    if (begin == 1)
    {
        answer.emplace_back(0);
        ++begin;
    }

    for (long long ll = begin; ll <= end; ++ll)
    {
        answer.emplace_back(getMeasure(ll));
    }

    return answer;
}