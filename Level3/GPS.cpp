#include <vector>
#include <map>

using namespace std;

class Graph {    
    map<int, vector<bool>> graph;

public:
    Graph(int nodeCount)
    {
        for (int i = 0; i < nodeCount; ++i)
        {
            graph[i] = vector<bool>(nodeCount, false);
            graph[i][i] = true;
        }
    }

    void Link(int to, int from)
    {
        graph[to - 1][from - 1] = true;
        graph[from - 1][to - 1] = true;
    }

    const bool IsLinked(int to, int from)
    {
        return graph[to - 1][from - 1];
    }

    int GetLinkNextStations(int now, int next)
    {
        int result = 0;
        for (int station : graph[now])
        {
            for (int nextStation : graph[station])
            {
                if (IsLinked(nextStation, next))
                {
                    return nextStation;
                    //result.emplace_back(nextStation);
                }
            }
        }
        return result;
    }
};

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    int nowPos = 1;
    const int TO = 0;
    const int FROM = 1;

    Graph graph(n);
    for (const vector<int>& edge : edge_list)
    {
        graph.Link(edge[TO], edge[FROM]);
    }
    
    for (int i = 0; i < gps_log.size() - 2; ++i)
    {
        if (graph.IsLinked(nowPos, gps_log[i]))
        {
            nowPos = gps_log[i];
        }
        else
        {
            int abledNextStation = graph.GetLinkNextStations(gps_log[i - 1], gps_log[i + 1]);
            nowPos = abledNextStation;
            ++answer;
        }
    }

    return answer;
}

int main()
{
    solution(7, 10, vector<vector<int>>{ {1, 2}, { 1, 3 }, { 2, 3 }, { 2, 4 }, { 3, 4 }, { 3, 5 }, { 4, 6 }, { 5, 6 }, { 5, 7 }, { 6, 7 } }, 6, vector<int>{1, 2, 3, 3, 6, 7});
}