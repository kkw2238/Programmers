/*
    https://school.programmers.co.kr/learn/courses/30/lessons/150368
*/

#include <string>
#include <vector>

using namespace std;

int DISCOUNTS[4] = { 40, 30, 20, 10 };

vector<int> bill(const vector<int>& user, const vector<int>& emoticons, const vector<int>& discounts)
{
    int pay = 0;

    for (int i = 0; i < emoticons.size(); ++i)
    {
        if (discounts[i] >= user[0])
        {
            pay += emoticons[i] * discounts[i] / 100;
        }

        if (pay > user[1])
        {
            return { 1, 0 };
        }
    }

    return { 0, pay };
}

vector<int> dfs(const vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discounts, int index)
{
    vector<int> result(2, 0);
    if (index == emoticons.size())
    {
        for (const vector<int>& user : users)
        {
            vector<int> buyBill = bill(user, emoticons, discounts);
            result[0] += buyBill[0];
            result[1] += buyBill[1];
        }

        return result;
    }

    for (int i = 0; i < 4; ++i)
    {
        discounts[index] = DISCOUNTS[i];
        
        vector<int> rootResult = dfs(users, emoticons, discounts, index + 1);

        if (rootResult[0] == result[0] && rootResult[1] > result[1])
        {
            result = rootResult;
        }
        else if (rootResult[0] > result[0])
        {
            result = rootResult;
        }
    }

    return result;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> discounts = vector<int>(emoticons.size(), 0);

    return dfs(users, emoticons, discounts, 0);
}

int main()
{
    solution({{40, 10000},{25, 10000}},{7000, 9000 });
}