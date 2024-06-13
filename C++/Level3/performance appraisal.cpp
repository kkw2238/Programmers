/*
	https://school.programmers.co.kr/learn/courses/30/lessons/152995
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isAbleIncentive(const vector<int>& myScores, const vector<int>& other)
{
    return (myScores[0] >= other[0]) || (myScores[1] >= other[1]);
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int myScore = scores[0][0] + scores[0][1];

    sort(scores.begin() + 1, scores.end(), [](vector<int>& a, vector<int>& b) {
        return (a[0] + a[1]) > (b[0] + b[1]);
        });

    for (int i = 1; i < scores.size(); ++i)
    {
        int sumScore = scores[i][0] + scores[i][1];

        if (myScore >= sumScore)
        {
            return answer;
        }

        if (!isAbleIncentive(scores[0], scores[i]))
        {
            return -1;
        }

        for (int j = 1; j < i; ++j)
        {
            if (!isAbleIncentive(scores[i], scores[j]))
            {
                --answer;
                break;
            }
        }

        ++answer;
    }

    return answer;
}

