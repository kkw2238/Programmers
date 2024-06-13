#include <string>
#include <vector>
#include <queue>

using namespace std;

const int ABS(int x)
{
	return x < 0 ? -x : x;
}

const bool IsRightQueens(vector<int>& queens, int x)
{
	int y = queens.size() - 1;

	for (int i = 0; i < y; ++i)
	{
		if (queens[i] == x)
		{
			return false;
		}
		else if (ABS(y - i) == ABS(x - queens[i]))
		{
			return false;
		}
	}

	return true;
}

queue<vector<int>> InitializeBoards(int n)
{
	queue<vector<int>> boards;

	for (int i = 0; i < n; ++i)
	{
		vector<int> board(1, i);
		boards.emplace(board);
	}

	return boards;
}

int solution(int n) {
    int answer = 0;
	queue<vector<int>> boards = InitializeBoards(n);

	while (!boards.empty())
	{
		vector<int> board = boards.front();
		boards.pop();

		if (board.size() == n)
		{
			++answer;
			continue;
		}

		board.push_back(0);

		for (int i = 0; i < n; ++i)
		{
			if (IsRightQueens(board, i))
			{
				board[board.size() - 1] = i;
				boards.push(board);
			}
		}
	}

    return answer;
}

int main()
{
	solution(4);
}

/*
    1. BFS로 queue에 체스판(vector<vector<bool>>을 넣어주면?
		=> 굳이 vector bool 넣어줄 필요가 있을까?
			-> y축은 vector.size()로 판별
			-> x축 위치만 알면된다.

	2. 서로의 공격 가능 여부 판가름 방법
		=> [y1][x1], [y2][x2] 있을때 
			a. x1 == x2 ( 수직으로 같은 위치 )
			b. |x1 - x2| == |y1 - y2|인 경우( 대각선 )

	3. while(!queue.empty())
		board = queue.top()		
		queue.pop

		if(board.size() == N)
			++anwer
			continue
		
		vector<bool> line	// 라인 추가
		for(i = 0 => N)
			line[i] = true; // Queen 배치	
			for(vector<bool> boardline : board)
				if x1 == x2
				else if |x1 - x2| == |y1 - y2|
				else queue.add(line)
			
			line[i] = false; // Queen 제거

*/