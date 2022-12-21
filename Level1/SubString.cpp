/*
    https://school.programmers.co.kr/learn/courses/30/lessons/140108
*/

#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    int xCount = 0;
    char x = ' ';

    for (int i = 0; i < s.length(); ++i)
    {
        if (x == ' ')
        {
            x = s[i];
            ++answer;
        }

        if (x == s[i])
        {
            ++xCount;
        }
        else
        {
            --xCount;
            if (xCount == 0)
            {
                x = ' ';
            }
        }
    }

    return answer;
}