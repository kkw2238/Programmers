/*
	https://programmers.co.kr/learn/courses/30/lessons/42884
*/



//int solution(vector<vector<int>> routes) {
//    vector<vector<int>> roadIndex(ROAD_DISTANCE, vector<int>());
//    vector<int> prefix(ROAD_DISTANCE, 0);
//    int minRange = ROAD_DISTANCE;
//    int maxRange = -ROAD_DISTANCE;
//    int answer = 0;
//    
//    for (int i = 0 ; i < routes.size(); ++i)
//    {
//        routes[i][0] += OFFSET;
//        routes[i][1] += OFFSET;
//
//        for (int j = routes[i][0]; j <= routes[i][1]; ++j)
//        {
//            roadIndex[j].push_back(i);
//        }
//
//        minRange = min(routes[i][0] - 1, minRange);
//        maxRange = max(routes[i][1] + 1, maxRange);
//
//        ++prefix[routes[i][0]];
//        --prefix[routes[i][1] + 1];
//    }
//
//    int maxIndex = getMaximumIndex(prefix, minRange, maxRange);
//
//    while (maxIndex > -1)
//    {
//        for (int index : roadIndex[maxIndex])
//        {
//            if (prefix[routes[index][0]] > 0) 
//            {
//                --prefix[routes[index][0]];
//                ++prefix[routes[index][1] + 1];
//            }
//        }
//
//        ++answer;
//        maxIndex = getMaximumIndex(prefix, minRange, maxRange);
//    }
//
//    return answer;
//}


//int getMaximumIndex(vector<int>& prefix, int minRange, int maxRange)
//{
//    int memprefix = 0;
//    int maximum = 0;
//    int maxIndex = -1;
//
//    for (int i = minRange; i <= maxRange + 1; ++i)
//    {
//        memprefix += prefix[i];
//
//        if (maximum < memprefix)
//        {
//            maximum = memprefix;
//            maxIndex = i;
//        }
//    }
//
//    return maxIndex;
//}
//
//struct Cmp
//{
//    const bool operator()(const vector<int>& a, const vector<int>& b) const
//    {
//        return a[0] < b[0];
//    }
//};
//
//#include <iostream>
//
//
//vector<vector<int>> init(multiset<vector<int>, Cmp>& road, int minRange, int maxRange)
//{
//    int range = maxRange - minRange;
//    int tier = 0;
//    int tmpRange = range;
//
//    vector<vector<int>> tree;
//
//    while (range > 1)
//    {
//        tree.push_back(vector<int>(range + (range % 2) + 1));
//        range = range / 2 + (range % 2);
//        ++tier;
//    }
//    tree.push_back(vector<int>(range + 1));
//
//    for (const vector<int>& log : road)
//    {
//        int leftIndex = log[0] - minRange;
//        int rightIndex = log[1] - minRange + 1;
//
//        for (int i = 0; i < tier; ++i)
//        {
//            ++tree[i][leftIndex];
//            --tree[i][rightIndex];
//
//            leftIndex = leftIndex / 2;
//            rightIndex = rightIndex / 2;
//        }
//    }
//
//    for (vector<int>& vi : tree)
//    {
//        for (int i : vi)
//        {
//            cout << i << ' ';
//        }
//        cout << '\n';
//    }
//
//    return tree;
//}

#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct Cmp
{
    const bool operator()(const vector<int>& a, const vector<int>& b) const
    {
        return a[0] < b[0];
    }
};

int getMaximumIndex(multiset<vector<int>, Cmp>& sorted_routes)
{
    priority_queue<int> exitIndices;
    int count = 0;
    int maximum_index = 0;
    int maximum_count = 0;

    for (const vector<int>& route : sorted_routes)
    {
        int startIndex = route[0];
        int exitIndex = route[1];

        while (!exitIndices.empty() && exitIndices.top() < startIndex)
        {
            exitIndices.pop();
            --count;
        }

        exitIndices.push(exitIndex);
        ++count;

        if (count > maximum_count)
        {
            maximum_count = count;
            maximum_index = startIndex;
        }
    }

    return maximum_index;
}

const bool isInside(const vector<int>& range, int index)
{
    return range[0] <= index && range[1] >= index;
}

void eraseDetectedCar(multiset<vector<int>, Cmp>& sorted_routes, int index)
{
    for (auto iter = sorted_routes.begin(); iter != sorted_routes.end();)
    {
        vector<int> route = *iter;

        if (route[0] > index)
        {
            break;
        }
        else if (isInside(route, index))
        {
            auto tmpIter = iter++;
            sorted_routes.erase(tmpIter);
        }
        else
        {
            ++iter;
        }
    }
}

int solution(vector<vector<int>> routes) {
    multiset<vector<int>, Cmp> sorted_routes(routes.begin(), routes.end());
    int count = 0;

    while (!sorted_routes.empty())
    {
        int index = getMaximumIndex(sorted_routes);
        eraseDetectedCar(sorted_routes, index);
        ++count;
    }

    return count;
}