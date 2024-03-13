/*
	https://school.programmers.co.kr/learn/courses/30/lessons/118669
*/

//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
//    vector<int> answer{ 100000001 ,100000001 };
//    vector<vector<int>> path(n + 1, vector<int>(n + 1, -100000001));
//
//    for (vector<int>& p : paths)
//    {
//        path[p[0]][p[1]] = p[2];
//        path[p[1]][p[0]] = p[2];
//    }
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            for (int m = 1; m <= n; ++m)
//            {
//                path[j][m] = max(path[j][m], max(path[j][i], path[i][m]));
//            }
//        }
//    }
//
//    for (int g : gates)
//    {
//        for (int s : summits)
//        {
//            if (path[g][s] < answer[1])
//            {
//                answer = { g, path[g][s] };
//            }
//            else if (path[g][s] == answer[1])
//            {
//                answer[0] = min(answer[0], g);
//            }
//        }
//    }
//
//    return answer;
//}

#include <string>
#include <vector>
#include <queue>

using namespace std;

enum { NORMAL, GATE, SUMMIT };
struct Node {
    vector<pair<int, int>> next;
    int type = NORMAL;
};

pair<int, int> dijkstra(int n, int start, vector<Node>& nodes)
{
    vector<int> visited(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> next;
    vector<int> intensity(n + 1, 100000000);

    visited[start] = 1;
    for (pair<int, int>& nx : nodes[start].next)
    {
        intensity[nx.first] = nx.second;
        next.emplace(nx.second, nx.first);
    }

    while (!next.empty())
    {
        pair<int, int> now = next.top();
        next.pop();
        
        if (nodes[now.second].type == SUMMIT)
        {
            return pair<int, int>(intensity[now.second], now.second);
        }
        else if (visited[now.second] == 1 || (now.second != start && nodes[now.second].type == GATE))
        {
            continue;
        }

        visited[now.second] = 1;

        for (pair<int, int>& nx : nodes[now.second].next)
        {   
            intensity[nx.first] = min(intensity[nx.first], max(nx.second, now.first));
            next.emplace(intensity[nx.first], nx.first);
        }
    }

    return pair<int, int>(0, 0);
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer{ 0, 1000000000 };
    vector<Node> nodes(n + 1);

    for (vector<int>& path : paths)
    {
        nodes[path[0]].next.emplace_back(path[1], path[2]);
        nodes[path[1]].next.emplace_back(path[0], path[2]);
    }

    for (int gate : gates)
    {
        nodes[gate].type = GATE;
    }

    for (int summit : summits)
    {
        nodes[summit].type = SUMMIT;
    }

    for (int gate : gates)
    {
        pair<int, int> result = dijkstra(n, gate, nodes);
        if (result.first < answer[1] || (result.first == answer[1] && result.second < answer[0]))
        {
            answer[0] = result.second;
            answer[1] = result.first;
        }
    }

    return answer;
}

int main()
{
    solution(6, { {1,2,3}, {2,3,5}, {2,4,2}, {2,5,4}, {3,4,4}, {4,5,3}, {4,6,1}, {5,6,1} }, { 1,3 }, { 5 });
}