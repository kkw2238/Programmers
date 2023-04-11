/*
	https://school.programmers.co.kr/learn/courses/30/lessons/161988
*/

#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long sum = 0, sumOdd = 0;
    long long avg[2] = { 1, -1 };

    for (int i = 0; i < sequence.size(); ++i)
    {
        sum = max(sequence[i] * avg[i % 2], sum + sequence[i] * avg[i % 2]);
        sumOdd = max(sequence[i] * avg[(i + 1) % 2], sumOdd + sequence[i] * avg[(i + 1) % 2]);

        answer = max(sumOdd, max(sum, answer));
    }

    return answer;
}