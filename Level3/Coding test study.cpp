/*
	https://school.programmers.co.kr/learn/courses/30/lessons/118668
*/

#include <vector>
#include <algorithm>

using namespace std;

enum { alp_req, cop_req, alp_rwd, cop_rwd, cost };

int alp_max = 0, cop_max = 0;
int min_time = 2147483647;

void DFS(int alp, int cop, int time, const vector<vector<int>>& problems, int index)
{
    if (alp < problems[index][alp_req])
    {
        time += problems[index][alp_req] - alp;
        alp = problems[index][alp_req]; 
    }
    if (cop < problems[index][cop_req])
    {
        time += problems[index][cop_req] - cop;
        cop = problems[index][cop_req];
    }

    if (alp >= alp_max && cop >= cop_max)
    {
        min_time = min(time, min_time);
        return;
    }

    int maximum = 0;
    if (problems[index][alp_rwd] > 0)
    {
        maximum = max((alp_max - alp) / problems[index][alp_rwd] + 1, maximum);
    }
    if (problems[index][cop_rwd] > 0)
    {
        maximum = max((cop_max - cop) / problems[index][cop_rwd] + 1, maximum);
    }

    for (int i = 0; i < maximum; ++i)
    {
        DFS(alp + problems[index][alp_rwd] * i, cop + problems[index][cop_rwd] * i, time + problems[index][cost] * i, problems, index + 1);
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) {

    sort(problems.begin(), problems.end(), [](vector<int>& a, vector<int>& b) {
        return (a[cop_req] + a[alp_req]) < (b[cop_req] + b[alp_req]);
    });

    for (int i = 0; i < problems.size(); ++i)
    {
        alp_max = max(alp_max, problems[i][alp_req]);
        cop_max = max(cop_max, problems[i][cop_req]);
    }

    DFS(alp, cop, 0, problems, 0);

    return min_time;
}

int main()
{
    solution(0, 0, { {0, 0, 2, 1, 2}, {4, 5, 3, 1, 2 }, {4, 11, 4, 0, 2 }, {10, 4, 0, 4, 2} });
}