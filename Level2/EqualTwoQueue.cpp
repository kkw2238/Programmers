/*
    https://school.programmers.co.kr/learn/courses/30/lessons/118667
*/
//
//#include <string>
//#include <vector>
//#include <list>
//#include <numeric>
//
//using namespace std;
//
//int minimumCount = 2147483647;
//
//void move(list<int>& src, list<int>& dest, long long& sumOfSrc, long long& sumOfDest)
//{
//    int num = src.front();
//
//    sumOfSrc -= num;
//    sumOfDest += num;
//
//    src.pop_front();
//    dest.push_back(num);
//}
//
//void RollBack(list<int>& src, list<int>& dest, long long& sumOfSrc, long long& sumOfDest)
//{
//    int num = dest.back();
//
//    sumOfSrc += num;
//    sumOfDest -= num;
//
//    src.push_front(num);
//    dest.pop_back();
//}
//
//void Find(list<int> queue1, list<int> queue2, long long sumOfQueue1, long long sumOfQueue2, int moveCount)
//{
//    if (moveCount >= (queue1.size() + queue2.size()))
//    {
//        return;
//    }
//    else if (moveCount > minimumCount)
//    {
//        return;
//    }
//
//    if (sumOfQueue1 == sumOfQueue2)
//    {
//        if (moveCount < minimumCount)
//        {
//            minimumCount = moveCount;
//        }
//        return;
//    }
//
//    if (!queue1.empty()) 
//    {
//        move(queue1, queue2, sumOfQueue1, sumOfQueue2);
//        Find(queue1, queue2, sumOfQueue1, sumOfQueue2, moveCount + 1);
//        RollBack(queue1, queue2, sumOfQueue1, sumOfQueue2);
//    }
//    if (!queue2.empty())
//    {
//        move(queue2, queue1, sumOfQueue2, sumOfQueue1);
//        Find(queue1, queue2, sumOfQueue1, sumOfQueue2, moveCount + 1);
//        RollBack(queue2, queue1, sumOfQueue2, sumOfQueue1);
//    }
//}
//
//int solution(vector<int> queue1, vector<int> queue2) {
//    long long lTotal = accumulate(queue1.begin(), queue1.end(), 0);
//    long long rTotal = accumulate(queue2.begin(), queue2.end(), 0);
//
//    list<int> listQueue1(queue1.begin(), queue1.end());
//    list<int> listQueue2(queue2.begin(), queue2.end());
//
//    Find(listQueue1, listQueue2, lTotal, rTotal, 0);
//
//    return minimumCount == 2147483647 ? -1 : minimumCount;
//}


//#include <string>
//#include <vector>
//#include <numeric>
//
//using namespace std;
//
//int GetCount(int length, int begin, int end)
//{
//    int half = length / 2;
//    if (begin >= half)
//    {
//        if (end == (length - 1))
//        {
//            return begin - half;
//        }
//        else if (end >= begin)
//        {
//            return half + (begin - half) * 2 + (end - begin);
//        }
//        else
//        {
//            return end + begin - half;
//        }
//    }
//    else
//    {
//        if (end == (half - 1))
//        {
//            return begin;
//        }
//        else if (end >= half)
//        {
//            return begin + end - half;
//        }
//        else
//        {
//            return begin * 2 + (end - begin) + half;
//        }
//    }
//}
//
//int Find(vector<int> queue, long long sumOfAll)
//{
//    if (sumOfAll % 2 == 1)
//    {
//        return -1;
//    }
//
//    unsigned long long half = sumOfAll / 2;
//    int begin = 0, end = 0;
//    unsigned long long sum = 0;
//
//    for (; begin < queue.size();)
//    {
//        int endPos = end % queue.size();
//        if ((sum + queue[endPos]) < half)
//        {
//            sum += queue[endPos];
//            ++end;
//        }
//        else if ((sum + queue[endPos]) > half)
//        {
//            sum -= queue[begin];
//            ++begin;
//        }
//        else
//        {
//            return GetCount(queue.size(), begin, endPos) + 1;
//        }
//    }
//
//    return -1;
//}
//
//int solution(vector<int> queue1, vector<int> queue2) {
//    unsigned long long sumOfQueue = 0;
//
//    vector<int> unionQueue = move(queue1);
//    unionQueue.insert(unionQueue.end(), queue2.begin(), queue2.end());
//
//    sumOfQueue = accumulate(unionQueue.begin(), unionQueue.end(), 0);
//
//    return Find(unionQueue, sumOfQueue);
//}

#include <string>
#include <vector>
#include <numeric>

using namespace std;

int GetCount(int length, int begin, int end)
{
    int half = length / 2;
    if (begin >= half)
    {
        if (end == (length - 1))
        {
            return begin - half;
        }
        else if (end >= begin)
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
        if (end == (half - 1))
        {
            return begin;
        }
        else if (end >= half)
        {
            return begin + end - half + 1;
        }
        else
        {
            return begin * 2 + (end - begin) + half;
        }
    }
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 2147483647;
    long long sumOfqueue = 0;

    for (int i = 0; i < queue1.size(); ++i)
    {
        sumOfqueue += queue1[i] + queue2[i];
    }

    vector<int> totalQueue = move(queue1);
    totalQueue.insert(totalQueue.end(), queue2.begin(), queue2.end());

    if (sumOfqueue % 2 == 1)
    {
        return -1;
    }

    int beg = 0, end = 0, endPos = 0;
    long long sum = totalQueue[0];
    long long mid = sumOfqueue / 2;

    for (; beg < totalQueue.size();)
    {
        if (sum < mid)
        {
            endPos = ++end % totalQueue.size();
            sum += totalQueue[endPos];
        }
        else if (sum > mid)
        {
            sum -= totalQueue[beg];
            ++beg;
        }
        else
        {
            endPos = end % totalQueue.size();
            answer = min(answer, GetCount(totalQueue.size(), beg, endPos));
            sum -= totalQueue[beg];
            ++beg;
        }
    }

    if (answer == 2147483647)
    {
        return -1;
    }

    return answer;
}