/*
	https://school.programmers.co.kr/learn/courses/30/lessons/258711
*/

#include <vector>
#include <map>
#include <set>

using namespace std;

int DFS(map<int, vector<int>>& link, map<int, vector<int>>& rLink, int start, int nowIndex)
{
    if (link[nowIndex].size() >= 2)
    {
        return 3;
    }
    
    for (int i : link[nowIndex])
    {
        if (i == start)
        {
            return 1;
        }
        else
        {
            return DFS(link, rLink, start, i);
        }
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
        if (reverseLink.find(v) == reverseLink.end())
        {
            answer[0] = v;
            break;
        }
    }

    for (int next : link[answer[0]])
    {
        int type = DFS(link, reverseLink, next, next);
        ++answer[type];
    }

    return answer;
}