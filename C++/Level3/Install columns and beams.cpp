/*
	https://school.programmers.co.kr/learn/courses/30/lessons/60061
*/

#include <vector>
#include <set>

using namespace std;

enum TYPE{ COLUMN = 1, BEAM = 2 };

bool isAbleBuild(vector<vector<int>>& graph, int x, int y, int objectType)
{
    switch (objectType)
    {
    case COLUMN:
        return y == 0 || graph[y - 1][x] % 2 == COLUMN || (graph[y][x - 1] >= BEAM || graph[y][x] >= BEAM);
    case BEAM:
        return ((x > 0 && graph[y][x - 1] >= BEAM) && graph[y][x + 1] >= BEAM) || graph[y - 1][x] % 2 == COLUMN || graph[y - 1][x + 1] % 2 == COLUMN;
    }
}

bool isAbleErase(vector<vector<int>>& graph, set<pair<int, int>>& buildings, int index, int objectType)
{
    for (const pair<int, int>& buildPos : buildings)
    {
        if (graph[buildPos.second][buildPos.first] % 2 == COLUMN && !isAbleBuild(graph, buildPos.first, buildPos.second, COLUMN))
        {
            return false;
        }
        if (graph[buildPos.second][buildPos.first] >= BEAM && !isAbleBuild(graph, buildPos.first, buildPos.second, BEAM))
        {
            return false;
        }
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> graph(n + 2, vector<int>(n + 2, 0));
    vector<vector<int>> answer;
    set<pair<int, int>> buildings;

    for (int i = 0; i < build_frame.size(); ++i)
    {
        int objectType = build_frame[i][2] + 1;
        
        if (build_frame[i][3] == 0)
        {
            graph[build_frame[i][1]][build_frame[i][0]] -= objectType;
            if (!isAbleErase(graph, buildings, i, objectType))
            {
                graph[build_frame[i][1]][build_frame[i][0]] += objectType;
            }
            else if (graph[build_frame[i][1]][build_frame[i][0]] == 0)
            {
                buildings.erase(pair(build_frame[i][0], build_frame[i][1]));
            }
        }
        else if (build_frame[i][3] == 1)
        {
            if (isAbleBuild(graph, build_frame[i][0], build_frame[i][1], objectType))
            {
                graph[build_frame[i][1]][build_frame[i][0]] += objectType;
                buildings.insert(pair(build_frame[i][0], build_frame[i][1]));
            }
        }
    }

    for (int x = 0; x <= n; ++x)
    {
        for (int y = 0; y <= n; ++y)
        {
            if (graph[y][x] % 2 == 1)
            {
                answer.push_back({ x, y, 0 });
            }
            if (graph[y][x] >= 2)
            {
                answer.push_back({ x, y, 1 });
            }
        }
    }

    return answer;
}