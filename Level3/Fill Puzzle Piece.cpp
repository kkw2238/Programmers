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
			// 모든 정점을 최상단 좌측 좌표 기준으로 옮긴다.
			bumps.emplace_back(index + offset);
			// 중복으로 처리하지 않게끔 board or table을 메꾼다.
			table[index.first][index.second] = 1 - type;

			// DFS을 이용하여 Piece를 탐색한다.
			MakePiece(table, Point(index.first + 1, index.second), type);
			MakePiece(table, Point(index.first - 1, index.second), type);
			MakePiece(table, Point(index.first, index.second + 1), type);
			MakePiece(table, Point(index.first, index.second - 1), type);
		}
		
		return;
	}

	const bool operator==(const Piece& other) const
	{
		// 홈과 돌기의 개수가 다를 경우 맞지 않는 블럭으로 간주
		if (other.bumps.size() != bumps.size())
		{
			return false;
		}

		for (int index = 0; index < bumps.size(); ++index)
		{
			/*
				각 조각의 위치가 서로 다를 경우 false 반환 
					=>	각 퍼즐의 시작지점은 무조건 최상단 좌측 index이며, 
						동일한 알고리즘을 이용했기에 index가 같으면 동일한 위치여야만 한다.
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
			// 홈 or 돌기일 경우 해당 인덱스를 기점으로 조각을 만들어 저장
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
	// 게임보드를 회전하기 전 임시 저장
	vector<vector<int>> tmp_Board = game_board;

	for (int y = 0; y < tmp_Board.size(); ++y)
	{
		for (int x = 0; x < tmp_Board[y].size(); ++x)
		{
			// 게임보드를 회전
			game_board[x][tmp_Board.size() - y - 1] = tmp_Board[y][x];
		}
	}
}

int FindMatchPiece(vector<Piece>& board_Pieces, vector<Piece>& puzzle_Pieces, vector<vector<int>>& game_board)
{
	int result = 0;

	for (int i = 0; i < board_Pieces.size(); ++i)
	{
		// puzzle 조각과 일치하는 game_board 홈을 탐색
		auto iter = find(puzzle_Pieces.begin(), puzzle_Pieces.end(), board_Pieces[i]);

		// 존재할 경우
		if (iter != puzzle_Pieces.end())
		{
			vector<Point> bumps = board_Pieces[i].bumps;

			// game_board의 홈을 메꾼다.
			for (int j = 0; j < bumps.size(); ++j)
			{
				game_board[bumps[j].first - board_Pieces[i].offset.first][bumps[j].second - board_Pieces[i].offset.second] = BUMP;
			}

			result += bumps.size();

			// 중복 처리를 막기 위해 제거
			board_Pieces.erase(board_Pieces.begin() + i);
			puzzle_Pieces.erase(iter);
			--i;
		}
	}
	
	return result;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;

	// 퍼즐 조각을 분류
	vector<Piece> puzzle_Pieces = GetPieces(table, BUMP);

	for (int i = 0; i < 4; ++i) 
	{
		// 현재 게임보드 상태에 대한 퍼즐 조각들을 분류
		vector<Piece> game_board_Pieces = GetPieces(game_board, EMPTY);

		answer += FindMatchPiece(game_board_Pieces, puzzle_Pieces, game_board);

		// 보드를 -90도 회전
		RotateBoard(game_board);
	}

    return answer;
}