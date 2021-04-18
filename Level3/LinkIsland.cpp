#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    vector<int> dests;
    vector<int> costs;
    int myCost = 9999;
};

vector<Node> graph;

enum { START, DEST, COST };

int solution(int n, vector<vector<int>> costs) {
    graph = vector<Node>(n);

    for (const vector<int>& cost : costs)
    {
        graph[cost[START]].costs.emplace_back(cost[COST]);
        graph[cost[START]].dests.emplace_back(cost[DEST]);

        graph[cost[DEST]].costs.emplace_back(cost[COST]);
        graph[cost[DEST]].dests.emplace_back(cost[START]);
    }

    for (Node& island : graph)
    {
        
    }
}


#include <iostream>
int main()
{
    int n = 4;
    vector<vector<int>> costs = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};

    cout << solution(n, costs);
}