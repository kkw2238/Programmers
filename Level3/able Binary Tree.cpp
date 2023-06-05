/*
	https://school.programmers.co.kr/learn/courses/30/lessons/150367
*/

#include <string>
#include <vector>
#include <bitset>

using namespace std;


void getBiset(long long num)
{
    long long offset = 1;
    long long bitCount = 1;

    for (bitCount; bitCount <= num;)
    {
        offset *= 2;
        bitCount += offset;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    return answer;
}