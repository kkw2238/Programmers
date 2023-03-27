#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int card1Index = 0, card2Index = 0;

    for (string& g : goal)
    {
        if (g == cards1[card1Index]) 
        {
            ++card1Index;
        }
        else if (g == cards2[card2Index]) 
        {
            ++card2Index;
        }
        else
        {
            return "No";
        }
    }

    return "Yes";
}