#include <string>

using namespace std;

const bool IsPalindrome(const string& s, int startIndex, int length)
{
    for (int i = 0; i <= length / 2; ++i)
    {
        if (s[startIndex + i] != s[startIndex + length - i -1] )
        {
            return false;
        }
    }
    return true;
}

int solution(string s)
{
    int answer = 1;
    for (int startIndex = 0; startIndex <= s.length() / 2; ++startIndex)
    {
        for (int subSLength = 1; subSLength <= (s.length() - startIndex) / 2; ++subSLength)
        {
            for (int i = 0; i < 2; ++i)
            {
                if (IsPalindrome(s, startIndex, subSLength * 2 + i))
                {
                    answer = answer < subSLength * 2 + i ? subSLength * 2 + i : answer;
                }
            }
        }
 
        if (answer > (s.length() - startIndex) * 2)
        {
            return answer;
        }
    }
    
    return answer;
}

#include <iostream>
#include <vector>
int main()
{
    vector<string> testCase{ "abacde", "abcabcdcbae", "aaaa", "abcde", "a", "abcbaqwertrewqq", "abcbaqwqabcba", "abba", "abaabaaaaaaa" };
   
    for (string& s : testCase) {
        cout << s << " : " << solution(s) << '\n';
    }
    
}