/*
	https://school.programmers.co.kr/learn/courses/30/lessons/152996
*/

#include <vector>
#include <map>

using namespace std;


#include <iostream>

long long solution(vector<int> weights) {
    long long count = 0;
    map<int, long long> weightToIndex;

    for (int i = 0; i < weights.size(); ++i)
    {
        ++weightToIndex[weights[i]];
    }

    for (auto& iter : weightToIndex)
    {
        int nowWeight = iter.first;

        count += (weightToIndex[nowWeight] * (weightToIndex[nowWeight] - 1)) / (long long)2;

        for (int j = 1; j <= 4; ++j)
        {
            for (int i = j + 1; i <= 4; ++i)
            {
                if (j == 2 && i == 4)
                {
                    continue;
                }

                if (nowWeight % j == 0)
                {
                    if (weightToIndex.find((nowWeight * i) / j) != weightToIndex.end())
                    {
                        count += weightToIndex[(nowWeight * i) / j] * weightToIndex[nowWeight];
                    }
                }
            }
        }
    }

    return count;
}


int main()
{
    vector<int> vi;
    for (int i = 1; i <= 100000; ++i)
    {
        vi.emplace_back(i);

        cout << i << ' ' << solution(vi) << '\n';
    }
}