/*
	https://school.programmers.co.kr/learn/courses/30/lessons/152996
*/

#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long count = 0;
    map<int, long long> weightToIndex;

    for (const int& weight : weights)
    {
        ++weightToIndex[weight];
    }

    for (const auto& iter : weightToIndex)
    {
        int nowWeight = iter.first;

        count += (weightToIndex[nowWeight] * (weightToIndex[nowWeight] - 1)) / (long long)2;

        for (int i = 2; i <= 4; ++i)
        {
            for (int j = i + 1; j <= 4; ++j)
            {
                int pairWeight = nowWeight * i;

                if (pairWeight % j == 0)
                {
                    if (weightToIndex.find(pairWeight / j) != weightToIndex.end())
                    {
                        count += (weightToIndex[pairWeight / j]) * weightToIndex[nowWeight];
                    }
                }
            }
        }
    }

    return count;
}