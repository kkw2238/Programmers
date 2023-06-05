/*
    https://school.programmers.co.kr/learn/courses/30/lessons/131129?language=cpp
*/
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> div(int n, int target, int totalCount, int sbCount, vector<int>& ableScore)
//{
//    if (n > target)
//    {
//        return { totalCount, sbCount };
//    }
//    int count = target / n;
//
//}
//
//vector<int> solution(int target) {
//    vector<vector<int>> ableScore(71, { 2, 2 });
//
//    for (int i = 1; i <= 20; ++i)
//    {
//        ableScore[i * 2] = {1, 0};
//        ableScore[i * 3] = {1, 0};
//        ableScore[i] = {1, 1};
//    }
//    ableScore[50] = {1, 1};
//
//    vector<int> answer{ 0, 0 };
//    if (target <= 70)
//    {
//        return ableScore[target];
//    }
//
//    answer[0] = target / 60;
//    answer[0] += ableScore[target % 60][0];
//    answer[1] = ableScore[target % 60][1];
//
//    return answer;
//}

#include <vector>

using namespace std;

const bool isAbleSave(const vector<int>& a, const vector<int>& b, const vector<int>& c)
{
    if ((a[0] + b[0]) == c[0])
    {
        return (a[1] + b[1]) > c[1];
    }
    return (a[0] + b[0]) < c[0];
}

vector<int> solution(int target) {
    vector<vector<int>> ableScore(target + 2, { 999999, 999999 });

    for (int i = 1; i <= 20; ++i)
    {
        if (i > target)
        {
            break;
        }

        if ((i * 2) <= target)
        {
            ableScore[i * 2] = { 1, 0 };
        }
        if ((i * 3) <= target)
        {
            ableScore[i * 3] = { 1, 0 };
        }
        ableScore[i] = { 1, 1 };
    }
    for (int i = 21; i <= 40; ++i)
    {
        if (i > target)
        {
            break;
        }
        if (ableScore[i][0] == 999999)
        {
            ableScore[i] = { 2, 2 };
        }
    }

    if (target >= 50)
    {
        ableScore[50] = { 1, 1 };
    }

    for (int i = 40; i <= target; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if ((i + j) > target)
            {
                break;
            }
            if (isAbleSave(ableScore[i], ableScore[j], ableScore[i + j]))
            {
                ableScore[i + j] = { ableScore[i][0] + ableScore[j][0], ableScore[i][1] + ableScore[j][1] };
            }
        }
    }

    return ableScore[target];
}