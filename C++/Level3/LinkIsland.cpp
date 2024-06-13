#include <vector>
#include <algorithm>
#include <map>

using namespace std;

enum { START, DEST, COST };

bool Link(map<int, vector<bool>>& linkIsland, int start, int dest)
{
    vector<bool> unioned = vector<bool>(linkIsland[start].size());

    for (int i = 0; i < unioned.size(); ++i)
    {
        unioned[i] = linkIsland[start][i] || linkIsland[dest][i];
    }

    unioned[start] = true;
    unioned[dest] = true;

    linkIsland[start] = unioned;
    linkIsland[dest] = unioned;
 
    for (auto& [island, isLinked] : linkIsland)
    {
        if (isLinked[start] || isLinked[dest])
        {
            copy(unioned.begin(), unioned.end(), isLinked.begin());
        }
    }

    return count_if(unioned.begin(), unioned.end(), [](const bool a) { return a; }) == unioned.size();
}

int solution(int n, vector<vector<int>> costs) {
    map<int, vector<bool>> alreadyLink;
    int answer = 0;

    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
        return a[COST] < b[COST];
    });

    for (int i = 0; i < n; ++i)
    {
        alreadyLink[i] = vector<bool>(n, false);
    }

    for (const vector<int>& cost : costs)
    {
        if (!alreadyLink[cost[START]][cost[DEST]])
        {
            answer += cost[COST];
            if (Link(alreadyLink, cost[START], cost[DEST]))
            {
                return answer;
            }
        }
    }

    return answer;
}