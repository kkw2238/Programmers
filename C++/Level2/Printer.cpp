/*
	https://programmers.co.kr/learn/courses/30/lessons/42587
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int nowPos = location;

    queue<int, deque<int>> printFile(deque<int>(priorities.begin(), priorities.end()));
    priority_queue<int, vector<int>, greater<int>> priority(priorities.begin(), priorities.end());
    
    while (!printFile.empty())
    {
        int front = printFile.front();
        printFile.pop();

        if (front < priority.top())
        {
            printFile.emplace(front);
        }
        else
        {
            priority.pop();
            ++answer;

            if (nowPos == 0)
            {
                break;
            }
        }

        --nowPos;
        if (nowPos < 0)
        {
            nowPos = printFile.size() - 1;
        }
    }

    return answer;
}


// 예전 코드
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <functional>
//using namespace std;
//
//int solution(vector<int> priorities, int location) {
//	int answer = 0;
//	vector<int> prioritySize(priorities);
//	sort(prioritySize.begin(), prioritySize.end(), greater<int>());
//
//	while (location >= 0) {
//		int frontPriorty = priorities.front();
//
//		auto iter = find(priorities.begin(), priorities.end(), prioritySize.front());
//
//		if (iter != priorities.end()) {
//			vector<int> smallerPriorty(priorities.begin(), iter);
//			priorities.erase(priorities.begin(), iter);
//			priorities.insert(priorities.end(), smallerPriorty.begin(), smallerPriorty.end());
//
//			location = (location + static_cast<int>(priorities.size() - smallerPriorty.size())) % static_cast<int>(priorities.size());
//		}
//
//		priorities.erase(priorities.begin());
//		prioritySize.erase(prioritySize.begin());
//
//		++answer; --location;
//	}
//
//	return answer;
//}