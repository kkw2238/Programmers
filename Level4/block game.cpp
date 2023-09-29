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
            checkBoard[newY][newX] = i;
            ++check;
        }

        if (check == 4)
        {
            return i;
        }
    }

    return 0;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> checkBoard(board.size(), vector<int>(board.size(), 0));
    vector<int> topPos(board.size(), board.size());
    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board.size(); ++x)
        {
            if (board[y][x] != 0)
            {
                topPos[x] = min(y, topPos[x]);
            }
            if (checkBoard[y][x] == 0)
            {
                getType(board, checkBoard, x, y);
            }
        }
    }

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board.size(); ++x)
        {
            if (checkBoard[y][x] != 0)
            {

            }
        }
    }

    return answer;
}