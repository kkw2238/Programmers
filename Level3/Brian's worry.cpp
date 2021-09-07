#include <string>

using namespace std;

const string INVALID = "invalid";

bool IsTypeOne(const string& s)
{
    // 대 소 대 소 대 소 대
    char pattern = 'a';

    if (islower(s[0]) || islower(s[s.length() - 1]))
    {
        return false;
    }

    for (int i = 0; i < s.size(); ++i)
    {
        if (islower(s[i]) && !(i % 2 == 0))
        {
            return false;
        }
    }

    return true;
}

bool IsTypeTwo(const string& s)
{
    char pattern = 'a';

    for (int i = 1; i < s.length() - 1; ++i)
    {
        if (islower(s[i]))
        {
            return false;
        }
    }

    return islower(s[0]) && islower(s[s.length() - 1]);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";

    for (int i = 0; i < sentence.length(); ++i)
    {

    }

    return answer;
}

/*
    타입 1 + 타입 1 => 중간에 대문자 2연속 

    타입 1 + 타입 2 => 대문자 + 다른 소문자
    
    타입 2 + 타입 2 => 중간에 소문자 2연속
    
    타입 2 + 타입 1 => 소문자 + 대문자 
*/