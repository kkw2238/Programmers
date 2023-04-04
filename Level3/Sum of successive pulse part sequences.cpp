/*
	https://school.programmers.co.kr/learn/courses/30/lessons/161988
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = -100000;
    long long sum = 0;
    long long mulIndex = 0;
    int mul[2] = { 1, -1 };

    for (int i = 0; i < sequence.size(); ++i)
    {
        if (((long long)sequence[i] * mul[0]) > (sum + sequence[i] * mul[mulIndex % 2]))
        {
            mulIndex = 0;
        }

        sum = sum + sequence[i] * mul[mulIndex++ % 2];
        answer = max(sum, answer);
    }

    return answer;
}