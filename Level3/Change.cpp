/*
	https://programmers.co.kr/learn/courses/30/lessons/12907
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int DENOMINATOR = 1000000007;

#include <iostream>

int solution(int n, vector<int> money) {
    vector<int> combinationCountAtMoney(n + 1);
    sort(money.begin(), money.end());

    for (int i : money)
    {
        combinationCountAtMoney[i] = 1;
    }

    for (int m = money[0]; m <= n; ++m)
    {
        int memCombination = 0;
        for (int i = 0; i < money.size(); ++i)
        {
            if (m - money[i] < 0 || m == money[i])
            {
                continue;
            }

            memCombination += combinationCountAtMoney[m - money[i]];
        }

        combinationCountAtMoney[m] += memCombination;
    }

    return combinationCountAtMoney[n];
}

/*
    1 = 1
    2 = 1 + 1 / 2
    3 = 1 + 1 + 1 / 1 + 2 / 2 + 1
    4 = 1 + 1 + 1 / 1 + 1 + 2 / 2 + 2 / 
    5 = 1 + 1 + 1 + 1 + 1 / 1 + 1 + 1 + 2 / 1 + 2 + 1/ 2 + 1 + 1 / 2 + 2 + 1 / 2 + 1 + 2 / 1 + 2 + 2 / 5

*/

int main()
{
    solution(5, {1, 2, 5});

    // i == 0
    //  1 + 1 + 1 + 1 + 1
    //  5

    // i == 1
    // 1 + 1 + 1 + 2
    // 1 + 2 + 2

    // i == 2
    // 0

    // 1 1 1 1 / 1 1 2 / 2 2 
}

/*
 

int Combination(int change, const vector<int>& money, int nowIndex)
{
    if (change == 0)
    {
        return 1;
    }
    else if (nowIndex == money.size())
    {
        return 0;
    }

    const int NOW_MONEY = money[nowIndex];
    int result = 0;

    for (int i = 0; NOW_MONEY * i <= change; ++i)
    {
        int tempChange = change - NOW_MONEY * i;

        result += Combination(tempChange, money, nowIndex + 1) % DENOMINATOR;
    }

    return result;
}

int solution(int n, vector<int> money) {
    vector<int> numberOfCase(money.size() + 1);

    for (int j = 0; j < numberOfCase.size(); ++j)
    {
        if (n % money[j] == 0)
        {
            ++numberOfCase[j];
        }
    }

    for (int i = 0; i < numberOfCase.size(); ++i)
    {
        for (int j = 0; j < numberOfCase.size(); ++j)
        {

        }
    }

    return Combination(n, money, 0);
}

*/