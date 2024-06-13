/*
	https://programmers.co.kr/learn/courses/30/lessons/85002?language=cpp
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Boxer
{
    int winCount = 0;
    int winHeavy = 0;
    int matchCount = 0;
    int myNumber = 0;
    int myWeight = 0;
    double winRate = 0.0;

    const bool operator<(const Boxer& other)
    {
        if (winCount != other.winCount)
        {
            return winCount > other.winCount;
        }
        else if (winHeavy != other.winHeavy)
        {
            return winHeavy > other.winHeavy;
        }
        else if (myWeight != other.myWeight)
        {
            return winHeavy > other.winHeavy;
        }
        return myNumber < other.myNumber;
    }
};

vector<int> solution(vector<int> weights, vector<string> head2head) {
    const int BOXER_COUNT = weights.size();

    vector<int> answer;
    vector<Boxer> boxers(weights.size());

    for (int i = 0; i < BOXER_COUNT; ++i)
    {
        boxers[i].myNumber = i + 1;
        boxers[i].myWeight = weights[i];

        for (int j = i + 1; j < BOXER_COUNT; ++j)
        {
            switch (head2head[i][j])
            {
            case 'W':
                ++boxers[i].winCount;
                ++boxers[i].matchCount;
                ++boxers[j].matchCount;

                if (weights[i] < weights[j])
                {
                    ++boxers[i].winHeavy;
                }
                break;
            case 'L':
                ++boxers[j].winCount;
                ++boxers[i].matchCount;
                ++boxers[j].matchCount;

                if (weights[i] > weights[j])
                {
                    ++boxers[j].winHeavy;
                }
                break;
            }
        }

        if (boxers[i].matchCount > 0) 
        {
            boxers[i].winRate = (double)boxers[i].winCount / (double)boxers[i].matchCount;
        }
    }

    sort(boxers.begin(), boxers.end());

    for (int i = 0; i < BOXER_COUNT; ++i)
    {
        answer.emplace_back(boxers[i].myNumber);
    }
    
    return answer;
}