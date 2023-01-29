/*
	https://school.programmers.co.kr/learn/courses/30/lessons/154540?language=cpp
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int DIR_X[4]{ -1, 0, 1, 0 };
const int DIR_Y[4]{ 0, -1, 0, 1 };

bool isAbleTravel(const char c)
{
    return c != '0' && c != 'X';
}

int travel(vector<string>& maps, int y, int x)
{
    int result = 0;

    if ((y < 0 || y >= maps.size()) || (x < 0 || x >= maps.front().size()))
    {
        return result;
    }

    if (!isAbleTravel(maps[y][x]))
    {
        return result;
    }

    result += maps[y][x] - '0';
    maps[y][x] = '0';

    for (int i = 0; i < 4; ++i)
    {
        result += travel(maps, y + DIR_Y[i], x + DIR_X[i]);
    }

    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    for (int y = 0; y < maps.size(); ++y)
    {
        for (int x = 0; x < maps[y].size(); ++x)
        {
            if (isAbleTravel(maps[y][x]))
            {
                answer.emplace_back(travel(maps, y, x));
            }
        }
    }

    if (answer.empty())
    {
        answer.emplace_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end(), greater<int>());
    }
    return answer;
}