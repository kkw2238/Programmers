#include <string>
#include <vector>
#include <queue>

const int START = 0;
const int TIME = 1;

struct Job
{
    int originStart;
    int start;
    int time;

    bool operator<(const Job& other) const
    {
        if (start == other.start)
        {
            return time > other.time;
        }
        return start > other.start;
    }
};

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int elapsedTime = 0;

    priority_queue<Job> controller;
    for (vector<int>& job : jobs)
    {
        controller.push({ job[START], job[START], job[TIME] });
    }
    
    while (!controller.empty())
    {
        Job nowJob = controller.top();
        controller.pop();

        if (nowJob.start > elapsedTime)
        {
            elapsedTime = nowJob.start;
        }
        else if (nowJob.start < elapsedTime)
        {
            controller.push({ nowJob.originStart, elapsedTime, nowJob.time });
            continue;
        }

        answer += (elapsedTime + nowJob.time) - nowJob.originStart;
        elapsedTime += nowJob.time;
    }

    return answer / jobs.size();
}


#include <iostream>
int main()
{
    vector<vector<int>> jobs { { 0, 3 },{ 1, 9 },{ 2, 6 } };

    cout << solution(jobs);
}