/*
	https://school.programmers.co.kr/learn/courses/30/lessons/131704
*/

#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    stack<int> dbox2;

    for (int i = 1; i <= order.size(); ++i)
    {
        dbox2.push(i);

        while (dbox2.top() != order[answer])
        {
            dbox2.pop();
            ++answer;
        }
    }

    return answer;
}