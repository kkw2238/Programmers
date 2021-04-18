#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    vector<int> enableStepping;

    for (int i = 0; i < stones.size() - k; ++i)
    {
        enableStepping.emplace_back(stones[i]);
        for (int j = 1; j < k; ++j)
        {
            if (i - j < 0)
            {
                break;
            }

            if (i - j >= 0 && enableStepping[i - j] < stones[i])
            {
                enableStepping[i - j] = stones[i];
            }
        }
    }

    if (enableStepping.empty())
    {
        return *max_element(stones.begin(), stones.end());
    }

    return *min_element(enableStepping.begin(), enableStepping.end());
}

#include <iostream>

int main()
{
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    int k = 10;

    cout << solution(stones, k) << '\n';
}