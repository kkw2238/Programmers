/*
	https://school.programmers.co.kr/learn/courses/30/lessons/258711
*/

#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

int Search(map<int, vector<int>>& link, map<int, vector<int>>& reverseLink, int start)
{
    queue<int> index;
    int edgeCount = 0, vertexCount = 0;
    index.push(start);

    int now = start;
    while (!index.empty())
    {
        now = index.front();
        index.pop();

        ++vertexCount;
        edgeCount += link[now].size();

        if (link[now].size() >= 2)
        {
            return 3;
        }
        else if (link[now].empty())
        {
            return 2;
        }
        if (link[now][0] == start)
        {
            return 1;
        }
        index.push(link[now][0]);
    }

    return 2;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    set<int> vertices;
    map<int, vector<int>> link, reverseLink;
 
    for (vector<int>& edge : edges)
    {
        link[edge[0]].push_back(edge[1]);
        reverseLink[edge[1]].push_back(edge[0]);

        vertices.insert(edge[0]);
        vertices.insert(edge[1]);
    }

    for (int v : vertices)
    {
        if (reverseLink[v].empty() && link[v].size() > 1)
        {
            answer[0] = v;
            break;
        }
    }

    for (int next : link[answer[0]])
    {
        int type = Search(link, reverseLink, next);
        ++answer[type];
    }

    return answer;
}