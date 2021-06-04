/*
	https://programmers.co.kr/learn/courses/30/lessons/17679
*/

#include <string>
#include <vector>

using namespace std;

const bool Is4Block(const string blocks)
{
    return (blocks[0] == blocks[1]) && (blocks[2] == blocks[3]) && (blocks[0] == blocks[2]);
}

vector<vector<int>> blockCount;

vector<string> TransposeBoard(vector<string> board)
{
    vector<string> transposedBord(board[0].length(), string(board.size(), ' '));

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            transposedBord[x][y] = board[y][x];
        }
    }

    return transposedBord;
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int finded4blocks = -1;

    const int X_OFFSET[4] = { 0, 0, 1, 1 };
    const int Y_OFFSET[4] = { 0, 1, 0, 1 };

    board = TransposeBoard(board);
    blockCount = vector<vector<int>>(n, vector<int>(m, 0));

    while (finded4blocks != 0)
    {
        for (int x = 0; x < board.size() - 2; ++x)
        {
            for (int y = 0; y < board[x].size() - 2; ++y)
            {
                if (board[x][y] == ' ')
                {
                    continue;
                }

                string str = "";
                for (int i = 0; i < 4; ++i)
                {
                    str += board[x + X_OFFSET[i]][y + Y_OFFSET[i]];
                }
            }
        }
    }

    return answer;
}