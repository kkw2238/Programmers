/*
	https://programmers.co.kr/learn/courses/30/lessons/42884
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int OFFSET = 30001;
#include <iostream>

int getMaximumIndex(vector<int>& prefix, int minRange, int maxRange)
{
    vector<int> calprefix = vector<int>(60002);
    int memprefix = 0;
    int maximum = 0;
    int maxIndex = -1;

    for (int i = minRange + 1; i <= maxRange + 1; ++i)
    {
        calprefix[i] += calprefix[i - 1] + prefix[i - 1];

        cout << calprefix[i] << ' ';
        if (maximum < calprefix[i])
        {
            maximum = calprefix[i];
            maxIndex = i;
        }
    }
    cout << " : " << maxIndex - OFFSET << '\n';
    return maxIndex;
}


int solution(vector<vector<int>> routes) {
    vector<vector<int>> roadIndex(60002, vector<int>());
    vector<int> prefix(60002, 0);
    int minRange = 60002;
    int maxRange = -60002;

    int answer = 0;
    
    for (int i = 0 ; i < routes.size(); ++i)
    {
        routes[i][0] += OFFSET;
        routes[i][1] += OFFSET;

        for (int j = routes[i][0]; j <= routes[i][1]; ++j)
        {
            roadIndex[j].push_back(i);
        }

        minRange = min(routes[i][0] - 1, minRange);
        maxRange = max(routes[i][1] + 1, maxRange);

        ++prefix[routes[i][0] - 1];
        --prefix[routes[i][1] + 1];
    }

    int maxIndex = getMaximumIndex(prefix, minRange, maxRange);

    while (maxIndex > -1)
    {
        for (int index : roadIndex[maxIndex])
        {
            
            if (prefix[routes[index][0] - 1] > 0) 
            {
                --prefix[routes[index][0] - 1];
            }
            if (prefix[routes[index][1] + 1] < 0)
            {
                ++prefix[routes[index][1] + 1];
            }
            int i = 0;
        }

        maxIndex = getMaximumIndex(prefix, minRange, maxRange);
        ++answer;
    }

    return answer;
}

int main()
{
    solution({ { -20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });
}