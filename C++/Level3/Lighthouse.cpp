/*
	https://school.programmers.co.kr/learn/courses/30/lessons/133500?language=cpp
*/

//#include <vector>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//struct node {
//    queue<int> linkLighthouse;
//
//    void insert(int index)
//    {
//        linkLighthouse.push(index);
//    }
//};
//
//int rebuild(queue<int>& q, vector<bool>& u)
//{
//    queue<int> tq;
//
//    while (!q.empty())
//    {
//        int n = q.front();
//        q.pop();
//
//        if (!u[n])
//        {
//            tq.push(n);
//        }
//    }
//
//    q = tq;
//    return q.size();
//}
//
//int turnOn(queue<int>& q, vector<bool>& u)
//{
//    while (!q.empty())
//    {
//        int n = q.front();
//        q.pop();
//
//        u[n] = true;
//    }
//
//    return q.size();
//}
//
//int solution(int n, vector<vector<int>> lighthouse) {
//    int answer = 0, lightCount = 0;
//    map<int, queue<int>> linkCounts;
//    vector<node> graph = vector<node>(n);
//    vector<bool> unionNode = vector<bool>(n, false);
//    vector<bool> skip = vector<bool>(n, false);
//
//    for (vector<int>& h : lighthouse)
//    {
//        graph[h[0] - 1].insert(h[1] - 1);
//        graph[h[1] - 1].insert(h[0] - 1);
//    }
//
//    for (int i = 0; i < n; ++i)
//    {
//        graph[i].linkLighthouse.push(i);
//        linkCounts[graph[i].linkLighthouse.size()].push(i);
//    }
//
//    for (int i = n; i >= 0; --i)
//    {
//        if (linkCounts[i].empty())
//        {
//            continue;
//        }
//
//        while (!linkCounts[i].empty())
//        {
//            int index = linkCounts[i].front();
//            linkCounts[i].pop();
//
//            int rebuildCount = rebuild(graph[index].linkLighthouse, unionNode);
//
//            if (rebuildCount != i)
//            {
//                linkCounts[rebuildCount].push(index);
//                continue;
//            }
//            else
//            {
//                lightCount += turnOn(graph[index].linkLighthouse, unionNode);
//                ++answer;
//            }
//
//            if (lightCount == n)
//            {
//                return answer;
//            }
//        }
//    }
//
//    return answer;
//}
//
//void main()
//{
//    solution(10, { {4, 1}, {5, 1}, {5, 6}, {7, 6}, {1, 2}, {1, 3}, {6, 8}, {2, 9}, {9, 10} });
//
//}

#include <vector>
#include <set>

using namespace std;

struct node {
    set<int> children;
    int parents = 0;
    bool isLeaf = false, isLight = false;
    bool turnOn = false;

    void insert(int index)
    {
        children.insert(index);
    }

    void link(vector<node>& graph, int now, int p)
    {
        parents = p;
        children.erase(p);
        isLeaf = children.empty();

        if (!isLeaf)
        {
            for (int i : children)
            {
                graph[i].link(graph, i, now);
            }
        }
    }
};

int turnOnCount = 0;

void turnOn(vector<node>& graph, int index)
{
    graph[index].turnOn = true;
    graph[index].isLight = true;

    for (int i : graph[index].children)
    {
        graph[i].turnOn = true;
    }

    graph[graph[index].parents].turnOn = true;
    ++turnOnCount;
}

void DFS(vector<node>& graph, int index)
{
    int counts = 0;
    bool isNeedTurnOn = true;
    bool isLight = true;
    if (graph[index].isLeaf)
    {
        if (!graph[index].turnOn)
        {
            turnOn(graph, graph[index].parents);
        }
        return;
    }

    for (int n : graph[index].children)
    {
        DFS(graph, n);

        isNeedTurnOn &= graph[n].turnOn;
        isLight &= graph[n].isLight;
    }

    if (!isNeedTurnOn || (isNeedTurnOn && !isLight && !graph[index].isLight))
    {
        turnOn(graph, index);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    vector<node> graph = vector<node>(n);

    for (vector<int>& h : lighthouse)
    {
        graph[h[0] - 1].insert(h[1] - 1);
        graph[h[1] - 1].insert(h[0] - 1);
    }

    graph[0].link(graph, 0, 0);
    DFS(graph, 0);

    if (!graph[0].turnOn)
    {
        turnOn(graph, 0);
    }

    return turnOnCount;
}
