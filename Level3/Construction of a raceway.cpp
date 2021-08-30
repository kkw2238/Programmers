/*
	https://programmers.co.kr/learn/courses/30/lessons/67259
*/

#include <vector>
#include <queue>

using namespace std;

enum Dir { NONE = -1, HORIZON = 0, VERTICAL = 1};
enum Type { EMPTY = 0, WALL = 1 };
enum Cost { STRAIGHT = 100, CORNER = 600 };

int board_Size;

class RailCost {
public:
    int cost = 100000000;
    int direction = Dir::NONE;
};

class Node : public RailCost {
public:
    int y = 0;
    int x = 0;

    Node(int newCost, int newY, int newX, int newDir) :
        y(newY),
        x(newX)
    {  
        cost = newCost;
        direction = newDir;
    }

    const bool operator<(const Node& other) const
    {
        return other.cost < cost;
    }
};

vector<vector<RailCost>> costs;

const bool IsInside(const int x, const int y)
{
    return x >= 0 && x < board_Size && y >= 0 && y < board_Size;
}

int solution(vector<vector<int>> board) {
    board_Size = board.size();
    costs = vector<vector<RailCost>>(board_Size, vector<RailCost>(board_Size));
    costs[0][0].cost = 0;

    priority_queue<Node> nodes;
    const int X_OFFSET[4] = { 1, -1, 0, 0 };
    const int Y_OFFSET[4] = { 0, 0, 1, -1 };
    int answer = 0;
    
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

        if (costs[node.y][node.x].cost < node.cost)
        {
            continue;
        }
        
        costs[node.y][node.x].cost = node.cost;
        costs[node.y][node.x].direction = node.direction;

        if (node.y == board_Size - 1 && node.x == board_Size - 1)
        {
            return costs[node.y][node.x].cost;
        }

        int nextCosts[2];
        nextCosts[VERTICAL] = node.cost + (node.direction == VERTICAL ? STRAIGHT : CORNER);
        nextCosts[HORIZON] = node.cost + (node.direction == HORIZON ? STRAIGHT : CORNER);
        
        for (int i = 0; i < 4; ++i)
        {
            int nextX = node.x + X_OFFSET[i];
            int nextY = node.y + Y_OFFSET[i];

            if (IsInside(nextX, nextY) && board[nextY][nextX] == EMPTY && costs[nextY][nextX].cost >= nextCosts[i / 2])
            {
                nodes.emplace(nextCosts[ i / 2 ], nextY, nextX, i / 2);
            }
        }
    }

    return answer;
}


#include <iostream>

int main()
{
    solution({ 
            { 0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
            { 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
            { 1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
            { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            { 0, 0, 0, 0, 1, 0, 1, 0, 1, 1},
            { 0, 0, 1, 0, 1, 1, 0, 1, 0, 1},
            { 0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
            { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
            { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0} });

    for (int y = 0; y < 10; ++y)
    {
        for (int x = 0; x < 10; ++x)
        {
            if (costs[y][x].cost == 100000000)
            {
                costs[y][x].cost = 0;
            }
            cout << costs[y][x].cost << '\t';
        }
        cout << '\n';
    }
}