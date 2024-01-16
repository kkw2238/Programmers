/*
	https://school.programmers.co.kr/learn/courses/30/lessons/258709?language=cpp
*/

#include <vector>
#include <bitset>
#include <set>
#include <map>

using namespace std;

void combination(vector<vector<int>>& dice, vector<int>& pos, int index, set<int>& s, map<int, int>& c, int nowSum)
{
    if (index == dice.size() / 2)
    {
        s.insert(nowSum);
        ++c[nowSum];
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
        combination(dice, pos, index + 1, s, c, nowSum + dice[pos[index]][i]);
    }
}

pair<int, int> getWinCount(set<int>& sumL, map<int, int>& lCount, set<int>& sumR, map<int, int>& rCount)
{
    int winc = 0;
    int samec = 0;

    for (int i : sumL)
    {
        for (auto m : rCount)
        {
            if (m.first < i)
            {
                winc += m.second * lCount[i];
            }
            else if (m.first == i)
            {
                samec += m.second * lCount[i];
            }
            else
            {
                break;
            }
        }
    }

    return pair<int, int>(winc, samec);
}

int search(vector<vector<int>>& dice, vector<int>& lists, vector<vector<int>>& pos)
{
    int maximumIndex = pow(2, dice.size()) - 1;
    int maximum = 0, index = 0;

    vector<int> winCount(maximumIndex + 1 , -1);

    for (int i = 0; i < lists.size(); ++i)
    {
        if (winCount[lists[i]] >= 0)
        {
            continue;
        }

        set<int> sumL, sumR;
        map<int, int> sumCountL, sumCountR;
        int otherSide = maximumIndex - lists[i];

        combination(dice, pos[lists[i]], 0, sumL, sumCountL, 0);
        combination(dice, pos[otherSide], 0, sumR, sumCountR, 0);

        pair<int, int> c = getWinCount(sumL, sumCountL, sumR, sumCountR);

        winCount[lists[i]] = c.first;
        winCount[otherSide] = pow(6, dice.size()) - c.first - c.second;

        if (winCount[lists[i]] > maximum)
        {
            index = lists[i];
            maximum = winCount[lists[i]];
        }
        else if (winCount[otherSide] > maximum)
        {
            index = otherSide;
            maximum = winCount[otherSide];
        }
    }

    return index;
}

vector<int> solution(vector<vector<int>> dice) {
    int maximumIndex = pow(2, dice.size());
    int minimumIndex = pow(2, dice.size() / 2) - 1;

    vector<vector<int>> position(maximumIndex);
    vector<vector<int>> answer(maximumIndex);
    vector<int> lists;

    for (int i = minimumIndex; i < maximumIndex; ++i)
    {
        bitset<10> bs(i);
        
        if (bs.count() == dice.size() / 2)
        {
            for (int j = 0; j < dice.size(); ++j)
            {
                if (bs[j] == 1)
                {
                    position[i].push_back(j);
                    answer[i].push_back(j + 1);
                }
            }

            lists.push_back(i);
        }
    }

    int index = search(dice, lists, position);
    return position[index];
}