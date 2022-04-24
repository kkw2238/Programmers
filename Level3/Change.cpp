/*
	https://programmers.co.kr/learn/courses/30/lessons/12907
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> combinationCountAtMoney(n + 1);
    sort(money.begin(), money.end());

    for (int m = money[0]; m <= n; ++m)
    {
        if (m % money[0] == 0)
        {
            ++combinationCountAtMoney[m];
        }
    }

    for (int i = 1; i < money.size(); ++i)
    {
        for (int m = money[i]; m <= n; ++m)
        {
            if (m - money[i] < 0)
            {
                break;
            }

            if (money[i] == m)
            {
                ++combinationCountAtMoney[m];
            }
            else if(combinationCountAtMoney[m - money[i]] > 0)
            {
                combinationCountAtMoney[m] += combinationCountAtMoney[m - money[i]];
            }
        }
    }

    return combinationCountAtMoney[n];
}

/*
    1 = 1
    2 = 1 + 1 / 2
    3 = 1 + 1 + 1 / 1 + 2
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