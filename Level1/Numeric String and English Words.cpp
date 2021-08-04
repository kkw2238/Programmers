/*
    https://programmers.co.kr/learn/courses/30/lessons/81301?language=cpp
*/
#include <string>
#include <vector>

using namespace std;

const vector<pair<string, string>> TRANSLATE = {
    {"zero" ,"0"},
    {"one"  ,"1"},
    {"two"  ,"2"},
    {"three","3"},
    {"four" ,"4"},
    {"five" ,"5"},
    {"six"  ,"6"},
    {"seven","7"},
    {"eight","8"},
    {"nine" ,"9"}
};

int solution(string s) {

    for (const pair<string, string>& translate : TRANSLATE)
    {
        const size_t leng = translate.first.length();
        size_t pos = s.find(translate.first);

        while (pos != string::npos)
        {
            s.replace(pos, leng, translate.second);
            pos = s.find(translate.first);
        }
    }
    
    return stoi(s);
}