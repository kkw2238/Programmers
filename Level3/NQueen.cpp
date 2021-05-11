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
    1. BFS�� queue�� ü����(vector<vector<bool>>�� �־��ָ�?
		=> ���� vector bool �־��� �ʿ䰡 ������?
			-> y���� vector.size()�� �Ǻ�
			-> x�� ��ġ�� �˸�ȴ�.

	2. ������ ���� ���� ���� �ǰ��� ���
		=> [y1][x1], [y2][x2] ������ 
			a. x1 == x2 ( �������� ���� ��ġ )
			b. |x1 - x2| == |y1 - y2|�� ���( �밢�� )

	3. while(!queue.empty())
		board = queue.top()		
		queue.pop

		if(board.size() == N)
			++anwer
			continue
		
		vector<bool> line	// ���� �߰�
		for(i = 0 => N)
			line[i] = true; // Queen ��ġ	
			for(vector<bool> boardline : board)
				if x1 == x2
				else if |x1 - x2| == |y1 - y2|
				else queue.add(line)
			
			line[i] = false; // Queen ����

*/