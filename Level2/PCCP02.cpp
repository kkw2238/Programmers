/*
    https://school.programmers.co.kr/learn/courses/30/lessons/250136
*/

#include <vector>
#include <set>

using namespace std;

vector<vector<int*>> roots;
vector<vector<bool>> visited;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int DFS(int x, int y, int& total, vector<vector<int>>& land)
{
    int result = 1;

    roots[y][x] = &total;
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < land[0].size() && ny >= 0 && ny < land.size())
        {
            if (!visited[ny][nx] && land[ny][nx] != 0)
            {
                result += DFS(nx, ny, total, land);
            }
        }
    }

    return result;
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    roots = vector<vector<int*>>(land.size(), vector<int*>(land[0].size(), nullptr));
    visited = vector<vector<bool>>(land.size(), vector<bool>(land[0].size(), false));

    for (int i = 0; i < land[0].size(); ++i)
    {
        set<int*> oils;
        int totalOil = 0;
        for (int j = 0; j < land.size(); ++j)
        {
            if (land[j][i] != 0)
            {
                if (!visited[j][i])
                {
                    land[j][i] = DFS(i, j, land[j][i], land);
                }
                oils.insert(roots[j][i]);
            }
        }

        for (int* root : oils)
        {
            totalOil += *root;
        }

        answer = max(answer, totalOil);
    }

    return answer;
}