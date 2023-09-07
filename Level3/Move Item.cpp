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

#include <iostream>


//#include <queue>
//#include <vector>
//
//using namespace std;
//
//int minimum = 100000;
//int width = 0, height = 0;
//int otherX[4]{ 1, 0, -1, 0 };
//int otherY[4]{ 0, 1, 0, -1 };
//
//struct node {
//    int x, y, type, count;
//    bool isRot = false; 
//};
//
//bool isAbleMove(const vector<vector<int>>& board, int x, int y, int type)
//{
//    if (x < 0 || x + otherX[type] < 0 || y < 0 || y + otherY[type] < 0)
//    {
//        return false;
//    }
//    if (x >= width || (x + otherX[type]) >= width || y >= height || (y + otherY[type]) >= height)
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
//bool isAbleRotate(const vector<vector<int>>& board, int x, int y, int beforeType, int type)
//{
//    switch (type)
//    {
//    case 0:
//        if (beforeType == 1)
//        {
//            return isAbleMove(board, x + 1, y, 1);
//        }
//        else if (beforeType == 3)
//        {
//            return isAbleMove(board, x + 1, y, 3);
//        }
//    case 1:
//        if (beforeType == 2)
//        {
//            return isAbleMove(board, x, y + 1, 2);
//        }
//        else if (beforeType == 0)
//        {
//            return isAbleMove(board, x, y + 1, 0);
//        }
//    case 2:
//        if (beforeType == 1)
//        {
//            return isAbleMove(board, x - 1, y, 1);
//        }
//        else if (beforeType == 3)
//        {
//            return isAbleMove(board, x - 1, y, 3);
//        }
//    case 3:
//        if (beforeType == 2)
//        {
//            return isAbleMove(board, x, y - 1, 2);
//        }
//        else if (beforeType == 0)
//        {
//            return isAbleMove(board, x, y - 1, 0);
//        }
//    }
//}
//
//void BFS(const vector<vector<int>>& board, int x, int y, int type)
//{
//    bool footPrint[2][100][100] { false };
//    queue<node> q;
//    vector<vector<vector<int>>> tmp(2, vector<vector<int>>(board.size(), vector<int>(board[0].size(), 40)));
//
//    q.push({ x, y, type, 0, false });
//
//    while (!q.empty())
//    {
//        node n = q.front();
//        q.pop();
//
//        node tmpN = n;
//
//        if (n.type < 2)
//        {
//            n.x = n.x + otherX[n.type];
//            n.y = n.y + otherY[n.type];
//            n.type = n.type + 2;
//        }
//        if (tmp[n.type % 2][n.y][n.x] < n.count  || footPrint[n.type % 2][n.y][n.x] && !n.isRot)
//        {
//            continue;
//        }
//        
//        tmp[n.type % 2][n.y][n.x] = n.count;
//
//        footPrint[n.type % 2][n.y][n.x] = true;
//
//        if ((n.x == width - 1 && n.y == height - 1) || (n.x + otherX[n.type] == width - 1 && n.y + otherY[n.type] == height - 1))
//        {
//            minimum = min(minimum, n.count);
//            continue;
//        }
//
//        for (int i = 0; i < 4; ++i)
//        {
//            if (isAbleMove(board, n.x + otherX[i], n.y + otherY[i], n.type))
//            {
//                q.push({ n.x + otherX[i], n.y + otherY[i], n.type, n.count + 1, false });
//            }
//        }
//
//        if (!n.isRot)
//        {
//            if (isAbleRotate(board, n.x, n.y, n.type, (n.type + 5) % 4))
//            {
//                q.push({ n.x, n.y, (n.type + 5) % 4, n.count + 1, true });
//            }
//            if (isAbleRotate(board, n.x + otherX[n.type], n.y + otherY[n.type], (n.type + 2) % 4, (n.type + 3) % 4))
//            {
//                q.push({ n.x + otherX[n.type], n.y + otherY[n.type], (n.type + 3) % 4, n.count + 1, true });
//            }
//
//            if (isAbleRotate(board, n.x, n.y, n.type, (n.type + 3) % 4))
//            {
//                q.push({ n.x, n.y, (n.type + 3) % 4, n.count + 1, true });
//            }
//            if (isAbleRotate(board, n.x + otherX[n.type], n.y + otherY[n.type], (n.type + 2) % 4, (n.type + 5) % 4))
//            {
//                q.push({ n.x + otherX[n.type], n.y + otherY[n.type], (n.type + 5) % 4, n.count + 1, true });
//            }
//        }
//    }
//}

