#include <iostream>
#include <vector>
#include <queue>

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

int main() {
    vector<vector<int>> board = { 
		{0,0,1,1},
		{1,1,1,1}
    };
    cout << solution(board);
}