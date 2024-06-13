/*
    https://school.programmers.co.kr/learn/courses/30/lessons/181186
*/


#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp{ 1, 1, 3, 10 };
    vector<int> offset(3, 0);
    int additional[3] = { 4, 2, 2 };

    for (int i = 4; i <= n; ++i)
    {
        int next = (dp[i - 1] * 1 + dp[i - 2] * 2 + dp[i - 3] * 5) % 1000000007;
        
        for (int j = 0; j < 3; ++j)
        {
            offset[j] += dp[i - 4] * additional[j % 3];
        }

        dp.push_back((next + offset[i % 3]) % 1000000007);
    }

    return dp[n];
}