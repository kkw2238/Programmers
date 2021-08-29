/*
	https://programmers.co.kr/learn/courses/30/lessons/67259
*/

#include <vector>
#include <queue>

using namespace std;

enum Dir { NONE = -1, VERTICAL = 1, HORIZON = 2};
enum Type { EMPTY = 0, WALL = 1 };
enum Cost { STRAIGHT = 100, CORNER = 600 };

class RailCost {
public:
    int cost = 100000000;
    Dir direction = Dir::NONE;
};

class Node : public RailCost {
public:
    int y = 0;
    int x = 0;

    Node(int newCost, int newY, int newX, Dir newDir) :
        y(newY),
        x(newX)
    {  
        cost = newCost;
        direction = newDir;
    }

    const bool operator<(const Node& other) const
    {
        return other.cost > cost;
    }
};

vector<vector<RailCost>> costs;

int solution(vector<vector<int>> board) {
    priority_queue<Node> nodes;
    int nowY = 0;
    int nowX = 0;
    int answer = 0;
    
    if (board[nowY + 1][nowX] == EMPTY)
    {
        nodes.emplace(STRAIGHT, nowY + 1, nowX, VERTICAL);
    }

    if (board[nowY][nowX + 1] == EMPTY)
    {
        nodes.emplace(STRAIGHT, nowY, nowX + 1, HORIZON);
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

    }

    return answer;
}