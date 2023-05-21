/*
	https://school.programmers.co.kr/learn/courses/30/lessons/138475?language=cpp
*/

#include <vector>
#include <set>
#include <cmath>

using namespace std;

vector<int> primeNumbers;
vector<vector<byte>> biggestRanges;

vector<set<int>> divisorCounts;

void addDivisor(int n, int primeNumber)
{
    int childNum = n / primeNumber;

    for (int d : divisorCounts[childNum])
    {
        divisorCounts[n].insert(d);
        divisorCounts[n].insert(d * primeNumber);
    }
}

void getDivisor(int n)
{
    for (int i : primeNumbers)
    {
        if (n % i == 0)
        {
            addDivisor(n, i);
            return;
        }
    }

    divisorCounts[n].insert(n);
    primeNumbers.push_back(n);
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    divisorCounts = vector<set<int>>(e + 1, set<int>());

    divisorCounts[1].insert(1);
    for (int i = 2; i <= e; ++i)
    {
        divisorCounts[i].insert(1);
        getDivisor(i);
    }

    for (int index : starts)
    {
        int maximum = 0;
        int indexArray = 0;
        for (int i = index; i <= e; ++i)
        {
            if (divisorCounts[i].size() > maximum)
            {
                maximum = divisorCounts[i].size();
                indexArray = i;
            }
        }
        answer.push_back(indexArray);
    }

    return answer;
}


int main()
{
    solution(8, { 1,3,7 });
}



//const bool isAblefactorization(int num, int primeNum)
//{
//    return (num % primeNum) == 0 && (primeCounts[num] == 0);
//}
//
//void factorization(int n)
//{
//    int memNum = n;
//    for (int i = 0; i < primeNumbers.size();)
//    {
//        if (memNum % primeNumbers[i] == 0)
//        {
//            ++primeCounts[n];
//            memNum /= primeNumbers[i];
//        }
//        else
//        {
//            ++i;
//        }
//    }
//
//    //for (int i = 2; i <= n; ++i)
//    //{
//    //    biggestRanges[i][n] = max(biggestRanges[i][n - 1], (byte)primeCounts[n]);
//    //}
//}
//
//vector<int> solution(int e, vector<int> starts) {
//    vector<int> answer;
//    primeCounts = vector<int>(e + 1, 1);
//    primeCounts[1] = 1;
//    for (int i = 2; i <= e; ++i)
//    {
//        initPrime(i);
//        if (primeCounts[i] == 1)
//        {
//            factorization(i);
//        }
//    }
//
//    for (int index : starts)
//    {
//        int maximum = 0;
//        int indexArray = 0;
//        for (int i = index; i <= e; ++i)
//        {
//            if (primeCounts[i] > maximum)
//            {
//                maximum = primeCounts[i];
//                indexArray = i;
//            }
//        }
//        answer.push_back(indexArray);
//    }
//
//    return answer;
//}