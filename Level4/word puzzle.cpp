/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12983
*/

#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int solution(vector<string> strs, string t)
{
    int maximum = 20001;

    map<char, set<string>> beginString;
    vector<set<int, greater<int>>> patterns(t.size() + 1);
    vector<int> minimum(t.size() + 1, maximum);

    for (string& str : strs)
    {
        beginString[str[0]].insert(str);

        if (t.substr(0, str.length()) == str)
        {
            minimum[str.length()] = 1;
            minimum[0] = 0;
        }
    }

    if (minimum[0] == maximum)
    {
        return -1;
    }

    for (int i = 1; i < t.length(); ++i)
    {
        if (minimum[i] == maximum)
        {
            continue;
        }

        for (const string& s : beginString[t[i]])
        {
            if (t.substr(i, s.length()) == s)
            {
                minimum[i + s.length()] = min(minimum[i] + 1, minimum[i + s.length()]);
            }
        }
    }

    if (minimum[t.length()] == maximum)
    {
        return -1;
    }

    return minimum[t.length()];
}