/*
    https://programmers.co.kr/learn/courses/30/lessons/87946?language=cpp
*/

#include <vector>
#include <algorithm>

using namespace std;

enum { NEED, CONSUME };

int maximum = -5000;

int TryToDungeons(int tiredness, int count, vector<vector<int>>& dungeons, vector<bool> alreadyTryDungeons)
{
    int n = 0;

    if (dungeons[0][NEED] > tiredness)
    {
        return count;
    }

    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (!alreadyTryDungeons[i] && tiredness >= dungeons[i][NEED])
        {
            alreadyTryDungeons[i] = true;
            int total = TryToDungeons(tiredness - dungeons[i][CONSUME], count + 1, dungeons, alreadyTryDungeons);
            alreadyTryDungeons[i] = false;

            n = max(total, n);
        }
    }

    return n;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> alreadyTryDungends(dungeons.size(), false);
    sort(dungeons.begin(), dungeons.end(), [](auto& a, auto& b) {
        return a[NEED] > b[NEED];
    });

    return TryToDungeons(k, 0, dungeons, alreadyTryDungends);
}

