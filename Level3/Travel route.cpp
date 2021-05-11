/*
    https://programmers.co.kr/learn/courses/30/lessons/43164
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int START = 0;
const int DEST = 1;

vector<string> answer;

void Find_Route(map<string, vector<string>> distributedTickets, vector<string> route, string nowPos, string beforePos)
{
    if (beforePos != "") 
    {
        route.push_back(beforePos);
    }

    if (distributedTickets[beforePos].empty())
    {
        distributedTickets.erase(beforePos);
    }

    if (distributedTickets.empty())
    {
        route.push_back(nowPos);
        answer = route;
        return;
    }

    vector<string> memorizeTickets = distributedTickets[nowPos];
    for (int i = 0; i < memorizeTickets.size(); ++i)
    {
        distributedTickets[nowPos].erase(distributedTickets[nowPos].begin() + i);

        Find_Route(distributedTickets, route, memorizeTickets[i], nowPos);

        distributedTickets[nowPos] = memorizeTickets;
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    map<string, vector<string>> distributedTickets;

    sort(tickets.begin(), tickets.end(), [](const vector<string>& a, const vector<string>& b) { 
        return a[DEST] > b[DEST];
    });

    for (const vector<string>& ticket : tickets)
    {
        distributedTickets[ticket[START]].push_back(ticket[DEST]);
    }

    string nowPos = "ICN";
    Find_Route(distributedTickets, answer, nowPos, "");
  
    return answer;
}

int main()
{
    vector<vector<string>> tickets{ {"ICN", "SFO"},{ "ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO" } };

    solution(tickets);
}

/*
* 현문제
*   
    1. tickets[i][1] 순으로 정렬
        => 최종 결과는 사전순으로 정렬되어 있어야함 -> 미리 정렬 후 DFS하는건? 
        => DFS => 
*/