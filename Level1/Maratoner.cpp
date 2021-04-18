#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int maratonerParticiant = 0;
    int maratonerCompletion = 0;
    map<string, int> maratoners;

    --maratoners[participant[participant.size() - 1]];
    for (int i = 0; i < completion.size(); ++i)
    {
        if (maratonerParticiant = --maratoners[participant[i]]; maratonerParticiant == 0)
        {
            maratoners.erase(participant[i]);
        }
        if (maratonerCompletion = ++maratoners[completion[i]]; maratonerCompletion == 0)
        {
            maratoners.erase(completion[i]);
        }
    }

    return (*maratoners.begin()).first;
}

#include <iostream>

int main()
{
    vector<string> participant = { "leo", "kiki", "eden" };
    vector<string> completion = { "kiki", "eden" };
    
    cout << solution(participant, completion);

    return 0;
}