/*
	https://school.programmers.co.kr/learn/courses/30/lessons/131127
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> wantCount;
    int answer = 0;
    int zeroCount = 0;

    for (int i = 0; i < want.size(); ++i)
    {
        wantCount[want[i]] = number[i];
    }

    for (int day = 0; day < discount.size(); ++day)
    {
        if (day >= 10)
        {
            if (wantCount.find(discount[day - 10]) != wantCount.end())
            {
                if (++wantCount[discount[day - 10]] == 1)
                {
                    --zeroCount;
                }
            }
        }

        if (wantCount.find(discount[day]) != wantCount.end())
        {
            if (--wantCount[discount[day]] == 0)
            {
                ++zeroCount;
            }

            if (zeroCount == wantCount.size())
            {
                ++answer;
            }
        }
    }
    return answer;
}