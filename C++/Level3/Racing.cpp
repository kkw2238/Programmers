#include <vector>

using namespace std;
enum Direction{ LEFT, RIGHT, UP, DOWN, ALL };
const int CORNER_COST = 500;
const int STRAIGHT_COST = 100;
const int MAX_COST = CORNER_COST * 25 * 25;

vector<vector<int>> costs;
const Direction dirs[4]{ LEFT, RIGHT , UP, DOWN};

void PathFind(const vector<vector<int>>& board, int nowX, int nowY, int nowCost, Direction dir)
{
    costs[nowY][nowX] = nowCost;
    if (nowX == board[0].size() - 1 && nowY == board.size() - 1)
    {
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int addCost = (dir == dirs[i]) ? STRAIGHT_COST : CORNER_COST;
        int nextX = nowX;
        int nextY = nowY;

        if (dir == ALL)
        {
            addCost = STRAIGHT_COST;
        }

        switch (dirs[i])
        {
        case UP:
            --nextY;
            break;
        case DOWN:
            ++nextY;
            break;
        case LEFT:
            --nextX = nowX;
            break;
        case RIGHT:
            ++nextX;
            break;
        }

        if (nextY >= 0 && nextY < board.size() && nextX >= 0 && nextX < board[0].size())
        {
            if (board[nextY][nextX] == 0 && costs[nowY][nowX] + addCost < costs[nextY][nextX])
            {
                PathFind(board, nextX, nextY, costs[nowY][nowX] + addCost, dirs[i]);
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    costs = vector<vector<int>>(board.size(), vector<int>(board[0].size(), MAX_COST));
    PathFind(board, 0, 0, 100, ALL);
    return costs[board.size() - 1][board[0].size() -1];
}

#include <iostream>
int main()
{
    vector<vector<int>> board{ {0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0} };
    cout << solution(board);
}