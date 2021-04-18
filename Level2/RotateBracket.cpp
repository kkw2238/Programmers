#include <string>
#include <vector>
#include <stack>

using namespace std;

int rotateCount = 0;

const bool IsLeftBracket(const char c)
{
    return c == '{' || c == '(' || c == '[';
}

const bool IsCompare(const char left, const char right)
{
    switch (left)
    {
    case '{':
        return right == '}';
    case '(':
        return right == ')';
    case '[':
        return right == ']';
    default:
        return false;
    }
}

bool IsNormallyBracket(const string& s)
{
    stack<char> lastestLeftBracket;

    int left = 0;
    int right = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        int nowIndex = (i + rotateCount) % s.length();
        if (IsLeftBracket(s[nowIndex]))
        {
            ++left;
            lastestLeftBracket.push(s[nowIndex]);
        }
        else 
        {
            ++right;

            char c = lastestLeftBracket.top();
            lastestLeftBracket.pop();
            
            if (!IsCompare(c, s[nowIndex]))
            {
                return false;
            }
        }

        if (right > left)
        {
            return false;
        }
    }

    return true;
}

int solution(string s) {
    if (s.length() % 2 == 1)
    {
        return 0;
    }

    int answer = 0;

    for (; rotateCount < s.length();)
    {
        if (IsNormallyBracket(s))
        {
            rotateCount += 2;
            ++answer;
        }
        else
        {
            ++rotateCount;
        }
    }

    return answer;
}


#include <iostream>

int main()
{
    string s = "[](){}";
    cout << solution(s);
}