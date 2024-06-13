
/*
    https://programmers.co.kr/learn/courses/30/lessons/86051?language=cpp
*/

#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;

    for (const int number : numbers)
    {
        answer -= number;
    }

    return answer;
}