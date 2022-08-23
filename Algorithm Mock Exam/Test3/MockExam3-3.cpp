#include <vector>

using namespace std;

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    int startDist = 2147483647;

    for (int i = 0; i < scope.size(); ++i)
    {
        if (scope[i][0] > scope[i][1])
        {
            swap(scope[i][1], scope[i][0]);
        }
        for (int j = scope[i][0]; j <= scope[i][1]; ++j)
        {
            int totalTime = times[i][0] + times[i][1];
            if (j % totalTime > 0 && j % totalTime <= times[i][0])
            {
                if (startDist > j)
                {
                    startDist = j;
                }
            }
        }
    }

    if (startDist == 2147483647)
    {
        return distance;
    }

    return startDist;
}