/*
	https://school.programmers.co.kr/learn/courses/30/lessons/150367
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isAble(string& bit, long long index, int tier)
{
    bool result = true;
    if (tier == 1)
    {
        return result;
    }

    long long left = index - pow(2, (tier - 2));
    long long right = index + pow(2, (tier - 2));

    if (bit[index] == '0' && (bit[left] == '1' || bit[right] == '1'))
    {
        return false;
    }

    result = result && isAble(bit, left, tier - 1);
    if (result)
    {
        result = result && isAble(bit, right, tier - 1);
    }

    return result;
}

bool getBitset(long long num)
{
    if (num == 1)
    {
        return true;
    }
    long long offset = 1;
    long long nowNum = 1;
    int tier = 1;

    for (nowNum; pow(2, nowNum) <= num;)
    {
        offset *= 2;
        nowNum += offset;
        ++tier;
    }

    string bitset(nowNum, '0');
    
    while (num > 0)
    {
        bitset[nowNum - 1] = (num % 2) + '0';
        num /= 2;
        --nowNum;
    }

    return isAble(bitset, bitset.length() / 2, tier);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (long long ll : numbers)
    {
        answer.push_back(getBitset(ll));
    }

    return answer;
}