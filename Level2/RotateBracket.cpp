#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

map<char, char> compareBracket{ pair('(', ')'), pair('{', '}'), pair('[', ']') };

const bool IsLeftBracket(const char c)
{
    return compareBracket.find(c) != compareBracket.end();
}

const bool IsCorrectBracket(string& s, int offset)
{
    stack<char> bracket;
    const int length = s.length();

    for (int i = offset; i < s.length() + offset; ++i)
    {
        char c = s[i % length];

        if (IsLeftBracket(c))
        {
            bracket.push(c);
        }
        else if(!bracket.empty())
        {
            char top = bracket.top();

            if (c != compareBracket[top])
            {
                return false;
            }

            bracket.pop();
        }
        else
        {
            return false;
        }
    }
  
    return bracket.empty();
}

int solution(string s) {

    int answer = 0;
    for (int count = 0; count < s.length(); ++count)
    {
        if (IsCorrectBracket(s, count))
        {
            ++answer;
        }
    }

    return answer;
}

// ���� �ڵ�
//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int rotateCount = 0;
//
//const bool IsLeftBracket(const char c)
//{
//    return c == '{' || c == '(' || c == '[';
//}
//
//const bool IsCompare(const char left, const char right)
//{
//    switch (left)
//    {
//    case '{':
//        return right == '}';
//    case '(':
//        return right == ')';
//    case '[':
//        return right == ']';
//    default:
//        return false;
//    }
//}
//
//bool IsNormallyBracket(const string& s)
//{
//    stack<char> lastestLeftBracket;
//
//    int left = 0;
//    int right = 0;
//
//    for (int i = 0; i < s.length(); ++i)
//    {
//        int nowIndex = (i + rotateCount) % s.length();
//        if (IsLeftBracket(s[nowIndex]))
//        {
//            ++left;
//            lastestLeftBracket.push(s[nowIndex]);
//        }
//        else 
//        {
//            ++right;
//
//            char c = lastestLeftBracket.top();
//            lastestLeftBracket.pop();
//            
//            if (!IsCompare(c, s[nowIndex]))
//            {
//                return false;
//            }
//        }
//
//        if (right > left)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int solution(string s) {
//    if (s.length() % 2 == 1)
//    {
//        return 0;
//    }
//
//    int answer = 0;
//
//    for (; rotateCount < s.length();)
//    {
//        if (IsNormallyBracket(s))
//        {
//            rotateCount += 2;
//            ++answer;
//        }
//        else
//        {
//            ++rotateCount;
//        }
//    }
//
//    return answer;
//}