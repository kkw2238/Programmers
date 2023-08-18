/*
	https://school.programmers.co.kr/learn/courses/30/lessons/60062
*/

#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int result = 2147483647;
int totalRange = 0;

void DFS(vector<int>& weak, int weakIndex, int clearCount, vector<int>& dist, int distIndex)
{
    if (clearCount >= weak.size())
    {
        result = min(result, distIndex);
        return;
    }
    else if (distIndex == dist.size())
    {
        return;
    }
    for (int i = distIndex; i < dist.size(); ++i)
    {
        int startIndex = weak[weakIndex];
        int tmpWeakIndex = weakIndex + 1;
        int tmpClearcount = clearCount + 1;

        swap(dist[i], dist[distIndex]);
        for (; tmpWeakIndex <= weakIndex + 1 + weak.size(); ++tmpWeakIndex)
        {
            int d = weak[tmpWeakIndex % weak.size()] - startIndex;
            if (d < 0)
            {
                d += totalRange;
            }
            if (d > dist[distIndex])
            {
                break;
            }
            ++tmpClearcount;
        }
        DFS(weak, tmpWeakIndex % weak.size(), tmpClearcount, dist, distIndex + 1);
        swap(dist[i], dist[distIndex]);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    vector<int> rWeak = weak;
    reverse(rWeak.begin(), rWeak.end());
    totalRange = n;

    for (int i = 0; i < weak.size(); ++i)
    {
        DFS(weak, i, 0, dist, 0);
        DFS(rWeak, i, 0, dist, 0);
    }

    if (result == 2147483647)
    {
        return -1;
    }
    return result;
}