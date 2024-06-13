/*
    https://school.programmers.co.kr/learn/courses/30/lessons/155651
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int convertHHmmTomm(const string& time)
{
    int hour = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));

    return hour * 60 + minutes;
}

int solution(vector<vector<string>> book_time) {
    vector<vector<int>> book_time_mm;
    vector<int> room;

    for (const vector<string>& time : book_time)
    {
        int startTime = convertHHmmTomm(time[0]);
        int endTime = convertHHmmTomm(time[1]);

        book_time_mm.push_back({ startTime , endTime });
    }

    sort(book_time_mm.begin(), book_time_mm.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    for (int i = 0; i < book_time_mm.size(); ++i)
    {
        bool successfully = false;
        for (int j = 0; j < room.size(); ++j)
        {
            if (room[j] + 10 <= book_time_mm[i][0])
            {
                room[j] = book_time_mm[i][1];
                successfully = true;
            }
        }
        if (!successfully)
        {
            room.push_back(book_time_mm[i][1]);
        }
    }

    return room.size();
}