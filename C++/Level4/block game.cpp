/*
	https://school.programmers.co.kr/learn/courses/30/lessons/42894
*/

#include <string>
#include <vector>

using namespace std;

int offsetX[12][4] = {  { 0, 1, 2, 2 }, { 0, 1, 0, 0 }, {0, 0, 1, 2}, {0, 0, 0, -1 }, 
                        { 0, 1, 2, 0}, {0, 0, 0, 1}, {0, 0, -1, -2}, {0, 1, 1, 1},
                        {0, 0, -1, 1 }, {0, 0, 1, 0}, {0, 1, 2, 1}, {0, 0, -1, 0 } };

int offsetY[12][4] = { { 0, 0, 0, 1 }, { 0, 0, 1, 2 }, {0, 1, 1, 1}, {0, 1, 2, 2 },
                        { 0, 0, 0, 1 }, {0, 1, 2, 2}, {0, 1, 1, 1}, {0, 0, 1, 2},
                        {0, 1, 1, 1 }, {0, 1, 1, 2}, {0, 0, 0, 1}, {0, 1, 1, 2 } };

int voidPosX[12][2] = { { -99, -99 }, { -99, -99 }, { 1, 2 }, { -1, -1 },
                        { -99, -99 }, { 1, 1 }, { -2, -1 }, { -99, -99 },
                        { -1, 1 }, { -99, -99 }, { -99, -99 }, { -99, -99 } };

int voidPosY[12][2] = { { -99, -99 }, { -99, -99 }, { 0, 0 }, { 0, 1 },
                        { -99, -99 }, { 0, 1 }, { 0, 0 }, {-99, -99 },
                        { 0, 0 }, { -99, -99}, { -99, -99 }, { -99, -99 } };

bool isInside(int x, int y, int n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

int getType(vector<vector<int>>& board, vector<vector<int>>& checkBoard, int x, int y)
{
    for (int i = 0; i < 12; ++i)
    {
        int check = 0;
        for (int j = 0; j < 4; ++j)
        {
            int newX = x + offsetX[i][j];
            int newY = y + offsetY[i][j];

            if (!isInside(newX, newY, board.size()))
            {
                break;
            }
            else if(board[newY][newX] != board[y][x])
            { 
                break;
            }
            checkBoard[newY][newX] = -1;
            ++check;
        }

        if (check == 4)
        {
            checkBoard[y][x] = i + 1;
            return i + 1;
        }
    }

    return 0;
}

bool isAbleErase(vector<vector<int>>& checkBoard, int index, int x, int y, vector<int> topIndex)
{
    int type = checkBoard[y][x] - 1;

    if (voidPosX[type][0] == -99)
    {
        return false;
    }

    for (int i = 0; i < 2; ++i)
    {
        int nextX = x + voidPosX[type][i];
        int nextY = y + voidPosY[type][i];

        if (topIndex[nextX] != index || checkBoard[nextY][nextX] != 0)
        {
            return false;
        }
    }
    return true;
}

int findNextY(vector<vector<int>>& checkBoard, vector<vector<int>>& board, int x)
{
    for (int nextY = 0; nextY < board.size(); ++nextY)
    {
        if (checkBoard[nextY][x] != 0)
        {
            return board[nextY][x];
        }
    }

    return board.size();
}

void boardErase(vector<vector<int>>& board, vector<vector<int>>& checkBoard, vector<int>& topIndex, int index, int x, int y)
{
    int type = checkBoard[y][x] - 1;

    for (int i = 0; i < 4; ++i)
    {
        int nowX = x + offsetX[type][i];
        int nowY = y + offsetY[type][i];
        checkBoard[nowY][nowX] = 0;

        topIndex[nowX] = findNextY(checkBoard, board, nowX);
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> checkBoard(board.size(), vector<int>(board.size(), 0));
    vector<int> topPos(board.size(), 300);
    vector<bool> isBlock(board.size(), false);

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board.size(); ++x)
        {
            if (checkBoard[y][x] == 0 && board[y][x] != 0)
            {
                getType(board, checkBoard, x, y);
            }
            if (topPos[x] == 300 && checkBoard[y][x] != 0)
            {
                topPos[x] = board[y][x];
            }
        }
    }

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board.size(); ++x)
        {
            if (checkBoard[y][x] > 0 && isAbleErase(checkBoard, board[y][x], x, y, topPos))
            {
                boardErase(board, checkBoard, topPos, board[y][x], x, y);
                x = 0;
                y = 0;
                ++answer;
            }
        }
    }

    return answer;
}