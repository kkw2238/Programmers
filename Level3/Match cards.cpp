/*
    https://programmers.co.kr/learn/courses/30/lessons/72415
*/
//
//#include <vector>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//enum DIR { U = 1, D = -1, L = 2, R = -2, CU = 3, CD = -3, CL = 4, CR = -4 };
//const int BOARD_SIZE = 4;
//const int GRAP_CARD = 7;
//const int EMPTY = 0;
// 
//struct GameState {
//    pair<int, int> nowPos;
//    map<int, vector<pair<int, int>>> remainTypePosition;
//
//    int nowCard = 0;
//    int remainCardCount = 0;
//    int clickCount = 0;
//    int beforeDir = 0;
//
//    vector<vector<int>> boardState;
//   
//    const bool operator<(const GameState& other) const
//    {
//        if (remainTypePosition.size() != other.remainTypePosition.size())
//        {
//            return remainTypePosition.size() > other.remainTypePosition.size();
//        }
//        return clickCount > other.clickCount;
//    }
//
//    const int GetCardType() const
//    {
//        return boardState[nowPos.first][nowPos.second];
//    }
//
//    void GrapCard()
//    {
//        nowCard = GetCardType();
//        boardState[nowPos.first][nowPos.second] = GRAP_CARD;
//    }
//
//    void MoveNewPosition(const pair<int, int>& newPos, int dir)
//    {
//        ++clickCount;
//        nowPos = newPos;
//        beforeDir = dir;
//    }
//
//    void EraseBoardData(int type)
//    {
//        for (const pair<int, int>& pos : remainTypePosition[type])
//        {
//            boardState[pos.first][pos.second] = EMPTY;
//        }
//
//        remainTypePosition.erase(type);
//        remainCardCount -= 2;
//    }
//};
//
//void Up(pair<int, int>& pos)
//{
//    --pos.first;
//}
//
//void Down(pair<int, int>& pos)
//{
//    ++pos.first;
//}
//
//void Left(pair<int, int>& pos)
//{
//    --pos.second;
//}
//
//void Right(pair<int, int>& pos)
//{
//    ++pos.second;
//}
//
//const int Abs(const int n)
//{
//    return n < 0 ? -n : n;
//}
//
//const bool IsInsideBoard(const pair<int, int>& pos)
//{
//    return pos.first >= 0 && pos.second >= 0 && pos.first < BOARD_SIZE&& pos.second < BOARD_SIZE;
//}
//
//pair<int, int> Move(GameState& state, int dir)
//{
//    pair<int, int> result = state.nowPos;
//    int moveCount = 1;
//
//    if (state.beforeDir + dir == 0)
//    {
//        return pair(-1, -1);
//    }
//
//    if (Abs(dir) > 2)
//    {
//        moveCount = BOARD_SIZE - 1;
//    }
//
//    for (int i = 0; i < moveCount; ++i)
//    {
//        switch (dir)
//        {
//        case U:
//        case CU:
//            Up(result);
//            break;
//
//        case D:
//        case CD:
//            Down(result);
//            break;
//
//        case L:
//        case CL:
//            Left(result);
//            break;
//
//        case R:
//        case CR:
//            Right(result);
//            break;
//        }
//
//        if (!IsInsideBoard(result))
//        {
//            return pair(-1, -1);
//        }
//        else if (state.boardState[result.first][result.second] != EMPTY)
//        {
//            return result;
//        }
//        else if (result.first == 0 || result.second == 0 || result.first == BOARD_SIZE - 1 || result.second == BOARD_SIZE - 1)
//        {
//            return result;
//        }
//    }
//
//    return result;
//}
//
//int solution(vector<vector<int>> board, int r, int c) {
//    priority_queue<GameState> queue;
//    map<int, vector<pair<int, int>>> remainTypePosition;
//
//    int answer = 1000;
//    int remainCard = 0;
//
//    for (int y = 0; y < BOARD_SIZE; ++y)
//    {
//        for (int x = 0; x < BOARD_SIZE; ++x)
//        {
//            if (board[y][x] != 0)
//            {
//                remainTypePosition[board[y][x]].push_back(pair(y, x));
//                ++remainCard;
//            }
//        }
//        
//    }
//    GameState startState{ .nowPos = pair(r, c), .remainTypePosition = remainTypePosition, .remainCardCount = remainCard, .boardState = board };
//    queue.push(startState);
//    
//    while (!queue.empty())
//    {
//        GameState nowState = queue.top();
//        queue.pop();
//
//        if (nowState.clickCount >= answer)
//        {
//            continue;
//        }
//
//        if (nowState.remainCardCount == 0)
//        {
//            answer = nowState.clickCount;
//        }
//
//        int nowIndexCardType = nowState.GetCardType();
//        if (nowIndexCardType != EMPTY)
//        {
//            if (nowState.nowCard == nowIndexCardType)
//            {
//                ++nowState.clickCount;
//
//                nowState.nowCard = EMPTY;
//                nowState.EraseBoardData(nowIndexCardType);
//                queue.push(nowState);
//
//                continue;
//            }
//            else if (nowState.nowCard == EMPTY)
//            {
//                ++nowState.clickCount;
//
//                nowState.GrapCard();
//                queue.push(nowState);
//
//                continue;
//            }
//        }
//
//        for (int dir = CR; dir <= CL; ++dir)
//        {
//            if (dir == 0)
//            {
//                continue;
//            }
//            GameState tmpState = nowState;
//            pair newPos = Move(tmpState, dir);
//
//            if (newPos.first == -1 || newPos.second == -1)
//            {
//                continue;
//            }
//            
//            tmpState.MoveNewPosition(newPos, dir);
//            queue.push(tmpState);
//        }
//    }
//
//    return answer;
//} 

