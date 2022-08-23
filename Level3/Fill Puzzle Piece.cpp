/*
	https://programmers.co.kr/learn/courses/30/lessons/84021?language=cpp
*/

#include <vector>
#include <algorithm>

using namespace std;

using Point = pair<int, int>;
enum TYPE { EMPTY, BUMP };

Point operator+(const Point& a, const Point& b)
{
	return Point(a.first + b.first, a.second + b.second);
}

class Piece {
public:
	Piece(Point newoffset) : offset(Point(-newoffset.first, -newoffset.second))
	{ }

	void MakePiece(vector<vector<int>>& table, Point index, const int type)
	{
		if (index.first < 0 || index.first >= table.size() || index.second < 0 || index.second >= table[0].size())
		{
			return;
		}

		
		if (table[index.first][index.second] == type)
		{
			// ��� ������ �ֻ�� ���� ��ǥ �������� �ű��.
			bumps.emplace_back(index + offset);
			// �ߺ����� ó������ �ʰԲ� board or table�� �޲۴�.
			table[index.first][index.second] = 1 - type;

			// DFS�� �̿��Ͽ� Piece�� Ž���Ѵ�.
			MakePiece(table, Point(index.first + 1, index.second), type);
			MakePiece(table, Point(index.first - 1, index.second), type);
			MakePiece(table, Point(index.first, index.second + 1), type);
			MakePiece(table, Point(index.first, index.second - 1), type);
		}
		
		return;
	}

	const bool operator==(const Piece& other) const
	{
		// Ȩ�� ������ ������ �ٸ� ��� ���� �ʴ� ������� ����
		if (other.bumps.size() != bumps.size())
		{
			return false;
		}

		for (int index = 0; index < bumps.size(); ++index)
		{
			/*
				�� ������ ��ġ�� ���� �ٸ� ��� false ��ȯ 
					=>	�� ������ ���������� ������ �ֻ�� ���� index�̸�, 
						������ �˰������ �̿��߱⿡ index�� ������ ������ ��ġ���߸� �Ѵ�.
			 */
			if (bumps[index].first != other.bumps[index].first || bumps[index].second != other.bumps[index].second)
			{
				return false;
			}
		}

		return true;
	}
public:
	vector<Point> bumps;
	Point offset;
};

vector<Piece> GetPieces(vector<vector<int>> table, const int type)
{
	vector<Piece> pieces;

	for (int y = 0; y < table.size(); ++y)
	{
		for (int x = 0; x < table.size(); ++x)
		{
			// Ȩ or ������ ��� �ش� �ε����� �������� ������ ����� ����
			if (table[y][x] == type)
			{
				Piece piece(Point(y, x));

				piece.MakePiece(table, Point(y, x), type);
				pieces.emplace_back(piece);
			}
		}
	}
	
	return pieces;
}

void RotateBoard(vector<vector<int>>& game_board)
{
	// ���Ӻ��带 ȸ���ϱ� �� �ӽ� ����
	vector<vector<int>> tmp_Board = game_board;

	for (int y = 0; y < tmp_Board.size(); ++y)
	{
		for (int x = 0; x < tmp_Board[y].size(); ++x)
		{
			// ���Ӻ��带 ȸ��
			game_board[x][tmp_Board.size() - y - 1] = tmp_Board[y][x];
		}
	}
}

int FindMatchPiece(vector<Piece>& board_Pieces, vector<Piece>& puzzle_Pieces, vector<vector<int>>& game_board)
{
	int result = 0;

	for (int i = 0; i < board_Pieces.size(); ++i)
	{
		// puzzle ������ ��ġ�ϴ� game_board Ȩ�� Ž��
		auto iter = find(puzzle_Pieces.begin(), puzzle_Pieces.end(), board_Pieces[i]);

		// ������ ���
		if (iter != puzzle_Pieces.end())
		{
			vector<Point> bumps = board_Pieces[i].bumps;

			// game_board�� Ȩ�� �޲۴�.
			for (int j = 0; j < bumps.size(); ++j)
			{
				game_board[bumps[j].first - board_Pieces[i].offset.first][bumps[j].second - board_Pieces[i].offset.second] = BUMP;
			}

			result += bumps.size();

			// �ߺ� ó���� ���� ���� ����
			board_Pieces.erase(board_Pieces.begin() + i);
			puzzle_Pieces.erase(iter);
			--i;
		}
	}
	
	return result;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;

	// ���� ������ �з�
	vector<Piece> puzzle_Pieces = GetPieces(table, BUMP);

	for (int i = 0; i < 4; ++i) 
	{
		// ���� ���Ӻ��� ���¿� ���� ���� �������� �з�
		vector<Piece> game_board_Pieces = GetPieces(game_board, EMPTY);

		answer += FindMatchPiece(game_board_Pieces, puzzle_Pieces, game_board);

		// ���带 -90�� ȸ��
		RotateBoard(game_board);
	}

    return answer;
}