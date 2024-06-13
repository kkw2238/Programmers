/*
	https://school.programmers.co.kr/learn/courses/30/lessons/140107
*/

#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long powD = (long long)d * (long long)d;

    for (long long y = 0; y <= d; y += k)
    {
        answer += sqrtl(powD - y * y) / (long long)k + 1;
    }

    return answer;
}