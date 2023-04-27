/*
	https://school.programmers.co.kr/learn/courses/30/lessons/135808
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int result = 0;
    sort(score.begin(), score.end());

    for (int i = score.size() - m; i >= 0; i -= m)
    {
        result += score[i] * m;
    }

    return result;
}