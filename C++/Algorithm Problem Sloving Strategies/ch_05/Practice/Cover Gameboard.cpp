#include <vector>
#include <string>

using namespace std;

const int BLOCK_LENGTH = 2;
int block_count = 0;
int board_width, board_height;

vector<vector<int>> getBlock( int type)
{
	vector<vector<int>> block;

	switch (type)
	{
	case 0:
		block = {
			{1, 1}, 
			{1, 0} 
		};
		break;
	case 1:
		block = {
			{1, 1}, 
			{0, 1} 
		};
		break;
	case 2:
		block = {
			{0, 1},
			{1, 1}
		};
		break;
	case 3:
		block = {
			{1, 0},
			{1, 1}
		};
		break;
	}
	return block;
}

#include <iostream>
void drawBoard(vector<string> board)
{
	for (string line : board)
	{
		cout << line << '\n';
	}
	cout << '\n';
}

bool ableDropBlock(vector<string>& board, vector<vector<int>> block, int xPos, int yPos, int index)
{
	const char start = '0';
	for (int y = 0; y < BLOCK_LENGTH; ++y)
	{
		for (int x = 0; x < BLOCK_LENGTH; ++x)
		{
			if (board[yPos + y][xPos - 1 + x] != '.' && block[y][x] == 1)
			{
				return false;
			}
			else if(board[yPos + y][xPos - 1 + x] == '.' && block[y][x] == 1)
			{
				board[yPos + y][xPos - 1 + x] = start + index;
			}
		}
	}

	return true;
}

const int isComplete(const vector<string>& board)
{
	for (const string& s : board)
	{
		for (const char c : s)
		{
			if (c == '.')
			{
				return 0;
			}
		}
	}

	//drawBoard(board);
	return 1;
}

const bool isFail(vector<string> board, int yPos)
{
	for (char c : board[yPos - 1])
	{
		if (c == '.')
		{
			return true;
		}
	}
	return false;
}

int findAbleCombination(vector<string> board, int pos, int index)
{
	if (pos % board_width == 0)
	{
		++pos;
	}

	int result = 0;
	int yPos = pos / board_width;
	int xPos = pos % board_width;

	++block_count;

	if ((yPos > 0 && xPos == 1) && isFail(board, yPos))
	{
		return 0;
	}
	if (pos == (board_height - 1) * board_width - 1)
	{
		return isComplete(board);
	}
	
	
	for (int rotateCount = 0; rotateCount < 4; ++rotateCount)
	{
		vector<string> cpyBoard = board;
		vector<vector<int>> block = getBlock(rotateCount);

		if (ableDropBlock(cpyBoard, block, xPos, yPos, index))
		{
			result += findAbleCombination(cpyBoard, pos + 1, index + 1);
		}
	}
	
	result += findAbleCombination(board, pos + 1, index);
	
	return result;
}


const int coverType[4][3][2] = {
	{ {0,0}, {1,0}, {0,1} },
	{ {0,0}, {0,1}, {1,1} },
	{ {0,0}, {1,0}, {1,1} },
	{ {0,0}, {1,0}, {1,-1} }
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
		{
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1)
		{
			ok = false;
		}
	}

	return ok;
}

int cover(vector<vector<int>>& board) {
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == 0) 
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y == -1) 
		{
			break;
		}
	}
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; ++type)
	{
		if (set(board, y, x, type, 1))
		{
			ret += cover(board);
		}
		set(board, y, x, type, -1);
	}
	return ret;
}

int run(vector<string> board, int height, int width)
{
	vector<vector<int>> newBoard(board.size());
	board_width = width;
	board_height = height;

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == '#')
			{
				newBoard[i].push_back(0);
			}
			else
			{
				newBoard[i].push_back(1);
			}
		}
	}

	return cover(newBoard);
}

int main()
{
	cout << run({ 
		"##########",
		"#........#",
		"#........#",
		"#........#",
		"#........#",
		"#........#",
		"#........#",
		"##########",
		}, 8, 10) << '\n';
	cout << block_count << '\n';
}