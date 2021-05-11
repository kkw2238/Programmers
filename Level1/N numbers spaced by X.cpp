/*
*  https://programmers.co.kr/learn/courses/30/lessons/12954
*/
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n);

    for (int i = 0; i < n; ++i)
    {
        answer[i] = static_cast <long long>(i + 1) * static_cast<long long>(x);
    }

    return answer;
}