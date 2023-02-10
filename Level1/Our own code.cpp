/*
    https://school.programmers.co.kr/learn/courses/30/lessons/155652?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    bool skipAble[26] = { false };

    for (char c : skip)
    {
        skipAble[c - 'a'] = true;
    }

    for (char& c : s)
    {
        int count = 1, charIndex = c - 'a';
        for (int i = 1; i <= index;)
        {
            if (!skipAble[(charIndex + count) % 26])
            {
                ++i;
            }

            ++count;
        }

        c = 'a' + (charIndex + count) % 26;
    }

    return s;
}