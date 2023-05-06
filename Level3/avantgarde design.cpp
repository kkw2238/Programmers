/*
	https://school.programmers.co.kr/learn/courses/30/lessons/181186
*/

//#include <string>
//#include <vector>
//
//using namespace std;
//
//int WAY[4]{ 0, 1, 2, 5 };
//
//int DFS(const int n)
//{
//    vector<int> a;
//    
//}
//
//int solution(int n) {
//    int answer = 0;
//
//    return answer;
//}

#include <string>
#include <vector>

using namespace std;

unsigned long long solution(int balls, int share) {
    unsigned long long totalNumerator = 1, totalDenominator = 1;

    for (int i = 1; i <= balls; ++i)
    {
        if ((i <= (balls - share)) && (i > share))
        {
            continue;
        }

        if (i <= balls - share)
        {
            totalDenominator *= (unsigned long long)i;
        }
        if (i > share)
        {
            totalNumerator *= (unsigned long long)i;
        }
    }

    return totalNumerator / totalDenominator;
}

long long llsolution(int balls, int share) {
    long long totalNumerator = 1, totalDenominator = 1;

    for (int i = 1; i <= balls; ++i)
    {
        if ((i <= (balls - share)) && (i > share))
        {
            continue;
        }

        if (i <= balls - share)
        {
            totalDenominator *= (long long)i;
        }
        if (i > share)
        {
            totalNumerator *= (long long)i;
        }
    }

    return totalNumerator / totalDenominator;
}