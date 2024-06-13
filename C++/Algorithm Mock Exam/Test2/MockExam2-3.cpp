#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> distanceToDestination;

void GenerationMap(map<int, vector<int>>& roadInIsland, int destination)
{
    queue<int> nextIndex;

    for (const int road : roadInIsland[destination])
    {
        nextIndex.push(road);
        distanceToDestination[road] = 1;
    }

    while (!nextIndex.empty())
    {
        int now = nextIndex.front();
        nextIndex.pop();

        for (const int road : roadInIsland[now])
        {
            if (distanceToDestination[road] > (distanceToDestination[now] + 1))
            {
                nextIndex.push(road);
                distanceToDestination[road] = (distanceToDestination[now] + 1);
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    map<int, vector<int>> roadInIsland;

    distanceToDestination = vector<int>(n, 2147483647);
    distanceToDestination[destination] = 0;
    
    for (const vector<int>& road : roads)
    {
        roadInIsland[road[0]].push_back(road[1]);
        roadInIsland[road[1]].push_back(road[0]);
    }

    GenerationMap(roadInIsland, destination);
    
    for (int source : sources)
    {
        int distance = distanceToDestination[source];

        if (distance == 2147483647)
        {
            distance = -1;
        }

        answer.push_back(distance);
    }
    return answer;
}