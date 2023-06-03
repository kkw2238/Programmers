/*
    https://school.programmers.co.kr/learn/courses/30/lessons/131129?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

vector<int> div(int n, int target, int totalCount, int sbCount, vector<int>& ableScore)
{
    if (n > target)
    {
        return { totalCount, sbCount };
    }
    int count = target / n;

}

vector<int> solution(int target) {
    vector<vector<int>> ableScore(71, { 2, 2 });

    for (int i = 1; i <= 20; ++i)
    {
        ableScore[i * 2] = {1, 0};
        ableScore[i * 3] = {1, 0};
        ableScore[i] = {1, 1};
    }
    ableScore[50] = {1, 1};

    vector<int> answer{ 0, 0 };
    if (target <= 70)
    {
        return ableScore[target];
    }

    answer[0] = target / 60;
    answer[0] += ableScore[target % 60][0];
    answer[1] = ableScore[target % 60][1];

    return answer;
}
