/*
    https://programmers.co.kr/learn/courses/30/lessons/12938
*/
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (s / n == 0)
    {
        return vector<int>{-1};
    }

    vector<int> answer(n - (s % n), s / n);
    vector<int> addAnswer(s % n, s / n + 1);
    answer.insert(answer.end(), addAnswer.begin(), addAnswer.end());

    return answer;
}