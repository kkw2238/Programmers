/*
	https://school.programmers.co.kr/learn/courses/30/lessons/138475?language=cpp
*/
//

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int e, vector<int> starts)
{
    vector<int> answer;
    vector<int> divisorCounts(e + 2, 1);
    vector<int> maximumDivisorIndex(e + 2, e);

    for (int i = 2; i <= e; ++i)
    {
        for (int j = 2; j <= e / i; ++j)
        {
            ++divisorCounts[i * j];
        }
    }

    for (int i = e; i >= 1; --i)
    {
        int index = maximumDivisorIndex[i + 1];

        if (divisorCounts[index] <= divisorCounts[i])
        {
            index = i;
        }
        
        maximumDivisorIndex[i] = index;
    }

    for (int index : starts)
    {
        answer.push_back(maximumDivisorIndex[index]);
    }

    return answer;
}

int main()
{
    solution(8, { 1,3,7 });
}


/*
* vector<set<int>> divisorCounts;
vector<int> divisorCounts2;
    void addDivisor(int n, int primeNumber)
{
    int childNum = n / primeNumber;

    for (int d : divisorCounts[childNum])
    {
        divisorCounts[n].insert(d);
        divisorCounts[n].insert(d * primeNumber);
    }
}

*/

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


//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//vector<int> divisorCounts;
//
//int getDivisor(int n)
//{
//    int result = 0;
//    int sqrtNum = sqrt(n) + 1;
//    for (int i = 1; i <= sqrtNum; ++i)
//    {
//        if (i * i == n)
//        {
//            result += 1;
//        }
//        else if(n % i == 0)
//        {
//            result += 2;
//        }
//    }
//    return result;
//}
//
//vector<int> solution(int e, vector<int> starts) {
//    vector<int> answer;
//    divisorCounts = vector<int>(e + 1, 1);
//
//    for (int index : starts)
//    {
//        int maximum = 0;
//        int indexArray = 0;
//        for (int i = index; i <= e; ++i)
//        {
//            if (divisorCounts[i] == 0)
//            {
//                divisorCounts[i] = getDivisor(i);
//            }
//            if (divisorCounts[i] > maximum)
//            {
//                maximum = divisorCounts[i];
//                indexArray = i;
//            }
//        }
//        answer.push_back(indexArray);
//    }
//
//    return answer;
//}