/*
    https://school.programmers.co.kr/learn/courses/30/lessons/169199
*/
#include <string>
#include <vector>

using namespace std;

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, -1, 0, 1 };

vector<vector<int>> footPrintCount;

const bool isInside(int x, int y)
{
    return x >= 0 && x < footPrintCount[0].size() && y >= 0 && y < footPrintCount.size();
}

pair<int, int> moveBot(const vector<string>& board, int x, int y, int dir)
{
    while (isInside(x, y) && board[y][x] != 'D')
    {
        x += dirX[dir];
        y += dirY[dir];
    }

    return pair(y - dirY[dir], x - dirX[dir]);
}

void DFS(const vector<string>& board, int x, int y)
{
    if (board[y][x] == 'G')
    {
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        pair<int, int> dest = moveBot(board, x, y, i);

        if (footPrintCount[dest.first][dest.second] == -1 || footPrintCount[dest.first][dest.second] > (footPrintCount[y][x] + 1))
        {
            footPrintCount[dest.first][dest.second] = footPrintCount[y][x] + 1;
            DFS(board, dest.second, dest.first);
        }
    }
}

int solution(vector<string> board) {
    pair<int, int> startPos(-1, -1), endPos(-1, -1);
    footPrintCount = vector<vector<int>>(board.size(), vector<int>(board[0].size(), -1));

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            switch (board[y][x])
            {
            case 'G':
                endPos = pair(y, x);
                break;
            case 'R':
                startPos = pair(y, x);
                break;
            }
        }

        if (startPos.first != -1 && endPos.first != -1)
        {
            break;
        }
    }

    footPrintCount[startPos.first][startPos.second] = 0;
    DFS(board, startPos.second, startPos.first);

    return footPrintCount[endPos.first][endPos.second];
}