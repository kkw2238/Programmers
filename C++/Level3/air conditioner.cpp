/*
	https://school.programmers.co.kr/learn/courses/30/lessons/214289?language=cpp
*/

#include <vector>
#include <queue>

using namespace std;

struct node {
    int time, temp, eUsage;
};

int memEUsage[1001][53];
bool footStamp[1001][53];

bool isAblePush(int nextTime, int nextTemp, int nexteUsage)
{
    memEUsage[nextTime][nextTemp + 11] = min(memEUsage[nextTime][nextTemp + 11], nexteUsage);

    return !footStamp[nextTime][nextTemp + 11];
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 1000000;
    
    queue<node> qn;

    int minTemp = min(t1, t2);
    int maxTemp = max(t1, t2);

    qn.push({ 0, temperature , 0 });

    for (int i = 0; i <= 52; ++i)
    {
        for (int j = 0; j <= 1000; ++j)
        {
            memEUsage[j][i] = 1000000;
        }
    }

    memEUsage[0][temperature + 11] = 0;

    while (!qn.empty())
    {
        node n = qn.front();
        qn.pop();

        n.eUsage = memEUsage[n.time][n.temp + 11];

        if (n.time == onboard.size())
        {
            answer = min(n.eUsage, answer);
            continue;
        }
        else if (onboard[n.time] == 1 && (n.temp < t1 || n.temp > t2))
        {
            continue;
        }
        else if (n.temp < -10 || n.temp > 40)
        {
            continue;
        }

        if (isAblePush(n.time + 1, n.temp - 1, n.eUsage + a))
        {
            footStamp[n.time + 1][n.temp + 10] = true;
            qn.push({ n.time + 1, n.temp - 1, n.eUsage + a });
        }
        if (n.temp <= t2 && n.temp >= t1 && isAblePush(n.time + 1, n.temp, n.eUsage + b))
        {
            footStamp[n.time + 1][n.temp + 11] = true;
            qn.push({ n.time + 1, n.temp, n.eUsage + b });
        }
        if (isAblePush(n.time + 1, n.temp + 1, n.eUsage + a))
        {
            footStamp[n.time + 1][n.temp + 12] = true;
            qn.push({ n.time + 1, n.temp + 1, n.eUsage + a });
        }

        int addTemp = n.temp > temperature ? -1 : 1;
        addTemp = n.temp == temperature ? 0 : addTemp;
        if (isAblePush(n.time + 1, n.temp + addTemp, n.eUsage))
        {
            footStamp[n.time + 1][n.temp + addTemp + 11] = true;
            qn.push({ n.time + 1, n.temp + addTemp, n.eUsage });
        }
    }

    return answer;
}