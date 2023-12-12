/*
    https://school.programmers.co.kr/learn/courses/15008/lessons/121683?language=cpp
*/

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

string solution(string input_string) {
    string answer = "";
    set<char> outsideChar;
    map<char, int> arriveCount; 
    char lastestInputString = ' ';

    for (char c : input_string)
    {
        if (lastestInputString != c)
        {
            if (arriveCount[c] > 0)
            {
                outsideChar.insert(c);
            }

            lastestInputString = c;
            ++arriveCount[c];
        }
        else
        {
            ++arriveCount[c];
        }
    }
    
    for (char c : outsideChar)
    {
        answer += c;
    }

    return answer;
}