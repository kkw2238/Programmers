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

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int OFFSET = 30001;
const int ROAD_DISTANCE = OFFSET * 2;

int getMaximumIndex(vector<int>& prefix, int minRange, int maxRange)
{
    int memprefix = 0;
    int maximum = 0;
    int maxIndex = -1;

    for (int i = minRange; i <= maxRange + 1; ++i)
    {
        memprefix += prefix[i];

        if (maximum < memprefix)
        {
            maximum = memprefix;
            maxIndex = i;
        }
    }

    return maxIndex;
}

struct Cmp
{
    const bool operator()(const vector<int>& a, const vector<int>& b) const
    {
        return a[0] < b[0];
    }
};

#include <iostream>


vector<vector<int>> init(multiset<vector<int>, Cmp>& road, int minRange, int maxRange)
{
    int range = maxRange - minRange;
    int tier = 0;
    int tmpRange = range;

    vector<vector<int>> tree;

    while (range > 1)
    {
        tree.push_back(vector<int>(range + (range % 2) + 1));
        range = range / 2 + (range % 2);
        ++tier;
    }
    tree.push_back(vector<int>(range + 1));

    for (const vector<int>& log : road)
    {
        int leftIndex = log[0] - minRange;
        int rightIndex = log[1] - minRange + 1;

        for (int i = 0; i < tier; ++i)
        {
            ++tree[i][leftIndex];
            --tree[i][rightIndex];

            leftIndex = leftIndex / 2;
            rightIndex = rightIndex / 2;
        }
    }

    for (vector<int>& vi : tree)
    {
        for (int i : vi)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return tree;
}

int findMaximum(vector<vector<int>>& tree)
{
    int maximum = -INT_MAX;
    int count = 0;
    int xIndex = 0, yIndex = 0;

    for (int y = tree.size() - 1; y >= 0; --y)
    {
        for (int x = 0; x < tree[y].size(); ++x)
        {
            if (tree[y][x] > maximum)
            {
                maximum = tree[y][x];
                xIndex = x;
                yIndex = y;
            }
        }
    }



}

int solution(vector<vector<int>> routes) {
    multiset<vector<int>, Cmp> road(routes.begin(), routes.end());
    int minRange = OFFSET;
    int maxRange = -OFFSET;

    for (vector<int>& route : routes)
    {
        minRange = min(minRange, route[0]);
        maxRange = max(maxRange, route[1] + 1);
    }

    vector<vector<int>> tree = init(road, minRange, maxRange);

    return 0;
}

#include <iostream>

int main()
{
    cout << solution({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }); //2
    cout << endl;
    cout << solution({ {-2, -1}, {1, 2}, {-3, 0} });//2
    cout << endl;
    cout << solution({ {0, 0}, });//1
    cout << endl;
    cout << solution({ {0, 1}, {0, 1}, {1, 2} });//1
    cout << endl;
    cout << solution({ {0, 1}, {2, 3}, {4, 5}, {6, 7} });//4
    cout << endl;
    cout << solution({ {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
    cout << endl;
    cout << solution({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
    cout << endl;
    cout << solution({ {2,2},{0,1},{-10,9} });//2
    cout << endl;
    cout << solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} });//4
    cout << endl;
    cout << solution({ {-5, -3}, {-4, 0}, {-4, -2}, {-1, 2}, {0, 3}, {1, 5}, {2, 4} });//2
    cout << endl;
    cout << solution({ {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15} });//8
    cout << endl;
    cout << solution({ {0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12} });//2
    cout << endl;
    cout << solution({ {-191, -107}, { -184,-151 }, { -150,-102 }, { -171,-124 }, { -120,-114 } }); // 2
    cout << endl;
}

