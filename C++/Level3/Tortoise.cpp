/*
	https://programmers.co.kr/learn/courses/30/lessons/42898
*/
#include <vector>

using namespace std;

const int PUDDLE = -1;
const int DIVISION_VAL = 1000000007;
static int LimitX, LimitY;

const bool IsAbleMoveDown(const int yPos) {
	return yPos != LimitY;
}

const bool IsAbleMoveRight(const int xPos) {
	return xPos != LimitX;
}

const vector<vector<int>> MakeBoard(int xSize, int ySize, const vector<vector<int>>& puddles) {
	LimitX = xSize - 1; LimitY = ySize - 1;

	vector<vector<int>> board(ySize, vector<int>(xSize, 0));

	for (const vector<int>& puddle : puddles)
		board[puddle[1] - 1][puddle[0] - 1] = PUDDLE;

	board[0][0] = 1;
	return board;
}

void FillTheBoardHorizen(const int nowYPos, vector<vector<int>>& board) {
	const bool isAbleMoveDown = IsAbleMoveDown(nowYPos);

	for (int x = 0; x < board[nowYPos].size(); ++x) {
		const bool isAbleMoveRight = IsAbleMoveRight(x);

		if (board[nowYPos][x] == PUDDLE) continue;

		if (isAbleMoveRight && board[nowYPos][x + 1] != PUDDLE)
			board[nowYPos][x + 1] = (board[nowYPos][x + 1] + board[nowYPos][x]) % DIVISION_VAL;
		if (isAbleMoveDown && board[nowYPos + 1][x] != PUDDLE)
			board[nowYPos + 1][x] = (board[nowYPos + 1][x] + board[nowYPos][x]) % DIVISION_VAL;
	}
}

int solution(int m, int n, vector<vector<int>> puddles) {
	vector<vector<int>> board = MakeBoard(m, n, puddles);

	for (int y = 0; y < n; ++y)  FillTheBoardHorizen(y, board);

	return board[LimitY][LimitX] % DIVISION_VAL;
}