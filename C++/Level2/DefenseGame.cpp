/*
    https://school.programmers.co.kr/learn/courses/30/lessons/142085?language=cpp
*/

#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    if (k >= enemy.size())
    {
        return enemy.size();
    }

    priority_queue<int> memData;

    for (int i = 0; i < enemy.size(); ++i)
    {
        n -= enemy[i];

        memData.push(enemy[i]);

        if (n < 0 && k > 0)
        {
            n += memData.top();
            memData.pop();
            --k;
        }
        else if (n < 0 && k == 0)
        {
            return i;
        }
    }
    
    return enemy.size();
}