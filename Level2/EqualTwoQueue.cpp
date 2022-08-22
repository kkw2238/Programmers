/*
    https://school.programmers.co.kr/learn/courses/30/lessons/118667
*/

#include <string>
#include <vector>
#include <numeric>

using namespace std;

int GetCount(int length, int begin, int end)
{
    int half = length / 2;
    if (begin >= half)
    {
        if (end == length - 1)
        {
            return begin - half;
        }
        else if (end >= half)
        {
            return half + (begin - half) * 2 + (end - begin);
        }
        else
        {
            return end + begin - half;
        }
    }
    else
    {
        if (end == half - 1)
        {
            return begin;
        }
        else if (end >= half)
        {
            return begin + end - half;
        }
        else
        {
            return begin * 2 + (end - begin) + half;
        }
    }
}

int Find(vector<int> queue, int sumOfAll)
{
    int half = sumOfAll / 2;
    int begin = 0, end = 0;
    int sum = 0;

    for (; begin < queue.size();)
    {
        int endPos = end % queue.size();
        if ((sum + queue[endPos]) < half)
        {
            sum += queue[endPos];
            ++end;
        }
        else if ((sum + queue[endPos]) > half)
        {
            sum -= queue[begin];
        }
        else
        {
            return GetCount(queue.size(), begin, endPos);
        }
    }

    return -1;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int sumOfQueue = 0;

    vector<int> unionQueue = move(queue1);
    unionQueue.insert(unionQueue.end(), queue2.begin(), queue2.end());

    sumOfQueue = accumulate(unionQueue.begin(), unionQueue.end(), 0);

    return Find(unionQueue, sumOfQueue);
}