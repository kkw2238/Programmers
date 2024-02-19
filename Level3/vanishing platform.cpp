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


#include <vector>

using namespace std;

int width = 0, height = 0;
int aWinCount = 0, bWinCount = 0;
int aWinMoveCount = 0, bWinMoveCount = 0;

int dirX[4]{ -1, 1, 0, 0 };
int dirY[4]{ 0, 0, -1, 1 };

vector<vector<int>> footPrint;

void DFS(vector<vector<int>>& board, int ax, int ay, int aMoveCount, int bx, int by, int bMoveCount)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {

        }
    }

}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    width = board[0].size();
    height = board.size();

    footPrint = vector<vector<int>>(height, vector<int>(width, 0));

    DFS(board, aloc[0], aloc[1], 0, bloc[0], bloc[1], 0);

    return maximum;
}

int main()
{
    solution({ {1, 1, 1},{1, 1, 1 }, {1,1,1} } , { 1, 0 }, { 1, 2 });
}