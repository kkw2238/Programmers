/*
    https://school.programmers.co.kr/learn/courses/30/lessons/159993
*/
#include <string>
#include <vector>

using namespace std;

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, -1, 0, 1 };

int maximumCount = 0;
vector<vector<int>> footPrintcount;

void DFS(const vector<string>& maps, int x, int y, const char destChar)
{
    if (maps[y][x] == destChar)
    {
        return ;
    }

    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if ((nextX >= 0 && nextX < maps[0].size()) && nextY >= 0 && nextY < maps.size())
        {
            if (maps[nextY][nextX] == 'X')
            {
                continue;
            }

            if (footPrintcount[nextY][nextX] > (footPrintcount[y][x] + 1) || footPrintcount[nextY][nextX] == -1)
            {
                footPrintcount[nextY][nextX] = footPrintcount[y][x] + 1;
                DFS(maps, x + dirX[i], y + dirY[i], destChar);
            }
        }
    }
}

void findTarget(const vector<string>& maps, int x, int y, const char destChar)
{
    footPrintcount = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), -1));
    footPrintcount[y][x] = 0;

    DFS(maps, x, y, destChar);
}

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> startPos, leverPos, endPos;

    for (int y = 0; y < maps.size(); ++y)
    {
        for (int x = 0; x < maps[y].size(); ++x)
        {
            switch (maps[y][x])
            {
            case 'O':
                ++maximumCount;
                break;
            case 'L':
                leverPos = pair(y, x);
                break;
            case 'S':
                startPos = pair(y, x);
                break;
            case 'E':
                endPos = pair(y, x);
                break;
            }
        }
    }

    findTarget(maps, startPos.second, startPos.first, 'L');
    answer += footPrintcount[leverPos.first][leverPos.second];

    if (footPrintcount[leverPos.first][leverPos.second] == -1)
    {
        return -1;
    }

    findTarget(maps, leverPos.second, leverPos.first, 'E');
    answer += footPrintcount[endPos.first][endPos.second];
 
    if (footPrintcount[endPos.first][endPos.second] == -1)
    {
        return -1;
    }

    return answer;
}