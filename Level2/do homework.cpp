/*
	https://school.programmers.co.kr/learn/courses/30/lessons/176962?language=cpp
*/

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

enum {INDEX, START_TIME, NEED_TIME};

int convertedTimetoMinute(const string& hhmm)
{
    return stoi(hhmm.substr(0, 2)) * 60 + stoi(hhmm.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<vector<int>> homework;

    sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b) {
        return convertedTimetoMinute(a[START_TIME]) > convertedTimetoMinute(b[START_TIME]);
    });

    int nowTime = convertedTimetoMinute(plans[0][START_TIME]);
    
    for (int i = 0; i < plans.size(); ++i)
    {
        int elapsedTime = convertedTimetoMinute(plans[i][START_TIME]) - nowTime;
        nowTime = convertedTimetoMinute(plans[i][START_TIME]);
        int timeOff = 0;
        while (homework.size() > 0 && elapsedTime > 0)
        {
            vector<int> lastestHomework = homework.top();
            homework.pop();
            timeOff = min(elapsedTime, lastestHomework[NEED_TIME]);

            lastestHomework[NEED_TIME] -= timeOff;
            elapsedTime -= timeOff;

            if (lastestHomework[NEED_TIME] > 0)
            {
                homework.push(lastestHomework);
            }
            else
            {
                answer.push_back(plans[lastestHomework[INDEX]][INDEX]);
            }
        }

        homework.push({ i, convertedTimetoMinute(plans[i][START_TIME]), stoi(plans[i][NEED_TIME]) });
    }

    while (!homework.empty())
    {
        vector<int> lastestHomework = homework.top();
        answer.push_back(plans[lastestHomework[INDEX]][INDEX]);

        homework.pop();
    }

    return answer;
}

int main()
{
    solution({{"aaa", "12:00", "20"}, {"bbb", "12:10", "30"}, {"ccc", "12:40", "10"}} );
}