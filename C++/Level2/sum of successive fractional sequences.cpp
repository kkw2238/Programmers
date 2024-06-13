/*
	https://school.programmers.co.kr/learn/courses/30/lessons/131701?language=cpp
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> sumofSequence;

    for (int i = 0; i < elements.size(); ++i)
    {
        int s = 0;
        for (int j = i; j < i + elements.size(); ++j)
        {
            s += elements[j % elements.size()];
        }

        sumofSequence.insert(s);
    }

    return answer;
}