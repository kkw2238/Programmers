/*
    https://school.programmers.co.kr/learn/courses/30/lessons/1837
*/

//#include <vector>
//#include <map>
//
//using namespace std;
//
//class Graph {    
//    map<int, vector<bool>> graph;
//
//public:
//    Graph(int nodeCount)
//    {
//        for (int i = 0; i < nodeCount; ++i)
//        {
//            graph[i] = vector<bool>(nodeCount, false);
//            graph[i][i] = true;
//        }
//    }
//
//    void Link(int to, int from)
//    {
//        graph[to - 1][from - 1] = true;
//        graph[from - 1][to - 1] = true;
//    }
//
//    const bool IsLinked(int to, int from)
//    {
//        return graph[to - 1][from - 1];
//    }
//
//    int GetLinkNextStations(int now, int next)
//    {
//        int result = 0;
//        for (int station : graph[now])
//        {
//            for (int nextStation : graph[station])
//            {
//                if (IsLinked(nextStation, next))
//                {
//                    return nextStation;
//                    //result.emplace_back(nextStation);
//                }
//            }
//        }
//        return result;
//    }
//};
//
//int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
//    int answer = 0;
//    int nowPos = 1;
//    const int TO = 0;
//    const int FROM = 1;
//
//    Graph graph(n);
//    for (const vector<int>& edge : edge_list)
//    {
//        graph.Link(edge[TO], edge[FROM]);
//    }
//    
//    for (int i = 0; i < gps_log.size() - 2; ++i)
//    {
//        if (graph.IsLinked(nowPos, gps_log[i]))
//        {
//            nowPos = gps_log[i];
//        }
//        else
//        {
//            int abledNextStation = graph.GetLinkNextStations(gps_log[i - 1], gps_log[i + 1]);
//            nowPos = abledNextStation;
//            ++answer;
//        }
//    }
//
//    return answer;
//}

//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct queueNode {
//    int length;
//    int next;
//    int before;
//};
//
//int bfs(int nodeIndex, vector<vector<int>>& roads, int gpsIndex, const vector<int>& gps_log)
//{
//    queue<queueNode> nodeQueue;
//
//    nodeQueue.push({ 0, gps_log[gpsIndex - 1], nodeIndex });
//    
//    for (int i = 0; i < roads[nodeIndex].size(); ++i)
//    {
//        if (gps_log[gpsIndex - 1] == roads[nodeIndex][i])
//        {
//            continue;
//        }
//
//        nodeQueue.push( {1, roads[nodeIndex][i], nodeIndex});
//    }
//
//    while (nodeQueue.empty())
//    {
//        queueNode qNode = nodeQueue.front();
//        nodeQueue.pop();
//
//        if (qNode.length > gpsIndex)
//        {
//            return -1;
//        }
//
//        for (int i = 0; i < roads[qNode.next].size(); ++i)
//        {
//            if (qNode.length > 0 && gps_log[gpsIndex - 1 - qNode.length] == roads[qNode.next][i])
//            {
//                return qNode.length;
//            }
//            if (roads[qNode.next][i] == qNode.before)
//            {
//                continue;
//            }
//
//            nodeQueue.push({ qNode.length + 1, roads[qNode.next][i], qNode.next });
//        }
//    }
//
//    return -1;
//}
//
//int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
//    int answer = 0;
//    vector<vector<int>> roads(n + 1, vector<int>());
//
//    for (vector<int>& edge : edge_list)
//    {
//        roads[edge[0]].push_back(edge[1]);
//        roads[edge[1]].push_back(edge[0]);
//    }
//
//    for (int i = gps_log.size() - 1; i > 0; --i)
//    {
//        bool isAble = false;
//        for (int j = 0; j < roads[gps_log[i]].size(); ++j)
//        {
//            if (roads[gps_log[i]][j] == gps_log[i - 1])
//            {
//                isAble = true;
//                break;
//            }
//        }
//
//        if (!isAble)
//        {
//            bfs(gps_log[min(i + 1, (int)gps_log.size())], roads, i + 1, (int)gps_log.size()), gps_log);
//        }
//
//    }
//
//
//    return answer;
//}

#include <vector>
#include <map>
#include <queue>

using namespace std;

struct node {
    int cost;
    int nowIndex;
    int nowPos;
};

class compare {
public:
    const bool operator()(const node& a, const node& b)
    {
        return a.cost > b.cost;
    }
};

vector<map<int, int>> pathFinder(int n, vector<vector<int>>& linked, int k, vector<int>& gps_log)
{

}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<vector<int>> linked(n + 1, vector<int>());

    for (vector<int>& edge : edge_list)
    {
        linked[edge[0]].push_back(edge[1]);
        linked[edge[1]].push_back(edge[0]);
    }
    
    for (int i = 1; i <= n; ++i)
    {
        linked[i].push_back(i);
    }
    
    priority_queue<node, vector<node>, compare> q;
    q.push(node{ 0, (int)gps_log.size() - 1, gps_log.back() });

    while (!q.empty())
    {
        node now = q.top();
        q.pop();

        if (now.nowIndex == 0)
        {
            if (now.nowPos == gps_log[0])
            {
                return now.cost;
            }
            else
            {
                continue;
            }
        }

        for (int& n : linked[now.nowPos])
        {
            int cost = (int)(n != gps_log[now.nowIndex - 1]);
            q.push(node{ now.cost + cost, now.nowIndex - 1, n });
        }
    }

    return -1;
}

//int main()
//{
//    solution(7, 10, vector<vector<int>>{ {1, 2}, { 1, 3 }, { 2, 3 }, { 2, 4 }, { 3, 4 }, { 3, 5 }, { 4, 6 }, { 5, 6 }, { 5, 7 }, { 6, 7 } }, 6, vector<int>{1, 2, 3, 3, 6, 7});
//}