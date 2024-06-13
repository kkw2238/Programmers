/*
    https://school.programmers.co.kr/learn/courses/30/lessons/250134
*/

#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<vector<bool>> rVisited, bVisited;
int minimum = 17;

bool isInside(const int x, const int y)
{
    return x >= 0 && x < rVisited[0].size() && y >= 0 && y < rVisited.size();
}

void DFS(int rx, int ry, int bx, int by, int turnCount, vector<vector<int>>& maze)
{
    if (rx == bx && ry == by)
    {
        return;
    }

    if (maze[ry][rx] == 3 && maze[by][bx] == 4)
    {
        minimum = min(turnCount, minimum);
    }
    else if (maze[ry][rx] == 3)
    {
        for (int bdir = 0; bdir < 4; ++bdir)
        {
            int nbx = bx + dx[bdir];
            int nby = by + dy[bdir];

            if (!isInside(nbx, nby) || bVisited[nby][nbx] || maze[nby][nbx] == 5)
            {
                continue;
            }

            bVisited[nby][nbx] = true;
            DFS(rx, ry, nbx, nby, turnCount + 1, maze);
            bVisited[nby][nbx] = false;
        }
    }
    else if (maze[by][bx] == 4)
    {
        for (int rdir = 0; rdir < 4; ++rdir)
        {
            int nrx = rx + dx[rdir];
            int nry = ry + dy[rdir];

            if (!isInside(nrx, nry) || rVisited[nry][nrx] || maze[nry][nrx] == 5)
            {
                continue;
            }

            rVisited[nry][nrx] = true;
            DFS(nrx, nry, bx, by, turnCount + 1, maze);
            rVisited[nry][nrx] = false;
        }
    }
    else
    {
        for (int rdir = 0; rdir < 4; ++rdir)
        {
            int nrx = rx + dx[rdir];
            int nry = ry + dy[rdir];

            if (!isInside(nrx, nry) || rVisited[nry][nrx])
            {
                continue;
            }

            for (int bdir = 0; bdir < 4; ++bdir)
            {
                int nbx = bx + dx[bdir];
                int nby = by + dy[bdir];

                if (!isInside(nbx, nby) || bVisited[nby][nbx] || (nbx == rx && nby == ry && nrx == bx && nry == by))
                {
                    continue;
                }

                bVisited[nby][nbx] = true;
                rVisited[nry][nrx] = true;

                DFS(nrx, nry, nbx, nby, turnCount + 1, maze);

                bVisited[nby][nbx] = false;
                rVisited[nry][nrx] = false;
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    int rsx, rsy;
    int bsx, bsy;

    rVisited = vector<vector<bool>>(maze.size(), vector<bool>(maze[0].size(), false));
    bVisited = vector<vector<bool>>(maze.size(), vector<bool>(maze[0].size(), false));

    for (int y = 0; y < maze.size(); ++y)
    {
        for (int x = 0; x < maze[y].size(); ++x)
        {
            switch (maze[y][x])
            {
            case 1:
                rsx = x;
                rsy = y;
                rVisited[y][x] = true;
                break;
            case 2:
                bsx = x;
                bsy = y;
                bVisited[y][x] = true;
                break;
            case 5:
                rVisited[y][x] = true;
                bVisited[y][x] = true;
                break;
            }
        }
    }

    DFS(rsx, rsy, bsx, bsy, 0, maze);

    if (minimum == 17)
    {
        return 0;
    }
    return minimum;
}