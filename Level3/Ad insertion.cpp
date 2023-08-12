/*
	https://school.programmers.co.kr/learn/courses/30/lessons/72414
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int convertTime(string& log)
{
    int hour = stoi(log.substr(0, 2));
    int minute = stoi(log.substr(3, 2));
    int seconds = stoi(log.substr(6, 2));

    return hour * 3600 + minute * 60 + seconds;
}

string addZero(string str)
{
    str = "0" + str;
    return str.substr(str.length() - 2);
}

string reverseTime(int log)
{
    string hour = to_string(log / 3600);
    log = log % 3600;

    string minute = to_string(log / 60);
    string second = to_string(log % 60);

    return addZero(hour) + ":" + addZero(minute) + ":" + addZero(second);
}

vector<int> unpackLogs(string& log)
{
    vector<int> unpacked; 
    vector<string> distributeLog;

    distributeLog.push_back(log.substr(0, 8));
    distributeLog.push_back(log.substr(9));

    for (int i = 0; i < 2; ++i)
    {
        unpacked.push_back(convertTime(distributeLog[i]));
    }
    
    return unpacked;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<int> beginTime, endTime;

    int pt = convertTime(play_time);
    int at = convertTime(adv_time);
    
    for (string& log : logs)
    {
        vector<int> unpacked = unpackLogs(log);

        beginTime.push_back(unpacked[0]);
        endTime.push_back(unpacked[1]);
    }

    sort(beginTime.begin(), beginTime.end());
    sort(endTime.begin(), endTime.end());

    map<int, int> timeCount;
    timeCount[0] = 0;
    timeCount[pt - at] = 0;
    int bti = 0, eti = 0;
    int nowTime = beginTime[0], count = 0;
    while (bti < logs.size())
    {
        if (beginTime[bti] < endTime[eti])
        {
            timeCount[beginTime[bti++]] = ++count;
        }
        else if (beginTime[bti] > endTime[eti])
        {
            timeCount[endTime[eti++]] = --count;
        }
        else
        {
            ++eti;
            ++bti;
        }
    }

    for (int i = eti; i < logs.size(); ++i)
    {
        timeCount[endTime[i]] = --count;
    }

    beginTime.push_back(0);
    beginTime.push_back(pt - at);

    sort(beginTime.begin(), beginTime.end());

    int memCount = 0, memAnswer = 0;
    for (int i = 0; i < beginTime.size(); ++i)
    {
        int eTime = beginTime[i] + at;
        int memTime = beginTime[i];
        int count = 0;
        auto iter = timeCount.find(beginTime[i]);
        for (; iter != timeCount.end(); ++iter)
        {
            int elapsedTime = min(iter->first, eTime) - memTime;
            count += timeCount[memTime] * elapsedTime;
            memTime = iter->first;

            if (iter->first > eTime)
            {
                break;
            }
        }

        if (count > memCount)
        {
            memAnswer = beginTime[i];
            memCount = count;
        }
    }
    answer = reverseTime(memAnswer);

    return reverseTime(memAnswer);
}

int main()
{
    solution("99:59:59", "25:00:00", { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" });
}