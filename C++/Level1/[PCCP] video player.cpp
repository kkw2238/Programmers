/*
* https://school.programmers.co.kr/learn/courses/30/lessons/340213?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

const int convertTimeToMinute(const string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(4));
}

string padding(string str, int length) {
    if (str.length() < length) {
        str = string(str.length() - length, '0') + str;
    }

    return str;
}

const string convertMinuteToTime(const int t) {
    string h = padding(to_string(t / 60), 2);
    string m = padding(to_string(t % 60), 2);

    return to_string(t / 60) + ":" + to_string(t % 60);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int nowPos = convertTimeToMinute(pos);
    int opStart = convertTimeToMinute(op_start);
    int opEnd = convertTimeToMinute(op_end);
    int videoLen = convertTimeToMinute(video_len);

    if (nowPos >= opStart && nowPos <= opEnd) {
        nowPos = opEnd;
    }

    for (string& command : commands) {
        if (command[0] == 'p') {
            nowPos = max(0, nowPos - 10);
        }
        else {
            nowPos = min(videoLen, nowPos + 10);
        }

        if (nowPos >= opStart && nowPos <= opEnd) {
            nowPos = opEnd;
        }
    }

    return convertMinuteToTime(nowPos);
}