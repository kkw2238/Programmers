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

/* 예전 코드
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int DeletedZero(string& s) {
    int zeroCount = 0;
    s.erase(remove_if(s.begin(), s.end(), [&zeroCount](const char c) {
        if (c != '0') return false;

        ++zeroCount;
        return true;
    }), s.end());

    return zeroCount;
}

string TransLengthBinary(const string& s) {
    string result = bitset<32>(s.length()).to_string();

    return result.substr(result.find('1'));
}

#include <iostream>
vector<int> solution(string s) {
    vector<int> answer(2);

    while (s.compare("1") != 0) {
        ++answer[0];
        answer[1] += DeletedZero(s);
        s = TransLengthBinary(s);
    }

    return answer;
}
*/