/*
	https://school.programmers.co.kr/learn/courses/30/lessons/72414
*/

#include <string>
#include <vector>
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

string reverseTime(long long log)
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

    int pt = convertTime(play_time);
    int at = convertTime(adv_time);

    vector<unsigned long long> timeline(pt + 2, 0);

    for (string& log : logs)
    {
        vector<int> unpacked = unpackLogs(log);

        ++timeline[unpacked[0]];
        --timeline[unpacked[1]];
    }

    unsigned long long sumTime = 0, nowWatching = 0, memTime = 0;
    unsigned long long memAnswer = 0;

    for (int i = 0; i <= pt; ++i)
    {
        timeline[i + 1] += timeline[i];

        if (i < at)
        {
            sumTime += timeline[i];
        }
    }

    for (int bti = 0; bti <= pt - at; ++bti)
    {
        if (sumTime > memTime)
        {
            memTime = sumTime;
            memAnswer = bti;
        }

        sumTime += timeline[bti + at];
        sumTime -= timeline[bti];
    }

    return reverseTime(memAnswer);
}

//string solution(string play_time, string adv_time, vector<string> logs) {
//    string answer = "";
//    vector<int> beginTime, endTime;
//
//    int pt = convertTime(play_time);
//    int at = convertTime(adv_time);
//
//    for (string& log : logs)
//    {
//        vector<int> unpacked = unpackLogs(log);
//
//        beginTime.push_back(unpacked[0]);
//        endTime.push_back(unpacked[1]);
//    }
//
//    sort(beginTime.begin(), beginTime.end());
//    sort(endTime.begin(), endTime.end());
//
//    map<int, int> timeCount;
//    timeCount[0] = 0;
//    timeCount[pt - at] = 0;
//    int bti = 0, eti = 0;
//    int count = 0;
//    while (bti < logs.size())
//    {
//        if (beginTime[bti] <= endTime[eti])
//        {
//            timeCount[beginTime[bti++]] = ++count;
//        }
//        else if (beginTime[bti] > endTime[eti])
//        {
//            timeCount[endTime[eti++]] = --count;
//        }
//    }
//
//    for (int i = eti; i < logs.size(); ++i)
//    {
//        timeCount[endTime[i]] = --count;
//    }
//
//    beginTime.push_back(0);
//    beginTime.push_back(pt - at);
//
//    sort(beginTime.begin(), beginTime.end());
//
//    int memCount = 0, memAnswer = 0;
//    for (int i = 0; i < beginTime.size(); ++i)
//    {
//        int eTime = beginTime[i] + at;
//        int memTime = beginTime[i];
//        int count = 0;
//        auto iter = timeCount.find(beginTime[i]);
//
//        if (eTime > pt)
//        {
//            break;
//        }
//
//        for (; iter != timeCount.end(); ++iter)
//        {
//            int elapsedTime = min(iter->first, eTime) - memTime;
//            count += timeCount[memTime] * elapsedTime;
//            memTime = iter->first;
//
//            if (iter->first > eTime)
//            {
//                break;
//            }
//        }
//
//        if (count > memCount)
//        {
//            memAnswer = beginTime[i];
//            memCount = count;
//        }
//    }
//
//    return reverseTime(memAnswer);
//}

#include <iostream>

int main()
{
    for (long long i = 0; i <= 360000; ++i)
    {
        string str = reverseTime(i);
        if (convertTime(str) != i)
        {
            cout << i << " " << str << '\n';
        }

    }
    solution("02:03:55", "00:14:15", { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" });
}