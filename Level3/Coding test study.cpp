/*
	https://school.programmers.co.kr/learn/courses/30/lessons/118668
*/

//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//enum { alp_req, cop_req, alp_rwd, cop_rwd, cost };
//
//int alp_max = 0, cop_max = 0;
//vector<vector<int>> minTimeAtAlpCop(151, vector<int>(151, 2147483647));
//
//void DFS(int alp, int cop, int time, vector<vector<int>>& problems, int index, bool beforeAdd)
//{
//    alp = min(alp_max, alp);
//    cop = min(cop_max, cop);
//
//    if (beforeAdd)
//    {
//        if (alp < problems[index][alp_req])
//        {
//            time += problems[index][alp_req] - alp;
//            alp = problems[index][alp_req];
//        }
//        if (cop < problems[index][cop_req])
//        {
//            time += problems[index][cop_req] - cop;
//            cop = problems[index][cop_req];
//        }
//    }
//
//    if (minTimeAtAlpCop[alp][cop] <= time)
//    {
//        return;
//    }
//    else
//    {
//        minTimeAtAlpCop[alp][cop] = time;
//    }
//
//    if ((alp >= alp_max && cop >= cop_max) || index == problems.size() - 1)
//    {
//        return;
//    }
//
//    int maximum = 0;
//    if (problems[index][alp_rwd] > 0)
//    {
//        maximum = max((alp_max - alp) / problems[index][alp_rwd] + 1, maximum);
//    }
//    if (problems[index][cop_rwd] > 0)
//    {
//        maximum = max((cop_max - cop) / problems[index][cop_rwd] + 1, maximum);
//    }
//
//    for (int j = index + 1; j < problems.size(); ++j)
//    {
//        swap(problems[index + 1], problems[j]);
//        for (int i = 0; i <= maximum; ++i)
//        {
//            int nextAlp = alp + problems[index][alp_rwd] * i;
//            int nextCop = cop + problems[index][cop_rwd] * i;
//
//            if (nextAlp < problems[index + 1][alp_req] || nextCop < problems[index + 1][cop_req])
//            {
//                DFS(nextAlp, nextCop, time + problems[index][cost] * i, problems, index + 1, true);
//            }
//            DFS(nextAlp, nextCop, time + problems[index][cost] * i, problems, index + 1, false);
//
//            if (alp < problems[index][alp_req] || cop < problems[index][cop_req])
//            {
//                break;
//            }
//        }
//        swap(problems[index + 1], problems[j]);
//    }
//}
//
//int solution(int alp, int cop, vector<vector<int>> problems) {
//    for (int i = 0; i < problems.size(); ++i)
//    {
//        alp_max = max(alp_max, problems[i][alp_req]);
//        cop_max = max(cop_max, problems[i][cop_req]);
//    }
//
//    for (int j = 0; j < problems.size(); ++j)
//    {
//        swap(problems[j], problems[0]);
//        if (alp < problems[0][alp_req] || cop < problems[0][cop_req])
//        {
//            DFS(alp, cop, 0, problems, 0, true);
//        }
//        DFS(alp, cop, 0, problems, 0, false);
//
//        swap(problems[j], problems[0]);
//    }
//
//    return minTimeAtAlpCop[alp_max][cop_max];
//}




