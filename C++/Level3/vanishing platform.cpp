/*
	https://school.programmers.co.kr/learn/courses/30/lessons/92345
*/

//#include <vector>
//
//using namespace std;
//
//int dirX[4]{ -1, 1, 0, 0 };
//int dirY[4]{ 0, 0, -1, 1 };
//
//int width = 0;
//int height = 0;
//int maximum = 0;
//
//bool isAbleMove(int x, int y)
//{
//    return x >= 0 && x < width && y >= 0 && y < height;
//}
//
//void DFS(vector<vector<int>>& board, int ax, int ay, int bx, int by, int mCount)
//{
//    if (board[ay][ax] == 0 || board[by][bx] == 0)
//    {
//        return;
//    }
//    
//    
//    for (int i = 0; i < 4; ++i)
//    {
//        int nextAX = ax + dirX[i];
//        int nextAY = ay + dirY[i];
//
//        board[ay][ax] = 0;
//        if (!isAbleMove(nextAX, nextAY) || board[nextAY][nextAX] == 0)
//        {
//            continue;
//        }
//    
//        for (int j = 0; j < 4; ++j)
//        {
//            int nextBX = bx + dirX[j];
//            int nextBY = by + dirY[j];
//
//            if (!isAbleMove(nextBX, nextBY) || board[nextBY][nextBX] == 0)
//            {
//                continue;
//            }
//            else if (board[by][bx] == 0)
//            {
//                break;
//            }
//
//            board[by][bx] = 0;
//            DFS(board, nextAX, nextAY, nextBX, nextBY, mCount + 1);
//        }
//    }
//    board[ay][ax] = 1;
//    board[by][bx] = 1;
//
//    maximum = max(maximum, mCount);
//}
//
//int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
//    width = board[0].size();
//    height = board.size();
//
//    DFS(board, aloc[1], aloc[0], bloc[1], bloc[0], 0);
//
//    return maximum;
//}

/*
    [
    [1, 1, 1, 0], 
    [1, 1, 0, 1], 
    [1, 0, 1, 1], 
    [0, 1, 1, 1]]
*/

#include <iostream>
#include <vector>

using namespace std;

int width = 0, height = 0;
int aWinCount = 0, maximumTurn = 0;
bool isLink = false;

int dirX[4]{ -1, 1, 0, 0 };
int dirY[4]{ 0, 0, -1, 1 };

vector<vector<int>> footPrint;

bool isInside(int x, int y)
{
    return x >= 0 && x < width && y >= 0 && y < height;
}

vector<int> getAbleMoveIndex(vector<vector<int>>& board, int x, int y)
{
    vector<int> result;

    for (int i = 0; i < 4; ++i)
    {
        int nax = x + dirX[i];
        int nay = y + dirY[i];

        if (isInside(nax, nay) && footPrint[nay][nax] == 1 && board[nay][nax] == 1)
        {
            result.push_back(i);
        }
    }

    return result;
}

int Play(vector<vector<int>>& board, int ax, int ay, int bx, int by, int moveCount, bool aTurn)
{
    vector<int> ableIndex = getAbleMoveIndex(board, ax, ay);

    if (ableIndex.empty())
    {
        return moveCount;
    }
    else if (ax == bx && ay == by)
    {
        return moveCount + 1;
    }

    footPrint[ay][ax] = 0;
    
    int result = moveCount;
    bool isWin = false;

    for (int i : ableIndex)
    {
        int nx = ax + dirX[i];
        int ny = ay + dirY[i];

        int dfsResult = Play(board, bx, by, nx, ny, moveCount + 1, !aTurn);
        
        if (dfsResult % 2 == moveCount % 2)
        {
            if (result % 2 == dfsResult % 2)
            {
                result = min(result, dfsResult);
            }
            else
            {
                result = dfsResult;
            }
        }
        else
        {
            result = max(result, dfsResult);
        }
        
    }
    footPrint[ay][ax] = 1;
    
    return result + 1;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    width = board[0].size();
    height = board.size();

    footPrint = vector<vector<int>>(height, vector<int>(width, 1));

    return Play(board, aloc[1], aloc[0], bloc[1], bloc[0], 0, true);
}

/*
    
void DFS(vector<vector<int>>& board, int ax, int ay, int bx, int by, int turnCount, bool aTurn)
{
    vector<int> ableAIndex = getAbleMoveIndex(board, ax, ay);
    
    if (ax == bx && ay == by)
    {
        if (aTurn && !ableAIndex.empty())
        {
            ++aWinCount;
        }
        isLink = true;
        return;
    }
    else if (ableAIndex.empty())
    {
        if (!aTurn)
        {
            ++aWinCount;
        }

        maximumTurn = max(maximumTurn, turnCount);
        return;
    }
    
    footPrint[ay][ax] = 0;

    for (int i : ableAIndex)
    {
        DFS(board, bx, by, ax + dirX[i], ay + dirY[i], turnCount + 1, !aTurn);
    }

    footPrint[ay][ax] = 1;
}
*/