/*
	https://school.programmers.co.kr/learn/courses/30/lessons/133499
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    map<char, string> kindOfBabbling{ {'a', "aya"}, {'y',"ye"}, {'w', "woo"}, {'m', "ma"} };

    for (string& bab : babbling)
    {
        string lastestBabbling = "";

        int index = 0;
        while (index < bab.length())
        {
            string matchString = kindOfBabbling[bab[index]];

            if (matchString.empty() || bab.substr(index, matchString.length()) != matchString || matchString == lastestBabbling)
            {
                lastestBabbling = "";
                break;
            }

            if (matchString != lastestBabbling)
            {
                lastestBabbling = matchString;
                index += matchString.length();
            }
        }

        answer += (index == bab.length());
    }

    return answer;
}