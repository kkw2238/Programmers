/*
    https://programmers.co.kr/learn/courses/30/lessons/81302?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

const int SIZE = 5;
const int LIMIT = 2;

const int Abs(const int num)
{
    return num > 0 ? num : -num;
}

const int Manhattan(const pair<int, int>& a, const pair<int, int>& b)
{
    return Abs(a.first - b.first) + Abs(a.second - b.second);
}

const bool SameLine(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first == b.first || a.second == b.second;
}

const int AbleSeat(const vector<pair<int, int>>& candidates, const vector<string>& room)
{
    for (int i = 0; i < candidates.size(); ++i)
    {
        for (int j = i + 1; j < candidates.size(); ++j)
        {
            if (Manhattan(candidates[i], candidates[j]) > LIMIT)
            {
                continue;
            }

            if (SameLine(candidates[i], candidates[j]))
            {
                pair<int, int> mid = pair((candidates[i].first + candidates[j].first) / 2, (candidates[i].second + candidates[j].second) / 2);

                if (room[mid.second][mid.first] != 'X')
                {
                    return 0;
                }
            }
            else
            {
                pair<int, int> offset = pair(candidates[j].first - candidates[i].first, candidates[j].second - candidates[i].second);

                if (room[candidates[i].second + offset.second][candidates[i].first] != 'X' || room[candidates[i].second][candidates[i].first + offset.first] != 'X')
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(places.size(), 1);

    for (int roomNo = 0; roomNo < SIZE; ++roomNo) 
    {
        vector<pair<int, int>> candidates;

        for (int y = 0; y < SIZE; ++y)
        {
            for (int x = 0; x < SIZE; ++x)
            {
                if (places[roomNo][y][x] == 'P')
                {
                    candidates.emplace_back(x, y);
                }
            }
        }

        answer[roomNo] = AbleSeat(candidates, places[roomNo]);
    }

    return answer;
}