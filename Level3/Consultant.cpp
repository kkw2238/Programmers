/*
	https://school.programmers.co.kr/learn/courses/30/lessons/214288
*/

#include <vector>
#include <queue>

using namespace std;

struct consultant {
    consultant() = default;
    consultant(int a, int b)
    {
        begTime = a;
        time = b;
        endTime = begTime + time;
    }
    int begTime;
    int endTime;
    int time;

    const bool operator<(const consultant& other) const
    {
        return endTime > other.endTime;
    }
};

int getWaitTime(int consultantCount, vector<consultant>& student)
{
    int waitTime = 0;
    priority_queue<consultant> consultants;

    for (int i = 0; i < consultantCount; ++i)
    {
        if (i < student.size()) 
        {
            consultants.push(consultant(student[i].begTime, student[i].time));
        }
        else
        {
            consultants.push(consultant());
        }
    }

    for (int i = consultantCount; i < student.size(); ++i)
    {
        consultant c = consultants.top();
        consultants.pop();

        if (c.endTime > student[i].begTime)
        {
            waitTime += c.endTime - student[i].begTime;
        }

        consultants.push(consultant(c.endTime, student[i].time));
    }

    return waitTime;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    vector<vector<consultant>> students(k + 1);
    vector<int> consultantCount(k + 1, 1);
    vector<vector<int>> durationTime(k + 2, vector<int>(n + 1, -1));

    n -= k;

    for (vector<int>& req : reqs)
    {
        students[req[2]].emplace_back(req[0], req[1]);
    }

    for (int i = 1; i <= k; ++i)
    {
        int result = getWaitTime(consultantCount[i], students[i]);
        durationTime[i][1] = result;
    }

    while (--n >= 0)
    {
        int memWaitTime = 0;
        int requireType = 0;

        for (int i = 1; i <= k; ++i)
        {
            if (durationTime[i][consultantCount[i] + 1] == -1)
            {
                durationTime[i][consultantCount[i] + 1] = getWaitTime(consultantCount[i] + 1, students[i]);
            }

            int reduceTime = durationTime[i][consultantCount[i]] - durationTime[i][consultantCount[i] + 1];
            if (memWaitTime < reduceTime)
            {
                memWaitTime = reduceTime;
                requireType = i;
            }
        }

        ++consultantCount[requireType];
    }

    for (int i = 1; i <= k; ++i)
    {
        answer += durationTime[i][consultantCount[i]];
    }

    return answer;
}

int main()
{
    solution(5, 5, { { 10, 60, 1},{15, 100, 3},{20, 30, 1},{30, 50, 3},{50, 40, 1},{60, 30, 2},{65, 30, 1},{70, 100, 2} });
}