#include <string>
#include <vector>
#include <queue>

using namespace std;

int dirX[4]{ -1, 0, 1, 0 };
int dirY[4]{ 0, 1, 0, -1 };

const int BOARD_SIZE = 4;

struct Point {
    int x, y;
};

bool isInside(int x, int y, vector<vector<int>>& board)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

Point ctrlDir(int x, int y, int dir, vector<vector<int>>& board)
{
    int ny = y + dirY[dir];
    int nx = x + dirX[dir];

    while (isInside(nx, ny, board))
    {
        if (board[ny][nx] != 0)
        {
            return Point{ nx, ny };
        }

        ny += dirY[dir];
        nx += dirX[dir];
    }

    return Point{ nx - dirX[dir], ny - dirY[dir] };
}

int getDistance(Point now, Point dest, int count, vector<vector<int>>& board)
{
    vector<vector<int>> footPrint(board.size(), vector<int>(board[0].size(), 30));
    queue<Point> next;
    next.push(now);

    footPrint[now.y][now.x] = 0;

    while (!next.empty()) 
    {
        Point now = next.front();
        next.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = dirX[i] + now.x;
            int ny = dirY[i] + now.y;

            if (isInside(nx, ny, board) && footPrint[ny][nx] > footPrint[now.y][now.x] + 1)
            {
                footPrint[ny][nx] = footPrint[now.y][now.x] + 1;
                next.push(Point{ nx, ny });
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            Point nPos = ctrlDir(now.x, now.y, i, board);

            if (footPrint[nPos.y][nPos.x] > footPrint[now.y][now.x] + 1)
            {
                footPrint[nPos.y][nPos.x] = footPrint[now.y][now.x] + 1;
                next.push(nPos);
            }
        }
    }

    return footPrint[dest.y][dest.x];
}

int getTotalMove(vector<vector<int>> board, vector<int>& targets, vector<vector<Point>>& pos, Point begin)
{
    vector<vector<int>> footPrint(7, { 200, 200 });
    int n = 0;
    int now = targets[0];

    footPrint[now][1] = getDistance(begin, pos[now][0], 0, board) + getDistance(pos[now][0], pos[now][1], 0, board);
    footPrint[now][0] = getDistance(begin, pos[now][1], 0, board) + getDistance(pos[now][1], pos[now][0], 0, board);

    board[pos[now][0].y][pos[now][0].x] = 0;
    board[pos[now][1].y][pos[now][1].x] = 0;

    for (int i = 1; i < targets.size(); ++i)
    {
        now = targets[i];
        int before = targets[i - 1];

        footPrint[now][0] = min(footPrint[before][0] + getDistance(pos[before][0], pos[now][1], 0, board),
            footPrint[before][1] + getDistance(pos[before][1], pos[now][1], 0, board)) + getDistance(pos[now][1], pos[now][0], 0, board);
        footPrint[now][1] = min(footPrint[before][0] + getDistance(pos[before][0], pos[now][0], 0, board), 
            footPrint[before][1] + getDistance(pos[before][1], pos[now][0], 0, board)) + getDistance(pos[now][0], pos[now][1], 0, board);
    }

    return min(footPrint[targets.back()][0], footPrint[targets.back()][1]) + targets.size() * 2;
}

void makePermutation(vector<int>& p, int index, vector<vector<int>>& permutations)
{
    if (index == p.size())
    {
        permutations.push_back(p);
        return;
    }

    for (int i = index; i < p.size(); ++i)
    {
        swap(p[i], p[index]);
        makePermutation(p, index + 1, permutations);
        swap(p[i], p[index]);
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 100;
    vector<vector<Point>> pos(7);
    vector<int> permutation;
    vector<vector<int>> permutations;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j] != 0)
            {
                pos[board[i][j]].push_back(Point{ j , i });
            }
        }
    }

    for (int i = 1; i <= 6; ++i)
    {
        if (!pos[i].empty())
        {
            permutation.push_back(i);
        }
    }

    makePermutation(permutation, 0, permutations);
    for (vector<int>& p : permutations)
    {
        answer = min(answer, getTotalMove(board, p, pos, Point{ c, r }));
    }

    return answer;
}