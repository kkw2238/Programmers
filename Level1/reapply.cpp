/*
	https://school.programmers.co.kr/learn/courses/30/lessons/161989
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int remanet = m;

    for (int i = 1; i < section.size(); ++i)
    {
        if (remanet - (section[i] - section[i - 1]) <= 0)
        {
            ++answer;
            remanet = m;
        }
    }

    return answer;
}