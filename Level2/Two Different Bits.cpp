/*
	https://programmers.co.kr/learn/courses/30/lessons/77885?language=cpp
*/

#include <string>
#include <vector>
#include <bitset>

using namespace std;

const int BIT_MAXIMUM_LENGTH = 51;
const int DIFFERENCE_MAXIMUM_COUNT = 2;

int GetBitCount(long long number)
{
    int count = 0;

    while (number > 0)
    {
        if (number & 1)
        {
            ++count;
        }

        number = number >> 1;
    }

    return count;
}

long long FindNextNumber(const long long& number)
{
    for (long long ll = number + 1; ; ++ll)
    {
        bitset<BIT_MAXIMUM_LENGTH> andOperatedNumber(number & ll);
        bitset<BIT_MAXIMUM_LENGTH> orOperatedNumber(number | ll);

        int differenceBitCount = GetBitCount(number | ll) - GetBitCount(number & ll);

        if (differenceBitCount > 0 && differenceBitCount <= DIFFERENCE_MAXIMUM_COUNT)
        {
            return ll;
        }
    }
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (const long long& number : numbers)
    {
        answer.emplace_back(FindNextNumber(number));
    }

    return answer;
}