/*
	https://school.programmers.co.kr/learn/courses/30/lessons/72413
*/

//#include <string>
//#include <vector>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//struct FindNode {
//    int a;
//    int b;
//    int aCosts;
//    int bCosts;
//    int costs;
//};
//
//class Compare {
//public:
//    const bool operator()(FindNode& a, FindNode& b)
//    {
//        return a.costs > b.costs;
//    }
//};
//
//int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
//    map<int, vector<int>> roads;
//    vector<vector<int>> costs(n + 1, vector<int>(n + 1, -1));
//    vector<int> aCosts(n + 1, 2147483647);
//    vector<int> bCosts(n + 1, 2147483647);
//
//    priority_queue<FindNode, vector<FindNode>, Compare> pq;
//
//    for (vector<int>& fare : fares)
//    {
//        costs[fare[0]][fare[1]] = fare[2];
//        costs[fare[1]][fare[0]] = fare[2];
//        costs[fare[0]][fare[0]] = 0;
//        costs[fare[1]][fare[1]] = 0;
//
//        roads[fare[0]].push_back(fare[1]);
//        roads[fare[1]].push_back(fare[0]);
//    }
//
//    pq.push(FindNode{ s, s, 0, 0, 0 });
//    aCosts[s] = 0;
//    bCosts[s] = 0;
//
//    while (!pq.empty())
//    {
//        FindNode node = pq.top();
//        pq.pop();
//
//        if (node.a == a && node.b == b)
//        {
//            return node.costs;
//        }
//
//        if (node.aCosts > aCosts[node.a] || node.bCosts > bCosts[node.b])
//        {
//            continue;
//        }
//
//        aCosts[node.a] = node.aCosts;
//        bCosts[node.b] = node.bCosts;
//
//        for (int i : roads[node.a])
//        {
//            int aCost = node.costs;
//            int nextA = node.a;
//
//            if (nextA != a)
//            {
//                aCost += costs[node.a][i];
//                nextA = i;
//            }
//
//            if (aCosts[i] < (aCosts[node.a] + aCost))
//            {
//                continue;
//            }
//
//            for (int j : roads[node.b])
//            {
//                int totalCost = aCost;
//                int nextB = node.b;
//                if (nextB != b)
//                {
//                    nextB = j;
//                    totalCost += costs[node.b][j];
//                }
//
//                int addACost = costs[node.a][i];
//                int addBCost = costs[node.b][j];
//
//                if (nextA == nextB && node.a == node.b)
//                {
//                    totalCost -= addACost;
//                    addACost /= 2;
//                    addBCost /= 2;
//                }
//
//                if (bCosts[nextB] < (bCosts[node.b] + addBCost))
//                {
//                    continue;
//                }
//
//                pq.push({ nextA, nextB, aCosts[node.a] + addACost, bCosts[node.b] + addBCost, totalCost });
//            }
//        }
//    }
//
//    return 0;
//}

//
//#include <string>
//#include <vector>
//#include <map>
//#include <queue>
//
//using namespace std;
//
//struct FindNode {
//    int a;
//    int b;
//    int beforeA;
//    int beforeB;
//    int costs;
//    int beforeCosts;
//};
//
//class Compare {
//public:
//    const bool operator()(FindNode& a, FindNode& b)
//    {
//        return a.costs > b.costs;
//    }
//};
//
//void rebuildCost(vector<vector<int>>& rangeFrom, vector<vector<int>>& costs, map<int, vector<int>>& roads, int start)
//{
//    priority_queue<FindNode, vector<FindNode>, Compare> pq;
//
//    for (int next : roads[start])
//    {
//        rangeFrom[start][next] = costs[start][next];
//        rangeFrom[next][start] = costs[next][start];
//        pq.push({ next, next, next, next, costs[start][next], 0 });
//    }
//
//    while (!pq.empty())
//    {
//        FindNode node = pq.top();
//        pq.pop();
//
//        for (int next : roads[node.a])
//        {
//            int roadsCost = node.costs + costs[node.a][next];
//            if (roadsCost < rangeFrom[node.a][next])
//            {
//                rangeFrom[node.a][next] = roadsCost;
//                rangeFrom[next][node.a] = roadsCost;
//
//                pq.push({ next, next, next, next, roadsCost, 0 });
//            }
//        }
//    }
//}
//
//int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
//    vector<vector<int>> rangeFrom(n + 1, vector<int>(n + 1, 2147483647));
//    vector<vector<int>> costs(n + 1, vector<int>(n + 1, -1));
//    map<int, vector<int>> roads;
//
//    for (vector<int>& fare : fares)
//    {
//        costs[fare[0]][fare[1]] = fare[2];
//        costs[fare[1]][fare[0]] = fare[2];
//        costs[fare[0]][fare[0]] = 0;
//        costs[fare[1]][fare[1]] = 0;
//
//        roads[fare[0]].push_back(fare[1]);
//        roads[fare[1]].push_back(fare[0]);
//    }
//
//    for (int i = 1; i <= n; ++i)
//    {
//        rebuildCost(rangeFrom, costs, roads, s);
//    }
//    priority_queue<FindNode, vector<FindNode>, Compare> pq;
//    pq.push({ s, s, 0, 0, 0, 0 });
//
//    while (!pq.empty())
//    {
//        FindNode node = pq.top();
//        pq.pop();
//
//        if (node.a == a && node.b == b)
//        {
//            return node.beforeCosts;
//        }
//        
//        for (int nextA : roads[node.a])
//        {
//            for (int nextB : roads[node.b])
//            {
//                int nextCost = 0;
//                int nowCost = node.beforeCosts;
//
//                if (node.a != a)
//                {
//                    if (nextA == node.beforeA)
//                    {
//                        continue;
//                    }
//
//                    nextCost += rangeFrom[node.a][nextA];
//                    nowCost += costs[node.a][nextA];
//                }
//                else
//                {
//                    nextA = a;
//                }
//                
//                if (node.b != b)
//                {
//                    if (nextB == node.beforeB)
//                    {
//                        continue;
//                    }
//
//                    nextCost += rangeFrom[node.b][nextB];
//                    nowCost += costs[node.b][nextB];
//                }
//                else
//                {
//                    nextB = b;
//                }
//
//                if (node.a == node.b && nextA == nextB)
//                {
//                    nextCost -= costs[node.a][nextA];
//                    nowCost -= costs[node.a][nextA];
//                }
//
//                pq.push({ nextA, nextB, node.a, node.b, nextCost, nowCost });
//
//            }
//        }
//    }
//
//    return 0;
//}

#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	vector<vector<int>> range(n + 1, vector<int>(n + 1, 100000000));

	for (vector<int>& fare : fares) {
		range[fare[0]][fare[0]] = 0;
		range[fare[1]][fare[1]] = 0;
		range[fare[0]][fare[1]] = fare[2];
		range[fare[1]][fare[0]] = fare[2];
	}

	for (int j = 1; j <= n; ++j)
	{
		for (int from = 1; from <= n; ++from)
		{
			for (int to = 1; to <= n; ++to)
			{
				range[from][to] = min(range[from][j] + range[j][to], range[from][to]);
			}
		}
	}

	int answer = 100000000;

	for (int j = 1; j <= n; ++j)
	{
		for (int to = 1; to <= n; ++to)
		{
			answer = min(range[s][j] + range[j][a] + range[j][b], answer);
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
