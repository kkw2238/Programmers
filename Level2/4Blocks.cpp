/*
	https://programmers.co.kr/learn/courses/30/lessons/17679
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> blockMarker;

const int X_OFFSET[4] = { 0, 0, 1, 1 };
const int Y_OFFSET[4] = { 0, 1, 0, 1 };

// Board를 전치행렬 화하여 블럭을 지울경우 알아서 내려오도록 변형
vector<string> TransposeBoard(vector<string> board)
{
    vector<string> transposedBord(board[0].length(), string(board.size(), ' '));

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            // 왼쪽 최상단이 0,0 이 아닌 왼쪽 최하단이 0,0 으로 변환
            transposedBord[x][y] = board[board.size() - ( y + 1 )][x];
        }
    }

    return transposedBord;
}

const bool Is4Blocks(const vector<string>& board, const int x, const int y)
{
    for (int i = 1; i < 4; ++i)
    {
        // 4블럭인지 여부 확인
        if (board[x][y] != board[x + X_OFFSET[i]][y + Y_OFFSET[i]])
        {
            return false;
        }
    }

    return true;
}

void Marking4Blocks(const int x, const int y)
{
    // 4Blocks의 인덱스를 blockMarker에서 마킹 
    for (int i = 0; i < 4; ++i)
    {
        blockMarker[x + X_OFFSET[i]][y + Y_OFFSET[i]] = true;
    }
}

int Erased4Blocks(vector<string>& board)
{
    int erasedBlocks = 0;

    for (int x = 0; x < board.size(); ++x)
    {
        for (int y = board[x].size() - 1; y >= 0; --y)
        {
            // 해당 인덱스가 4block의 내부인 경우
            if (blockMarker[x][y])
            {
                // 해당 문자열을 지우고 맨 뒤에 ' '를 추가 -> Is4Block 오류 방지
                board[x].erase(y, 1);
                board[x].push_back(' ');
                ++erasedBlocks;
            }
        }
    }

    return erasedBlocks;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int finded4blocks = -1;

    board = TransposeBoard(board);

    // 찾은 4blocks가 없을때까지 반복
    while (finded4blocks != 0)
    {
        // blockMarker 초기화
        blockMarker = vector<vector<bool>>(n, vector<bool>(m, 0));
    
        for (int x = 0; x <= board.size() - 2; ++x)
        {
            for (int y = 0; y <= board[x].size() - 2; ++y)
            {
                if (board[x][y] == ' ')
                {
                    continue;
                }

                if (Is4Blocks(board, x, y))
                {
                    Marking4Blocks(x, y);
                }
            }
        }

        finded4blocks = Erased4Blocks(board);
        answer += finded4blocks;
    }

    return answer;
}