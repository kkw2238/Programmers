/*
	https://school.programmers.co.kr/learn/courses/30/lessons/60063
*/

//vector<vector<int>> footPrint[4];
//int minimum = INT_MAX;
//int width = 0, height = 0;
//int otherX[4]{ 1, 0, -1, 0 };
//int otherY[4]{ 0, 1, 0, -1 };
//
//bool isAbleMove(const vector<vector<int>>& board, int x, int y, int type)
//{
//    if (x * 2 + otherX[type] < 0 || y * 2 + otherY[type] < 0)
//    {
//        return false;
//    }
//    if ((x * 2 + otherX[type]) >= (width * 2 - 1) || (y * 2 + otherY[type]) >= (height * 2 - 1))
//    {
//        return false;
//    }
//
//    if (board[y + otherY[type]][x + otherX[type]] == 1 || board[y][x] == 1)
//    {
//        return false;
//    }
//
//    return true;
//}
//
//bool isAbleRotate(const vector<vector<int>>& board, int x, int y, int type)
//{
//    return isAbleMove(board, x + otherX[(type + 1) % 4], y + otherY[(type + 1) % 4], type);
//}
//
//void DFS(const vector<vector<int>>& board, int x, int y, int type, int footCount, bool rotAble)
//{
//    if (footPrint[type][y][x] < footCount)
//    {
//        return;
//    }
//    else
//    {
//        footPrint[type][y][x] = footCount;
//    }
//
//    if ((x == width - 1 && y == height - 1) || (x + otherX[type] == width - 1 && y + otherY[type] == height - 1))
//    {
//        minimum = min(minimum, footCount);
//        return;
//    }
//
//    for (int i = 0; i < 4; ++i)
//    {
//        if (isAbleMove(board, x + otherX[i], y + otherY[i], type))
//        {
//            DFS(board, x + otherX[i], y + otherY[i], type, footCount + 1, true);
//        }
//    }
//
//    if (isAbleRotate(board, x, y, (type + 5) % 4) && rotAble)
//    {
//        DFS(board, x, y, (type + 5) % 4, footCount + 1, false);
//        DFS(board, x + otherX[type], y + otherY[type], (type + 3) % 4, footCount + 1, false);
//    }
//
//    if (isAbleRotate(board, x, y, (type + 3) % 4) && rotAble)
//    {
//        DFS(board, x, y, (type + 3) % 4, footCount + 1, false);
//        DFS(board, x + otherX[type], y + otherY[type], (type + 5) % 4, footCount + 1, false);
//    }
//}
//
//int solution(vector<vector<int>> board) {
//    int answer = 0;
//    height = board.size();
//    width = board[0].size();
//    
//    for (int i = 0; i < 4; ++i)
//    {
//        footPrint[i] = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 100000));
//    }
//    DFS(board, 1, 0, 2, 0, true);
//
//    return minimum;
//}


#include <queue>
#include <vector>

using namespace std;

int minimum = 100000;
int width = 0, height = 0;
int otherX[4]{ 1, 0, -1, 0 };
int otherY[4]{ 0, 1, 0, -1 };

struct node {
    int x, y, type, count;
};

bool isAbleMove(const vector<vector<int>>& board, int x, int y, int type)
{
    if (x * 2 + otherX[type] < 0 || y * 2 + otherY[type] < 0)
    {
        return false;
    }
    if ((x * 2 + otherX[type]) >= (width * 2 - 1) || (y * 2 + otherY[type]) >= (height * 2 - 1))
    {
        return false;
    }

    if (board[y + otherY[type]][x + otherX[type]] == 1 || board[y][x] == 1)
    {
        return false;
    }

    return true;
}

bool isAbleRotate(const vector<vector<int>>& board, int x, int y, int type)
{
    return isAbleMove(board, x + otherX[(type + 1) % 4], y + otherY[(type + 1) % 4], type);
}

void BFS(const vector<vector<int>>& board, int x, int y, int type)
{
    bool footPrint[2][100][100] { false };
    queue<node> q;

    q.push({ x, y, type, 0 });

    while (!q.empty())
    {
        node n = q.front();
        q.pop();

        if (footPrint[n.type % 2][n.y][n.x])
        {
            continue;
        }
        
        footPrint[n.type % 2][n.y][n.x] = true;

        if ((n.x == width - 1 && n.y == height - 1) || (n.x + otherX[n.type] == width - 1 && n.y + otherY[n.type] == height - 1))
        {
            minimum = min(minimum, n.count);
            continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            if (isAbleMove(board, n.x + otherX[i], n.y + otherY[i], n.type))
            {
                q.push({ n.x + otherX[i], n.y + otherY[i], n.type, n.count + 1 });
            }
        }

        if (isAbleRotate(board, n.x, n.y, (n.type + 5) % 4))
        {
            q.push({ n.x, n.y, (n.type + 5) % 4, n.count + 1 });
            q.push({ n.x + otherX[n.type], n.y + otherY[n.type], (n.type + 3) % 4, n.count + 1 });
        }

        if (isAbleRotate(board, n.x, n.y, (n.type + 3) % 4))
        {
            q.push({ n.x, n.y, (n.type + 3) % 4, n.count + 1 });
            q.push({ n.x + otherX[n.type], n.y + otherY[n.type], (n.type + 5) % 4, n.count + 1 });
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    height = board.size();
    width = board[0].size();

    BFS(board, 0, 0, 0);

    return minimum;
}

int main()
{
    solution({ {0, 0, 0, 1, 1} ,{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} });
}