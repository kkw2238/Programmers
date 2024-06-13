#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    for (int y = 1; y < board.size(); ++y)
    {
        for (int x = 1; x < board[y].size(); ++x)
        {
            if (board[y][x] > 0)
            {
                /* 
                    왼쪽 위 대각선의 숫자를 참조 => 최소 값 + 1
                    1 1 인 경우 -> 1 1 로 변환
                    1 1           1 2

                    1 1 1 인 경우 ->1 1 2
                    1 1 1           1 2 2
                    1 1 1           1 2 3
                */
                board[y][x] = min(board[y][x - 1], min(board[y - 1][x], board[y - 1][x - 1])) + 1;

                if (board[y][x] > answer)
                {
                    answer = board[y][x];
                }
            }
        }
    }

    return answer * answer;
}


/* 예전 코드
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    for (int i = 1; i < board.size(); ++i) {
        for (int j = 1; j < board[i].size(); ++j) {
            if (board[i][j] > 0) {
				board[i][j] = min(min(board[i - 1][j], board[i][j - 1]), board[i - 1][j - 1]) + 1;
				answer = board[i][j] > answer ? board[i][j] : answer;
            }
        }
    }

	if (answer == 0)
		answer = board[0][0];

    return answer * answer;
}
*/