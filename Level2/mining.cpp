/*
	https://school.programmers.co.kr/learn/courses/30/lessons/172927
*/

#include <string>
#include <vector>

using namespace std;

const int FATIGUE[3][3]{
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1}
};

enum {DIAMOND, IRON, STONE};

int getFatigue(int pick, const vector<string>& minerals, int index)
{
    int result = 0;
    for (int i = index; i < (index + 5); ++i)
    {
        if (i >= minerals.size())
        {
            break;
        }

        switch (minerals[i][0])
        {
        case 'd':
            result += FATIGUE[pick][DIAMOND];
            break;
        case 'i':
            result += FATIGUE[pick][IRON];
            break;
        case 's':
            result += FATIGUE[pick][STONE];
            break;
        }
    }

    return result;
}

int calculateFatigue(vector<int>& picks, const vector<string>& minerals, int index)
{
    int result = 0;
    int tmpResult = INT_MAX;

    if (index < minerals.size())
    {
        for (int i = 0; i < 3; ++i)
        {
            if (picks[i] <= 0)
            {
                continue;
            }

            --picks[i];
            tmpResult = min(tmpResult, getFatigue(i, minerals, index) + calculateFatigue(picks, minerals, index + 5));
            result = tmpResult;
            ++picks[i];
        }
    }

    return result;
}

int solution(vector<int> picks, vector<string> minerals) {
    return calculateFatigue(picks, minerals, 0);
}