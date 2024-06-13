/*
    https://programmers.co.kr/learn/courses/30/lessons/68935
*/

#include <string>

using namespace std;

const int DIGIT_COUNT = 3;

string ToTernary(int n)
{
    const char DIGIT[DIGIT_COUNT] = { '0', '1', '2' };
    string toTernary = "";

    while (n > 0)
    {
        toTernary += DIGIT[n % DIGIT_COUNT];
        n /= DIGIT_COUNT;
    }
    
    return toTernary;
}

int ToInt(string& ternary)
{
    const char ZERO_CHARACTER = '0';
    const int LENGTH = ternary.length();
    int toInt = 0;

    for (int index = 0; index < LENGTH; ++index)
    {
        toInt += pow(DIGIT_COUNT, LENGTH - index - 1) * (ternary[index] - ZERO_CHARACTER);
    }

    return toInt;
}

int solution(int n) 
{
    string ternary = ToTernary(n);
    return ToInt(ternary);
}

/*   이전 코드
#include <string>
#include <vector>

using namespace std;

string TransformTernary(int n) {
    string result = "";
    const char NUMBER[3] = { '0', '1', '2' };

    while (n > 0) {
        result += NUMBER[n % 3];
        n /= 3;
    }

    return result;
}

int TransformDemical(string& s) {
    int result = 0, digit = 1;
    const int NUMBER_CHARACTER = '0';

    for (int i = s.length() - 1; i > 0; --i) {
        result += (s[i] - NUMBER_CHARACTER) * digit;
        digit *= 3;
    }

    return result;
}

int solution(int n) {
    string convertedTernary = TransformTernary(n);
    return TransformDemical(convertedTernary);
}
*/