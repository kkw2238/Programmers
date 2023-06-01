/*
	https://school.programmers.co.kr/learn/courses/30/lessons/132266
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Compair
{
public:
    constexpr bool operator()(const pair<int, int>& _Left, const pair<int, int>& _Right) const {
        return _Left.second > _Right.second;
    }
};

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> range = vector<int>(n + 1, -1);
    vector<vector<int>> lines = vector<vector<int>>(n + 1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compair> q;

    for (vector<int>& road : roads)
    {
        lines[road[0]].push_back(road[1]);
        lines[road[1]].push_back(road[0]);
    }

    q.push(pair(destination, 0));

    while (!q.empty())
    {
        int now = q.top().first;
        int step = q.top().second;

        q.pop();

        if (range[now] != -1 && range[now] <= step)
        {
            continue;
        }

        range[now] = step;

        for (int i : lines[now])
        {
            if (range[i] != -1 && range[i] <= (step + 1))
            {
                continue;
            }
            q.push(pair(i, step + 1));
        }
    }

    for (int s : sources)
    {
        answer.push_back(range[s]);
    }

    return answer;
}