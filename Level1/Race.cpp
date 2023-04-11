/*
	https://school.programmers.co.kr/learn/courses/30/lessons/178871
*/

#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> ranking;
    
    reverse(players.begin(), players.end());
    for (int i = 0; i < players.size(); ++i)
    {
        ranking[players[i]] = i;
    }

    for (const string& calling : callings)
    {
        
        int nowRanking = ranking[calling];
        string beforePlayer = players[nowRanking - 1];

        swap(players[nowRanking], players[nowRanking - 1]);
        --ranking[calling];
        ++ranking[beforePlayer];
    }
    
    return players;
}

int main()
{
    string c(3, 'a');

    c += 'c';
}