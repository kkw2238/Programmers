/*
    https://school.programmers.co.kr/learn/courses/30/lessons/258705?language=cpp
*/

#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;

    vector<int> sum(200002, 0);
    vector<int> cal(30);

    int nowTopIndex = tops[0] > 0 ? 1 : 0;
    sum[1] = 1;
    sum[2] = tops[0] > 0 ? 3 : 2;

    for (int index = 3; index <= n * 2 + 1; ++index)
    {
        sum[index] = sum[index - 1] + sum[index - 2];
        if (index % 2 == 0)
        {
            if (tops[nowTopIndex] > 0)
            {
                sum[index] = sum[index] + sum[index - 1];
            }
            ++nowTopIndex;
        }
    }

    return sum[n * 2 + 1];
}
