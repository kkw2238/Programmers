/*
	https://school.programmers.co.kr/learn/courses/30/lessons/60061
*/

#include <string>
#include <vector>

using namespace std;

enum TYPE{ COLUMN = 1, BEAM = 2 };

/*
    보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
*/

bool isAbleBuild(vector<vector<int>>& graph, int n, int x, int y, int objectType)
{
    switch (objectType)
    {
    case 0:
        return y == 0 || graph[y - 1][x] == COLUMN || (graph[y][x - 1] >= BEAM || graph[y][x] >= BEAM);
    case 1:
        return ((graph[y][x - 1] % 2 == BEAM && graph[y][x + 1] % 2 == BEAM) || graph[y - 1][x] >= COLUMN || graph[y - 1][x + 1] >= COLUMN);
    }
}

bool isAbleErase(vector<vector<int>>& graph, vector<vector<int>>& build_frame, int index, int n, int objectType)
{
    for (int i = 0; i < index; ++i)
    {
        
        if(isAbleBuild()
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> answer;

    for (vector<int>& build : build_frame)
    {
        int index = build[0] + build[1] * (n + 1);
        int objectType = build[2];
        
        if (build[3] == 0)
        {

        }
        else if (build[3] == 1)
        {

        }
    }

    return answer;
}