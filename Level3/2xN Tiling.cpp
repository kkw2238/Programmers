/*
    https://programmers.co.kr/learn/courses/30/lessons/12900
*/

#include <vector>

using namespace std;

int solution(int n) {
    const int DIV = 1000000007;
    vector<int> fib(n + 1, 1);

    for (int i = 2; i <= fib.size(); ++i)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % DIV;
    }

    return fib[n];
}