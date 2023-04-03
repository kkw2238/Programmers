/*
	https://school.programmers.co.kr/learn/courses/30/lessons/176963
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> nameYearning;

    for (int i = 0; i < name.size(); ++i)
    {
        nameYearning[name[i]] = yearning[i];
    }

    for (const vector<string>& p : photo)
    {
        int score = 0;
        for (const string& person : p)
        {
            score += nameYearning[person];
        }
        answer.push_back(score);
    }

    return answer;
}