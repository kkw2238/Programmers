/*
	https://school.programmers.co.kr/learn/courses/30/lessons/72413
*/

#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct FindNode {
    int a;
    int b;
    int aCosts;
    int bCosts;
    int costs;
};

class Compare {
public:
    const bool operator()(FindNode& a, FindNode& b)
    {
        return a.costs > b.costs;
    }
};

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    map<int, vector<int>> roads;
    vector<vector<int>> costs(n + 1, vector<int>(n + 1, -1));
    vector<int> aCosts(n + 1, 2147483647);
    vector<int> bCosts(n + 1, 2147483647);

    priority_queue<FindNode, vector<FindNode>, Compare> pq;

    for (vector<int>& fare : fares)
    {
        costs[fare[0]][fare[1]] = fare[2];
        costs[fare[1]][fare[0]] = fare[2];
        costs[fare[0]][fare[0]] = 0;
        costs[fare[1]][fare[1]] = 0;

        roads[fare[0]].push_back(fare[1]);
        roads[fare[1]].push_back(fare[0]);
    }

    pq.push(FindNode{ s, s, 0, 0, 0 });
    aCosts[s] = 0;
    bCosts[s] = 0;

    while (!pq.empty())
    {
        FindNode node = pq.top();
        pq.pop();

        if (node.a == a && node.b == b)
        {
            return node.costs;
        }

        if (node.aCosts > aCosts[node.a] || node.bCosts > bCosts[node.b])
        {
            continue;
        }

        for (int i : roads[node.a])
        {
            int aCost = node.costs;
            int nextA = node.a;

            if (nextA != a)
            {
                aCost += costs[node.a][i];
                nextA = i;
            }

            if (aCosts[nextA] < (node.aCosts + costs[node.a][i]))
            {
                continue;
            }

            for (int j : roads[node.b])
            {
                int totalCost = aCost;
                int nextB = node.b;
                if (nextB != b)
                {
                    nextB = j;
                    totalCost += costs[node.b][j];
                }

                if (bCosts[nextB] < (node.bCosts + costs[node.b][j]))
                {
                    continue;
                }

                aCosts[nextA] = aCosts[node.a] + costs[node.a][i];
                bCosts[nextB] = bCosts[node.b] + costs[node.b][j];

                if (nextA == nextB && node.a == node.b)
                {
                    aCosts[nextA] -= costs[node.a][i] / 2;
                    bCosts[nextB] -= costs[node.b][j] / 2;
                    totalCost -= costs[node.b][j];
                }

                pq.push({ nextA, nextB, aCosts[nextA], bCosts[nextB], totalCost });
            }
        }
    }

    return 0;
}

int main()
{
    solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} });
}
//vector<int> aCosts(n, 2147483647);
//vector<int> bCosts(n, 2147483647);
