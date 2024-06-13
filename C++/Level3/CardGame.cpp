
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int FindStartIndex(const vector<vector<int>>& board, int boardXIndex) {
	for (int i = 0; i < board.size(); ++i) {
		if (board[i][boardXIndex] != -1)
			return i;
	}
	return 0;
}

int DistributeCard(const vector<int>& left, const vector<int>& right, vector<vector<int>>& board, int boardXIndex) {
	int yIndex = FindStartIndex(board, boardXIndex), xIndex = boardXIndex, score = 0;

	while (yIndex != left.size() && xIndex != right.size()) {
		board[yIndex][boardXIndex] = score;
		if (left[yIndex] > right[xIndex])
			score += right[xIndex++];
		else {
			board[yIndex++][boardXIndex + 1] = score;
		}
	}

	board[left.size()][boardXIndex] = score;
	return score;
}

int solution(vector<int> left, vector<int> right) {
	int answer = 0;

	vector<vector<int>> board(left.size() + 1, vector<int>(right.size() + 1, -1));
	answer = DistributeCard(left, right, board, 0);

	for (int i = 1; i < left.size(); ++i) {
		int tmpResult = DistributeCard(left, right, board, i);
	}
	sort(board[left.size()].begin(), board[right.size()].end());
	return *(board[left.size()].end() - 1);
}

int main() {
	vector<int> left = { 1, 1, 1, 1, 3 };
	vector<int> right = { 2, 3, 1, 1, 1 };
	cout << solution(left, right) << '\n';

	return 0;
}