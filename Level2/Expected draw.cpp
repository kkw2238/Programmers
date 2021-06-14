/*
    https://programmers.co.kr/learn/courses/30/lessons/12985
*/

using namespace std;

const int NextNumber(const int n)
{
    return n / 2 + n % 2;
}

int solution(int n, int a, int b)
{
    int answer = 0;

    while (NextNumber(a) != NextNumber(b))
    {
        a = NextNumber(a);
        b = NextNumber(b);

        ++answer;
    }

    return answer;
}