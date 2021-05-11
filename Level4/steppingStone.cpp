#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    rocks.emplace_back(0);
    rocks.emplace_back(distance);
    sort(rocks.begin(), rocks.end());

    list<pair<int, int>> distanceBeforeNext;
    
    for (int i = 0; i < rocks.size(); ++i)
    {
        if (i == 0)
        {
            distanceBeforeNext.emplace_back(pair(rocks[i], rocks[i + 1] * 2));
        }
        else if (i == rocks.size() - 1)
        {
            distanceBeforeNext.emplace_back(pair(rocks[i], (distance - rocks[i - 1]) * 2));
        }
        else
        {
            distanceBeforeNext.emplace_back(pair(rocks[i], rocks[i + 1] - rocks[i - 1]));
        }
    }

    for (int i = 0; i < n; ++i)
    {
        auto eraseIter = min_element(distanceBeforeNext.begin(), distanceBeforeNext.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        int dist = std::distance(distanceBeforeNext.begin(), eraseIter);

        if (dist == 0)
        {
            (*distanceBeforeNext.begin()).second = (*(++eraseIter)).second * 2;
            distanceBeforeNext.erase(eraseIter);
        }
        else if(dist == distanceBeforeNext.size() - 1)
        {
            auto endIter = distanceBeforeNext.end();
            --endIter;
            --eraseIter;

            (*endIter).second = (*eraseIter).second * 2;
            distanceBeforeNext.erase(eraseIter);
        }
        else
        {

        }
    }
    return (*min_element(distanceBeforeNext.begin(), distanceBeforeNext.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    })).second;
}

#include <iostream>

int main() {
    int distance = 25;
    vector<int> rocks = { 2, 14, 11, 21, 17 };
    int n = 2;
    
    cout << solution(distance, rocks, n);
}