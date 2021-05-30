/*
	https://programmers.co.kr/learn/courses/30/lessons/70129
*/

#include <string>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int DeleteZero(string& s)
{
    int deletedZeroCount = 0;

    s.erase(remove_if(s.begin(), s.end(), [&deletedZeroCount](char c) 
    {
        if (c != '0')
        {
            return false;
        }

        ++deletedZeroCount;
        return true;
    }), s.end());
    
    return deletedZeroCount;
}

string TransferLengthToBinary(int length)
{
    bitset<20> bs(length);
    
    return bs.to_string().substr(bs.to_string().find('1'));
}

vector<int> solution(string s) {
    vector answer{ 0, 0 };

    while (s.compare("1") != 0)
    {
        answer[1] += DeleteZero(s);
        s = TransferLengthToBinary(s.length());
        ++answer[0];
    }

    return answer;
}