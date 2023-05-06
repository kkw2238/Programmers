#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

enum {START, DEST, COST};
enum {NON_TRAP, TRAP};

struct Node
{
    vector<vector<pair<int, int>>> nextNode = vector<vector<pair<int, int>>>(2, vector<pair<int, int>>());

    int traps = 0;
};

struct QueueNode
{
    QueueNode(int nextCost, int nextIndex, int isTrapRoom, const vector<int>& trapIndices)
    {
        cost = nextCost;
        nowIndex = nextIndex;
        traps = isTrapRoom;
        trapsIndices = trapIndices;
    };

    const bool operator<(const QueueNode& other) const 
    {
        return other.cost < cost;
    }

    vector<int> trapsIndices;
    int cost = 0;
    int nowIndex = 0;
    int traps = 0;
};

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 2147483647;

    vector<Node> rooms(n + 1);
    vector<int> trapIndices(n + 1);

    priority_queue<QueueNode> nowRoom;

    for (int trap : traps)
    {
        trapIndices[trap] = 1;
        rooms[trap].traps = TRAP;
    }

    for (const vector<int>& road : roads)
    {
        if (rooms[road[START]].traps == 1)
        {
            rooms[road[DEST]].nextNode[TRAP].emplace_back(pair(road[START], road[COST]));
        }
        else if (rooms[road[DEST]].traps == 1)
        {
            rooms[road[START]].nextNode[TRAP].emplace_back(pair(road[DEST], road[COST]));
        }

        rooms[road[START]].nextNode[NON_TRAP].emplace_back(pair(road[DEST], road[COST]));
    }


    for (auto [nextRoom, cost] : rooms[start].nextNode[NON_TRAP])
    {
        nowRoom.emplace(cost, nextRoom, rooms[nextRoom].traps, trapIndices);
    }

    while (!nowRoom.empty())
    {
        QueueNode node = nowRoom.top();
        nowRoom.pop();

        if (node.cost > answer)
        {
            continue;
        }
        
        if (node.nowIndex == end)
        {
            answer = node.cost;
            continue;
        }

        
    }

    return answer;
}