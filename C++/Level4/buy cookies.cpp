/*
    https://school.programmers.co.kr/learn/courses/30/lessons/49995
*/

#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0, sumL = 0;
    vector<int> totalSum(cookie.size() + 1, 0);

    for (int l = 1; l <= cookie.size(); ++l)
    {
        sumL += cookie[l - 1];
        totalSum[l] = sumL;
    }

    for (int m = 1; m <= cookie.size(); ++m)
    {
        for (int l = m; l >= 1; --l)
        {
            int sumLM = (totalSum[m] - totalSum[l - 1]);
            if (sumLM <= answer)
            {
                break;
            }
            else if (sumLM > (totalSum[cookie.size()] - totalSum[m - 1]))
            {
                continue;
            }

            for (int r = m + 1; r <= cookie.size(); ++r)
            {
                if ((totalSum[m] - totalSum[l - 1]) == (totalSum[r] - totalSum[m]))
                {
                    answer = max(answer, (totalSum[m] - totalSum[l - 1]));
                }
            }
        }
    }

    return answer;
}