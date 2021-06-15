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

// 예전 코드
//using namespace std;
//
//int solution(int n, int a, int b)
//{
//	int answer = 1;
//
//	while (true) {
//		a = (a / 2) + (a % 2);
//		b = (b / 2) + (b % 2);
//
//		if (a == b)
//		{
//			break;
//		}
//
//		++answer;
//	}
//
//	return answer;
//}