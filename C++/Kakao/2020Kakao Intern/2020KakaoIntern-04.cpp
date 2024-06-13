#include <string>
#include <vector>

using namespace std;

enum Direction {LEFT = -2, RIGHT = -1, UP = 1, DOWN = 2};

vector<vector<int>> costBoard;
const int CONER_COST = 500;
const int STRIGHT_COST = 100;

struct Vector2Int {
    int st;
    int coner;
};

const bool IsableGo(vector<vector<int>>& board, int x, int y, Direction direction, bool isConer) {
    int addCost = isConer ? CONER_COST + STRIGHT_COST : STRIGHT_COST;
    int cost = costBoard[y][x] + addCost;

    if (direction == LEFT) {
        if (x == 0) return false;
        else if (board[y][x - 1] == 1) return false;
        return costBoard[y][x - 1] > cost;
    }
    if (direction == RIGHT) {
        if (x == costBoard[0].size() - 1) return false;
        else if (board[y][x + 1] == 1) return false;
        return costBoard[y][x + 1] > cost;
    }
    if (direction == UP) {
        if (y == 0) return false;
        else if (board[y - 1][x] == 1) return false;
        return costBoard[y - 1][x] > cost;
    }
    if (direction == DOWN) {
        if (y == costBoard.size() - 1) return false;
        else if (board[y + 1][x] == 1) return false;
        return costBoard[y + 1][x] > cost;
    }

    return false;
}

int CalCost(Direction now, Direction next) {
    if (now * next > 0) return STRIGHT_COST;
    else return CONER_COST + STRIGHT_COST;
}

void DFS(vector<vector<int>>& board, int x, int y, Direction direction, int cost) {
    costBoard[y][x] = costBoard[y][x] > cost ? cost : costBoard[y][x];

    for (int i = -2; i <= 2; ++i) {
        switch (i) {
        case LEFT: {
            if (IsableGo(board, x, y, Direction(i), i * LEFT < 0)) {
                DFS(board, x - 1, y, LEFT, costBoard[y][x] + CalCost(direction, LEFT));
            }
            break;
        }
        case RIGHT: {
            if (IsableGo(board, x, y, Direction(i), i * RIGHT < 0)) {
                DFS(board, x + 1, y, RIGHT, costBoard[y][x] + CalCost(direction, RIGHT));
            }
            break;
        }
        case UP: {
            if (IsableGo(board, x, y, Direction(i), i * UP < 0)) {
                DFS(board, x, y - 1, UP, costBoard[y][x] + CalCost(direction, UP));
            }
            break;
        }
        case DOWN: {
            if (IsableGo(board, x, y, Direction(i), i * DOWN < 0)) {
                DFS(board, x, y + 1, DOWN, costBoard[y][x] + CalCost(direction, DOWN));
            }
            break;
        }
        }
    }

}
#include <iostream>
int solution(vector<vector<int>> board) {
    costBoard = vector<vector<int>>(board.size(), vector<int>(board[0].size(), INT_MAX));
    int answer = 0;

    DFS(board, 0, 0, RIGHT, 0);
    DFS(board, 0, 0, DOWN, 0);

    return costBoard[board.size() - 1][board[0].size() - 1];
}


int main() {
    vector<vector<int>> board = 
    { 
        { 0,0,0,0,0,0,0,0 }, 
        { 1,1,1,1,1,1,1,0 },
        { 0,0,0,0,0,0,0,0 },
        { 0,1,1,1,1,1,1,1 },
        { 0,0,0,0,0,0,0,0 },
        { 1,1,1,1,1,1,1,0 }
    };

    cout << solution(board);
}