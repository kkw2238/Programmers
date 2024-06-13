/*
    https://programmers.co.kr/learn/courses/30/lessons/92334
*/

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, set<string>> reportResult;
    map<string, int> successReport;
    int id_count = id_list.size();

    for (const string& rep : report)
    {
        int voidIndex = rep.find(' ');
        
        string from = rep.substr(0, voidIndex);
        string to = rep.substr(voidIndex + 1);

        reportResult[to].insert(from);
    }

    for (auto result : reportResult)
    {
        if (result.second.size() < k)
        {
            continue;
        }

        for (const string& id : result.second)
        {
            ++successReport[id];
        }
    }

    vector<int> answer(id_count);
    for (int i = 0; i < id_count; ++i)
    {
        answer[i] = successReport[id_list[i]];
    }

    return answer;
}