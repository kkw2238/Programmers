/*
	https://programmers.co.kr/learn/courses/30/lessons/84325
*/

#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<string, int> applicantInfo;
    int totalScore = 0;
    
    for (int i = 0; i < languages.size(); ++i)
    {
        applicantInfo[languages[i]] = preference[i];
    }
    
    for (const string& line : table)
    {
        stringstream ss(line);
        string profession, lang;
        int score = 5;
        int myScore = 0;

        ss >> profession;

        for (int i = 0; i < 5; ++i)
        {
            ss >> lang;
            myScore += score * applicantInfo[lang];
            --score;
        }

        if ((myScore > totalScore) || (myScore == totalScore && answer > profession))
        {
            totalScore = myScore;
            answer = profession;
        }
    }

    return answer;
}

int main()
{
    solution({ "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" }, { "PYTHON", "C++", "SQL" }, { 7, 5, 5 });
}