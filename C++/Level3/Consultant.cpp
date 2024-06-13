/*
	https://school.programmers.co.kr/learn/courses/30/lessons/214288
*/

//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct consultant {
//    consultant() = default;
//    consultant(int a, int b)
//    {
//        begTime = a;
//        time = b;
//        endTime = begTime + time;
//    }
//    int begTime;
//    int endTime;
//    int time;
//
//    const bool operator<(const consultant& other) const
//    {
//        return begTime > other.begTime;
//    }
//};
//
//int getWaitTime(int consultantCount, vector<consultant>& student)
//{
//    int waitTime = 0;
//    priority_queue<consultant> consultants;
//
//    for (int i = 0; i < consultantCount; ++i)
//    {
//        if (i < student.size()) 
//        {
//            consultants.push(consultant(student[i].begTime, student[i].time));
//        }
//        else
//        {
//            consultants.push(consultant());
//        }
//    }
//
//    for (int i = consultantCount; i < student.size(); ++i)
//    {
//        consultant c = consultants.top();
//        consultants.pop();
//
//        if (c.endTime > student[i].begTime)
//        {
//            waitTime += c.endTime - student[i].begTime;
//        }
//
//        consultants.push(consultant(c.endTime, student[i].time));
//    }
//
//    return waitTime;
//}
//
//int solution(int k, int n, vector<vector<int>> reqs) {
//    int answer = 0;
//    vector<vector<consultant>> students(k + 1);
//    vector<int> consultantCount(k + 1, 1);
//    vector<vector<int>> durationTime(k + 2, vector<int>(n + 1, -1));
//
//    n -= k;
//
//    for (vector<int>& req : reqs)
//    {
//        students[req[2]].emplace_back(req[0], req[1]);
//    }
//
//    for (int i = 1; i <= k; ++i)
//    {
//        int result = getWaitTime(consultantCount[i], students[i]);
//        durationTime[i][1] = result;
//    }
//
//    while (--n >= 0)
//    {
//        int memWaitTime = 0;
//        int requireType = 0;
//
//        for (int i = 1; i <= k; ++i)
//        {
//            if (durationTime[i][consultantCount[i] + 1] == -1)
//            {
//                durationTime[i][consultantCount[i] + 1] = getWaitTime(consultantCount[i] + 1, students[i]);
//            }
//
//            int reduceTime = durationTime[i][consultantCount[i]] - durationTime[i][consultantCount[i] + 1];
//            if (memWaitTime < reduceTime)
//            {
//                memWaitTime = reduceTime;
//                requireType = i;
//            }
//        }
//
//        ++consultantCount[requireType];
//    }
//
//    for (int i = 1; i <= k; ++i)
//    {
//        answer += durationTime[i][consultantCount[i]];
//    }
//
//    return answer;
//}

#include <string>
#include <vector>
#include <queue>

using namespace std;

int waitTime(int consultantCount, vector<vector<int>>& students)
{
    int waitTime = 0;
    priority_queue<int, vector<int>, greater<int>> consultants;

    for (int i = 0; i < consultantCount; ++i)
    {
        consultants.push(0);
    }

    for (vector<int>& student : students)
    {
        int nowTime = consultants.top();
        consultants.pop();

        waitTime += max(0, nowTime - student[0]);
        consultants.push(max(nowTime, student[0]) + student[1]);
    }

    return waitTime;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;

    vector<int> consultantCount(k + 1, 1);
    vector<vector<vector<int>>> students(k + 1, vector<vector<int>>());
    vector<vector<int>> memConsultantTime(k + 1, vector<int>(n + 2, -1));

    n -= k;

    for (vector<int>& req : reqs)
    {
        students[req[2]].push_back({ req[0], req[1] });
    }

    for (int i = 1; i <= k; ++i)
    {
        memConsultantTime[i][1] = waitTime(1, students[i]);
    }

    while (n-- > 0)
    {
        int memDiffTime = 0;
        int memIndex = 0;

        for (int i = 1; i <= k; ++i)
        {
            int conCount = consultantCount[i];
            
            if (memConsultantTime[i][conCount + 1] == -1)
            {
                memConsultantTime[i][conCount + 1] = waitTime(conCount + 1, students[i]);
            }

            int diff = memConsultantTime[i][conCount] - memConsultantTime[i][conCount + 1];
            
            if (diff > memDiffTime)
            {
                memDiffTime = diff;
                memIndex = i;
            }
        }

        ++consultantCount[memIndex];
    }

    for (int i = 1; i <= k; ++i)
    {
        answer += memConsultantTime[i][consultantCount[i]];
    }

    return answer;
}