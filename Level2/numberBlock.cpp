/*
    https://programmers.co.kr/learn/courses/30/lessons/12923
*/

#include <vector>
#include <cmath>

using namespace std;

const int MAXIMUM_BLOCK = 10000000;

int getMeasure(int n)
{
    int sqrtN = sqrt(n);

    for (int i = 2; i <= sqrtN + 1; ++i)
    {
        if (n % i == 0 && (n / i) <= MAXIMUM_BLOCK)
        {
            return n / i;
        }
    }

    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    if (begin == 1)
    {
        answer.emplace_back(0);
        ++begin;
    }

    for (int ll = static_cast<int>(begin); ll <= static_cast<int>(end); ++ll)
    {
        answer.emplace_back(getMeasure(ll));
    }

    return answer;
}