/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12920
*/
#include <iostream>

#include <vector>

using namespace std;

const int MAXIMUM = 2147483647;

const bool isSuccessfully(int n, const int time,const vector<int>& cores)
{
    for (const int core : cores)
    {
        n -= time / core;

        if (n <= 0)
        {
            return true;
        }
    }
    
    return false;
}

const int calRemainWork(int n, const int time, const vector<int>& cores)
{
    for (const int core : cores)
    {
        n -= time / core;
    }

    return n;
}

int solution(int n, vector<int> cores) {
    n -= cores.size();

    int left = 0, right = MAXIMUM, mid = MAXIMUM / 2;
    int result = MAXIMUM;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (isSuccessfully(n, mid, cores))
        {
            if (result > mid)
            {
                result = mid;
            }
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    int remainWork = calRemainWork(n, result, cores);

    for (int i = cores.size() - 1; i >= 0; --i)
    {
        if (result % cores[i] == 0)
        {
            ++remainWork;
            if (remainWork > 0)
            {
                return i + 1;
            }
        }
    }

    return 0;
}

int main()
{
    solution(6, { 1,2,3 });
}
