/*
*  https://programmers.co.kr/learn/courses/30/lessons/12954
*/
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n);

    for (long long i = 0; i < n; ++i)
    {
        answer[i] = (i + 1) * x;
    }

    return answer;
}