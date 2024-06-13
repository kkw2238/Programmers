/*
    https://programmers.co.kr/learn/courses/30/lessons/12902
*/

#include <vector>

using namespace std;

const unsigned int MOD = 1000000007;

int solution(int n) {
    vector<long long> remember3Count(n / 2 + 2, 0);
    vector<long long> remember1Count(n / 2 + 2, 0);

    remember3Count[1] = remember1Count[2] = 1;

    for (int i = 2; i <= (n / 2); ++i)
    {
        remember3Count[i] = (remember3Count[i - 1] * 4 - remember3Count[i - 2]) % MOD;
        if (i > 2)
        {
            remember1Count[i] = (remember1Count[i - 1] * 4 - remember1Count[i - 2]) % MOD;
        }
    }

    int result = (remember3Count[n / 2] * 3 - remember1Count[n / 2]) % MOD;

    if (result < 0)
    {
        result += MOD;
    }

    return result;
}
