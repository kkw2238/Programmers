/*
    https://school.programmers.co.kr/learn/courses/30/lessons/132267
*/

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a)
    {
        answer += (n / a) * b;
        n = (n / a) * b + n % a;
    }

    return answer;
}