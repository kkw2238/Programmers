/*
	https://programmers.co.kr/learn/courses/30/lessons/77885?language=cpp
*/
#include <vector>
#include <bitset>
#include <string>

using namespace std;

const int DIFFERENCE_MAXIMUM_COUNT = 2;
const int MAXIMUM_BIT_COUNT = 52;

long long FindNextNumber(const long long& number)
{
    if (number % 2 == 0)
    {
        return number + 1;
    }

    bitset<MAXIMUM_BIT_COUNT> bs(number);
    string str = bs.to_string();
    size_t index = str.rfind("01");
    
    str.replace(str.begin() + index, str.begin() + index + 2, "10");

    return stoll(str, 0, 2);
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (const long long& number : numbers)
    {
        answer.emplace_back(FindNextNumber(number));
    }

    return answer;
}