//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//enum { alp_req, cop_req, alp_rwd, cop_rwd, cost };
//
//int alp_max = 0, cop_max = 0;
//vector<vector<int>> minTimeAtAlpCop(151, vector<int>(151, 2147483647));
//
//void DFS(int alp, int cop, int time, vector<vector<int>>& problems, int index)
//{
//    int maximum = 0;
//    alp = min(alp_max, alp);
//    cop = min(cop_max, cop);
//
//    if (problems[index][alp_req] > alp)
//    {
//        time += problems[index][alp_req] - alp;
//        alp = problems[index][alp_req];
//    }
//    if (problems[index][cop_req] > cop)
//    {
//        time += problems[index][cop_req] - cop;
//        cop = problems[index][cop_req];
//    }
//
//    if (alp == alp_max && cop == cop_max)
//    {
//        minTimeAtAlpCop[alp][cop] = min(minTimeAtAlpCop[alp][cop], time);
//        return;
//    }
//    else if (minTimeAtAlpCop[alp][cop] <= time)
//    {
//        return;
//    }
//    else if (minTimeAtAlpCop[alp][cop] > time)
//    {
//        minTimeAtAlpCop[alp][cop] = time;
//    }
//
//    if (problems[index][alp_rwd] > 0)
//    {
//        maximum = max(maximum, (alp_max - alp) / problems[index][alp_rwd] + 1);
//    }
//    if (problems[index][cop_rwd] > 0)
//    {
//        maximum = max(maximum, (cop_max - cop) / problems[index][cop_rwd] + 1);
//    }
//
//    for (int i = index + 1; i < problems.size(); ++i)
//    {        
//        swap(problems[i], problems[index + 1]);
//        for (int j = 0; j <= maximum; ++j)
//        {
//            DFS(alp + problems[index][alp_rwd] * j, cop + problems[index][cop_rwd] * j, time + problems[index][cost] * j, problems, index + 1);
//        }
//        swap(problems[i], problems[index + 1]);
//    }
//}
//
//int solution(int alp, int cop, vector<vector<int>> problems) {
//    for (int i = 0; i < problems.size(); ++i)
//    {
//        alp_max = max(alp_max, problems[i][alp_req]);
//        cop_max = max(cop_max, problems[i][cop_req]);
//    }
//
//    for (int j = 0; j < problems.size(); ++j)
//    {
//        swap(problems[0], problems[j]);
//
//        DFS(alp, cop, 0, problems, 0);
//
//        swap(problems[0], problems[j]);
//    }
//
//    return  minTimeAtAlpCop[alp_max][cop_max];
//}

#include <string>
#include <vector>
#include <algorithm>

enum { alp_req, cop_req, alp_rwd, cop_rwd, cost };

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int alp_max = 0, cop_max = 0;
    vector<vector<int>> minTimeAtAlpCop(151, vector<int>(151, 2147483647));

    sort(problems.begin(), problems.end(), [&alp_max, &cop_max](vector<int>& a, vector<int>& b) {
        return a[alp_req] + a[cop_req] < b[alp_req] + b[cop_req];
        });

    for (vector<int>& problem : problems)
    {
        alp_max = max(alp_max, problem[alp_req]);
        cop_max = max(cop_max, problem[cop_req]);
    }

    for (int a = alp; a <= alp_max; ++a)
    {
        for (int c = cop; c <= cop_max; ++c)
        {
            minTimeAtAlpCop[a][c] = max(0, a - alp) + max(0, c - cop);
        }
    }

    for (int a = min(alp, alp_max); a <= alp_max; ++a)
    {
        for (int c = min(cop, cop_max); c <= cop_max; ++c)
        {
            for (int i = 0; i < problems.size(); ++i)
            {
                if (problems[i][alp_req] > a || problems[i][cop_req] > c)
                {
                    continue;
                }
                else if (problems[i][alp_req] + problems[i][cop_req] > a + c)
                {
                    break;
                }

                int maximum = 0;
                if (problems[i][alp_rwd] > 0)
                {
                    maximum = max(maximum, (alp_max - a) / problems[i][alp_rwd] + 1);
                }
                if (problems[i][cop_rwd] > 0)
                {
                    maximum = max(maximum, (cop_max - c) / problems[i][cop_rwd] + 1);
                }

                for (int j = 1; j <= maximum; ++j)
                {
                    int nextAlp = min(alp_max, a + problems[i][alp_rwd] * j);
                    int nextCop = min(cop_max, c + problems[i][cop_rwd] * j);
                    int nextTime = minTimeAtAlpCop[a][c] + problems[i][cost] * j;

                    if (minTimeAtAlpCop[nextAlp][nextCop] <= nextTime)
                    {
                        break;
                    }

                    minTimeAtAlpCop[nextAlp][nextCop] = nextTime;
                }
            }
        }
    }

    return minTimeAtAlpCop[alp_max][cop_max];
}

int main()
{
    solution(0, 0, { {0, 0, 2, 1, 2}, {4, 5, 3, 1, 2 }, {4, 11, 4, 0, 2 }, {10, 4, 0, 4, 2} });
}