#include <queue>
#include <vector>

using namespace std;

struct node {
    int x, y, type, count;
};

int dirX[4]{ 1, -1, 0, 0 };
int dirY[4]{ 0, 0, 1, -1 };

bool isAbleMove(vector<vector<int>>& board, int x, int y, int type, int index)
{
    int otherX = type == 0 ? x - 1 : x;
    int otherY = type == 1 ? y - 1 : y;

    if (otherX < 0 || x >= board[0].size() || otherY < 0 || y >= board.size())
    {
        return false;
    }
    else if (otherX + dirX[index] < 0 || x + dirX[index] >= board[0].size() || otherY + dirY[index] < 0 || y + dirY[index] >= board.size())
    {
        return false;
    }

    return board[y + dirY[index]][x + dirX[index]] == 0 && board[otherY + dirY[index]][otherX + dirX[index]] == 0;
}

int BFS(vector<vector<int>> board)
{
    bool footPrint[2][100][100]{ false };
    int height = board.size(), width = board[0].size();
    queue<node> qn;

    qn.push({ 1, 0, 0, 0 });

    while (!qn.empty())
    {
        node n = qn.front();
        qn.pop();
       
        if (footPrint[n.type][n.y][n.x])
        {
            continue;
        }

        if (n.y == board.size() - 1 && n.x == board[0].size() - 1)
        {
            return n.count;
        }

        footPrint[n.type][n.y][n.x] = true;

        if (n.type == 0)
        {
            if (n.x > 0 && n.y > 0 && board[n.y - 1][n.x] == 0 && board[n.y - 1][n.x - 1] == 0)
            {
                qn.push({ n.x - 1, n.y, 1, n.count + 1 });
                qn.push({ n.x, n.y, 1, n.count + 1 });
            }
            if (n.x < board[0].size() && n.y < board.size() - 1 && board[n.y + 1][n.x - 1] == 0 && board[n.y + 1][n.x] == 0)
            {
                qn.push({ n.x - 1, n.y + 1, 1, n.count + 1 });
                qn.push({ n.x, n.y + 1, 1, n.count + 1 });
            }
        }
        else if (n.type == 1)
        {
            if (n.x > 0 && n.y > 0 && board[n.y - 1][n.x - 1] == 0 && board[n.y][n.x - 1] == 0)
            {
                qn.push({ n.x, n.y, 0, n.count + 1 });
                qn.push({ n.x, n.y - 1, 0, n.count + 1 });
            }
            if (n.x < board[0].size() - 1 && n.y < board[0].size() && board[n.y][n.x + 1] == 0 && board[n.y - 1][n.x + 1] == 0)
            {
                qn.push({ n.x + 1, n.y, 0, n.count + 1 });
                qn.push({ n.x + 1, n.y - 1, 0, n.count + 1 });
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            if (isAbleMove(board, n.x, n.y, n.type, i) && !footPrint[n.type][n.y + dirY[i]][n.x + dirX[i]])
            {
                qn.push({ n.x + dirX[i], n.y + dirY[i], n.type, n.count + 1 });
            }
        }
    }

    return 0;
}

int solution(vector<vector<int>> board) {
    return BFS(board);
}


int main()
{
    //solution("handshake", "shake hands");
    

    solution(
        [
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 1, 1, 1, 0, 0],
        [0, 1, 1, 1, 1, 1, 1, 1, 1],
        [0, 0, 1, 1, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 0]]

    );

    solution({
        {0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1},
        {0, 0, 1, 0, 0, 0, 0} }
    );
}