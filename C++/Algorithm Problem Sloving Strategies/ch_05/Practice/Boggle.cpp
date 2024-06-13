#include <vector>
#include <string>

using namespace std;

const int X_OFFSET[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int Y_OFFSET[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

vector<vector<char>> checkBoard;

const bool isInBoard(const int pos)
{
	return pos >= 0 && pos < 5;
}

const bool hasWord(const vector<vector<char>>& board, const int x, const int y, const string word, const int index)
{
	if (index == word.length() - 1)
	{
		return true;
	}

	bool result = false;

	for (int i = 0; i < 8; ++i)
	{
		int nextX = X_OFFSET[i] + x;
		int nextY = Y_OFFSET[i] + y;

		if (isInBoard(nextX) && isInBoard(nextY))
		{
			if (board[nextY][nextX] == word[index + 1])
			{
				result |= hasWord(board, nextX, nextY, word, index + 1);
				checkBoard[nextY][nextX] = word[index + 1];
			}
		}
	}

	return result;
}

#include <iostream>

void DrawBoard(vector<vector<char>>& board)
{
	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			cout << board[y][x] << '\t';
		}

		cout << '\n';
	}
}

bool FindWord(const vector<vector<char>>& board, const string word)
{
	checkBoard = vector<vector<char>>(5, vector<char>(5, '.'));

	for (int y = 0; y < board.size(); ++y)
	{
		for (int x = 0; x < board[y].size(); ++x)
		{
			if (board[y][x] == word[0])
			{
				if (hasWord(board, x, y, word, 0))
				{
					checkBoard[y][x] = word[0];
					DrawBoard(checkBoard);

					return true;
				}
			}
		}
	}

	return false;
}

//int main()
//{
//	vector<vector<char>> board =
//	{
//		{ 'U', 'R', 'L', 'P', 'M' },
//		{ 'X', 'P', 'R', 'E', 'T' },
//		{ 'G', 'I', 'A', 'E', 'T' },
//		{ 'X', 'T', 'N', 'Z', 'Y' },
//		{ 'X', 'O', 'Q', 'R', 'S' }
//	};
//
//	FindWord(board, "PRETTY");
//	FindWord(board, "GIRL");
//	FindWord(board, "REPEAT");
//}