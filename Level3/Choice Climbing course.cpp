/*
	https://school.programmers.co.kr/learn/courses/30/lessons/118669
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer{ 100000001 ,100000001 };
    vector<vector<int>> path(n + 1, vector<int>(n + 1, -100000001));

    for (vector<int>& p : paths)
    {
        path[p[0]][p[1]] = p[2];
        path[p[1]][p[0]] = p[2];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int m = 1; m <= n; ++m)
            {
                path[j][m] = max(path[j][m], max(path[j][i], path[i][m]));
            }
        }
    }

    for (int g : gates)
    {
        for (int s : summits)
        {
            if (path[g][s] < answer[1])
            {
                answer = { g, path[g][s] };
            }
            else if (path[g][s] == answer[1])
            {
                answer[0] = min(answer[0], g);
            }
        }
    }

    return answer;
}

int main()
{
    solution(6, { {1,2,3}, {2,3,5}, {2,4,2}, {2,5,4}, {3,4,4}, {4,5,3}, {4,6,1}, {5,6,1} }, { 1,3 }, { 5 });
}