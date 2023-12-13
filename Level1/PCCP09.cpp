/*
	https://school.programmers.co.kr/learn/courses/30/lessons/250125
*/

#include <string>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool isInside(int x, int y, vector<vector<string>>& board)
{
    return x >= 0 && x < board[0].size() && y >= 0 && y < board.size();
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    for (int i = 0; i < 4; ++i)
    {
        int nx = w + dx[i];
        int ny = h + dy[i];

        if (!isInside(nx, ny, board))
        {
            continue;
        }

        if (board[ny][nx] == board[h][w])
        {
            ++answer;
        }
    }
    
    return answer;
}