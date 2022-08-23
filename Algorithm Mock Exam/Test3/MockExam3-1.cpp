#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n < a)
    {
        int payBack = (n / a) * b;
        n = (n / a) + (n % a) + payBack;
        answer += payBack;
    }

    return answer;
}