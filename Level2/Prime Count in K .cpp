/*
    https://programmers.co.kr/learn/courses/30/lessons/92335?language=cpp
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

string ConvertKNumber(int n, int k)
{
    string result = "";

    while (n > 0)
    {
        result = to_string(n % k) + result;
        n /= k;
    }

    return result;
}

vector<long long> Split(string number, char splitChar)
{
    vector<long long> result;
    
    int split_index = number.find(splitChar);
    int mem_index = 0;
    string split_string = "";

    while (split_index > 0)
    {
        split_string = number.substr(mem_index, split_index - mem_index);

        if (split_string.length() > 0) 
        {
            int splited_num = stoi(split_string);

            if (splited_num > 1)
            {
                result.push_back(splited_num);
            }
        }

        mem_index = split_index + 1;
        split_index = number.find(splitChar, mem_index);
    }

    split_string = number.substr(mem_index);
    if (split_string.length() > 0 && stoll(split_string) > 1)
    {
        result.push_back(stoll(split_string));
    }

    return result;
}

const bool IsPrime(const long long n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    int nowPos = 0;

    vector<long long> converted_SplitNumber = Split(ConvertKNumber(n, k), '0');

    for (long long& num : converted_SplitNumber)
    {
        if (IsPrime(num))
        {
            ++answer;
        }
    }

    return answer;
}