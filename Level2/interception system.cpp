/*
	https://school.programmers.co.kr/learn/courses/30/lessons/181188
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
        });

    int l = targets[0][0], r = targets[0][1];
    for (int i = 1; i < targets.size(); ++i)
    {
        if (targets[i][0] > r)
        {
            l = targets[i][0];
            r = targets[i][1];
            ++answer;
        }
        else
        {
            l = max(l, targets[i][0]);
            r = min(r, targets[i][1]);
        }
    }

    return answer;
}