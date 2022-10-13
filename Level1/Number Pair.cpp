/*
    https://school.programmers.co.kr/learn/courses/30/lessons/131128?language=cpp
*/
#include <string>
#include <algorithm>

using namespace std;

string getResult(string& answer)
{
    if(answer.empty())
    {
        return "-1";
    }
    if (answer[0] == '0')
    {
        return "0";
    }
    return answer;
}

string solution(string X, string Y) {
    string answer = "";
    
    sort(X.begin(), X.end(), greater());
    sort(Y.begin(), Y.end(), greater());
   
    int yIndex = 0;
    for (int i = 0; i < X.length();)
    {
        if (X[i] == Y[yIndex])
        {
            answer += X[i++];
            ++yIndex;
        }
        else if (X[i] > Y[yIndex])
        {
            ++i;
        }
        else
        {
            ++yIndex;
        }

        if (yIndex >= Y.length() || i >= X.length())
        {
            return getResult(answer);
        }
    }

    return getResult(answer);
}