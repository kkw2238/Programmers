/*
	https://programmers.co.kr/learn/courses/30/lessons/12924
*/

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0, j = 1;

    for (int i = 1; i <= n; ++i)
    {
        sum += i;

        if (sum >= n)
        {
            if (sum == n)
            {
                ++answer;
            }

            sum = 0;
            i = ++j;
        }
    }

    return answer;
}