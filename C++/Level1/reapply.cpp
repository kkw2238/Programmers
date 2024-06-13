/*
	https://school.programmers.co.kr/learn/courses/30/lessons/161989
*/

#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int remanet = m - 1;

    for (int i = 1; i < section.size(); ++i)
    {
        int offset = (section[i] + 1) - section[i - 1];
        if ((remanet - offset) < 0)
        {
            ++answer;
            remanet = m - 1;
        }
        else
        {
            remanet -= offset;
        }
    }

    return answer;
}

int main()
{
    solution(8, 4, { 2,4,6 });
}