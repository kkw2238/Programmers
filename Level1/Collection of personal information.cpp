/*
	https://school.programmers.co.kr/learn/courses/30/lessons/150370?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

const int DAY_OF_MONTH = 28;
const int DAY_OF_YEAR = DAY_OF_MONTH * 12;

const int parseTotalDay(const string& s)
{
    int year = stoi(s.substr(0, 4)) - 2000;
    int month = stoi(s.substr(5, 2)) - 1;
    int day = stoi(s.substr(8, 2));

    return DAY_OF_YEAR * year + DAY_OF_MONTH * month + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> convertedTermToDay('Z' - 'A' + 1, 0);

    int totalDayofToday = parseTotalDay(today);

    for (const string& term : terms)
    {
        convertedTermToDay[term[0] - 'A'] = stoi(term.substr(2)) * DAY_OF_MONTH;
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        int totalDayofPrivacy = parseTotalDay(privacies[i].substr(0, 10));
        totalDayofPrivacy += convertedTermToDay[privacies[i][11] - 'A'];

        if (totalDayofPrivacy <= totalDayofToday)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}