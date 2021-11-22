#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    if ((n & 1) == 1)
    {
        return 2;
    }

    int answer = --n;
    for (int i = 2; i <= sqrt(n) + 1; ++i)
    {
        if (n % i == 0)
        {
            answer = i;
            break;
        }
    }

    return answer;
}