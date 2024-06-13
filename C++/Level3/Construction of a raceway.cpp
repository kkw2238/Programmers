/*
	https://programmers.co.kr/learn/courses/30/lessons/67259
*/

#include <vector>
#include <queue>

using namespace std;

enum Dir { NONE = -1, HORIZON = 0, VERTICAL = 1};
enum Type { EMPTY = 0, WALL = 1 };
enum Cost { STRAIGHT = 100, CORNER = 600 };

const int X_OFFSET[4] = { 1, -1, 0, 0 };
const int Y_OFFSET[4] = { 0, 0, 1, -1 };

const int MAXIMUM_COST = 100000000;
int board_Size;

class RailCost {
public:
    int cost[2] = { MAXIMUM_COST, MAXIMUM_COST };
};

class Node : public RailCost {
public:
    int y = 0;
    int x = 0;
    int direction = Dir::NONE;

    Node(int newCost, int newY, int newX, int newDir) :
        y(newY),
        x(newX)
    {  
        cost[newDir] = newCost;
        direction = newDir;
    }

    const bool operator<(const Node& other) const
    {
        return other.cost[direction] < cost[direction];
    }
};

const bool IsInside(const int x, const int y)
{
    return x >= 0 && x < board_Size && y >= 0 && y < board_Size;
}

int solution(vector<vector<int>> board) {
    board_Size = board.size();

    vector<vector<RailCost>> costs = vector<vector<RailCost>>(board_Size, vector<RailCost>(board_Size));
    costs[0][0].cost[HORIZON] = 100;
    costs[0][0].cost[VERTICAL] = 100;

    priority_queue<Node> nodes;
    
    int answer[2] = { MAXIMUM_COST, MAXIMUM_COST };
    
    if (board[1][0] == EMPTY)
    {
        nodes.emplace(STRAIGHT, 1, 0, VERTICAL);
    }

    if (board[0][1] == EMPTY)
    {
        nodes.emplace(STRAIGHT, 0, 1, HORIZON);
    }

    while (!nodes.empty())
    {
        Node node = nodes.top();
        nodes.pop();

        if (costs[node.y][node.x].cost[node.direction] < node.cost[node.direction])
        {
            continue;
        }

        int nextCosts[2];

        nextCosts[VERTICAL] = node.cost[node.direction] + (node.direction == VERTICAL ? STRAIGHT : CORNER);
        nextCosts[HORIZON] = node.cost[node.direction] + (node.direction == HORIZON ? STRAIGHT : CORNER);
        
        if (node.y == board_Size - 1 && node.x == board_Size - 1)
        {
            answer[node.direction] = nextCosts[node.direction] - 100;
            costs[node.y][node.x].cost[node.direction] = nextCosts[node.direction];
            continue;
        }

        costs[node.y][node.x].cost[VERTICAL] = nextCosts[VERTICAL];
        costs[node.y][node.x].cost[HORIZON] = nextCosts[HORIZON];

        for (int i = 0; i < 4; ++i)
        {
            int nextX = node.x + X_OFFSET[i];
            int nextY = node.y + Y_OFFSET[i];

            if (IsInside(nextX, nextY) && board[nextY][nextX] == EMPTY && costs[nextY][nextX].cost[i / 2] >= nextCosts[i / 2])
            {
                nodes.emplace(nextCosts[ i / 2 ], nextY, nextX, i / 2);
            }
        }
    }

    return answer[HORIZON] > answer[VERTICAL] ? answer[VERTICAL] : answer[HORIZON];
}