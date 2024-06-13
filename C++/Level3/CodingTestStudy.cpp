/*
    https://school.programmers.co.kr/learn/courses/30/lessons/118668
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum { alp_req, cop_req, alp_rwd, cop_rwd, cost };

const int getStudyTime(int alp, int cop, const vector<int>& indices, const vector<vector<int>>& problems)
{
    int time = 0;
    for (int index : indices)
    {
        if (problems[index][alp_req] > alp)
        {
            time += problems[index][alp_req] - alp;
        }
        if (problems[index][cop_req] > cop)
        {
            time += problems[index][cop_req] - cop;
        }

        time += problems[index][cost];
        alp += problems[index][alp_rwd];
        cop += problems[index][cop_rwd];
    }

    return time;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 2147483647;
    vector<int> indices;

    for (int i = 0; i < problems.size(); ++i)
    {
        indices.push_back(i);
    }

    answer = min(answer, getStudyTime(alp, cop, indices, problems));
    while (next_permutation(indices.begin(), indices.end()))
    {
        answer = min(answer, getStudyTime(alp, cop, indices, problems));
    }

    return answer;
}