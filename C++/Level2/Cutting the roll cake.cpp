/*
	https://school.programmers.co.kr/learn/courses/30/lessons/132265
*/

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    map<int, int> lTopping;
    map<int, int> rTopping;
    int answer = 0;

    for (int i : topping)
    {
        ++rTopping[i];
    }

    for (int t : topping)
    {
        --rTopping[t];
        if (rTopping[t] == 0)
        {
            rTopping.erase(t);
        }
        ++rTopping[t];

        if (lTopping.size() == rTopping.size())
        {
            ++answer;
        }
    }

    return answer;
}