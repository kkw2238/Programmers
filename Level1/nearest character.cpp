/*
	https://school.programmers.co.kr/learn/courses/30/lessons/142086
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> indices(26, -1);

    for (int i = 0; i < s.length(); ++i)
    {
        int charIndex = s[i] - 'a';

        if (indices[charIndex] == -1)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - indices[charIndex]);
        }

        indices[charIndex] = i;
    }

    return answer;
}