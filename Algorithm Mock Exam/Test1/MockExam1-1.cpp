#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    int xIndex = 0;
    int yIndex = 0;

    sort(X.begin(), X.end(), less());
    sort(Y.begin(), Y.end(), less());

    while ((xIndex < X.length()) && (yIndex < Y.length()))
    {
        if (X[xIndex] == Y[yIndex])
        {
            answer += X[xIndex];
            ++xIndex;
            ++yIndex;
        }
        else if (X[xIndex] > Y[yIndex])
        {
            ++xIndex;
        }
        else if (X[xIndex] < Y[yIndex])
        {
            ++yIndex;
        }
    }

    if (answer.empty())
    {
        return "-1";
    }
    else if (answer[0] == answer.back() && answer.back() == '0')
    {
        return "0";
    }
 
    return answer;
}