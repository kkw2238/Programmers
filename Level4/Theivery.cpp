/*
    https://programmers.co.kr/learn/courses/30/lessons/42897
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> totalMoney = money;
    vector<int> totalMoneyEnd = money;

    for (int i = money.size() - 1; i >= 0; --i)
    {
        for (int j = 2; j < 4 && i - j >= 0; ++j)
        {
            if (i - j > 0 && totalMoneyEnd[i - j] <= totalMoneyEnd[i] + money[i - j])
            {
                totalMoneyEnd[i - j] = totalMoneyEnd[i] + money[i - j];
            }

            if (i != money.size() - 1 && totalMoney[i - j] <= totalMoney[i] + money[i - j])
            {
                totalMoney[i - j] = totalMoney[i] + money[i - j];
            } 
        }
    }

    return max({ totalMoney[0], totalMoney[1], totalMoney[2], totalMoneyEnd[0], totalMoneyEnd[1], totalMoneyEnd[2] });
}


#include <iostream>
int main()
{
    vector<int> money = { 1,2,3 };
    cout << solution(money);
}