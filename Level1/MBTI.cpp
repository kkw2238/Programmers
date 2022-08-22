/*
    https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=cpp
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    const vector<string> TYPES = { "RT", "CF", "JM", "AN" };
    map<char, int> scoreOfCharacter;

    for (int i = 0; i < survey.size(); ++i)
    {
        int score = choices[i] - 4;

        if (score < 0)
        {
            scoreOfCharacter[survey[i][0]] -= score;
        }
        else
        {
            scoreOfCharacter[survey[i][1]] += score;
        }
    }

    for (const string type : TYPES)
    {
        if (scoreOfCharacter[type[1]] > scoreOfCharacter[type[0]])
        {
            answer += type[1];
        }
        else
        {
            answer += type[0];
        }
    }

    return answer;
}