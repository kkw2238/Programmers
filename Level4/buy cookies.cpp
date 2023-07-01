/*
    https://school.programmers.co.kr/learn/courses/30/lessons/49995
*/

#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int sumL = 0;
    vector<vector<int>> totalSum(cookie.size() + 1, vector<int>(cookie.size() + 1));

    for (int n = 1; n <= cookie.size(); ++n)
    {
        sumL = 0;
        for (int l = n; l <= cookie.size(); ++l)
        {
            sumL += cookie[l - 1];
            totalSum[n][l] = sumL;
        }
    }

    for (int m = 1; m <= cookie.size(); ++m)
    {
        for (int l = l; l <= m; ++l)
        {
            if (totalSum[l][m] == 0 || totalSum[l][m] > totalSum[l][cookie.size()] / 2)
            {
                break;
            }
            for (int r = m + 1; r <= cookie.size(); ++r)
            {
                if ((totalSum[m + 1][r] == 0) || totalSum[l][m] < totalSum[m + 1][r])
                {
                    break;
                }
                if (totalSum[l][m] == totalSum[m + 1][r])
                {
                    answer = max(answer, totalSum[l][m]);
                }
            }
        }
    }

    return answer;
}

int main()
{
    solution({ 1,1,2,3 });
}