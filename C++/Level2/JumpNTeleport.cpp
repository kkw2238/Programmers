/*
	https://programmers.co.kr/learn/courses/30/lessons/12980
*/

using namespace std;

int solution(int n)
{
	int answer = 0;
	
	// n위치에서 백트랙킹
	while (n > 0)
	{
		// 짝수인 경우( 2로 나누어 떨어지는 경우 ) 텔레포트
		if (n % 2 == 0) 
		{
			n /= 2;
		}
		// 아닌 경우 1칸씩 이동
		else
		{
			--n;
			++answer;
		}
	}

	return answer;
}

/* 예전 코드
using namespace std;

int solution(int n)
{
	int answer = 0;
	while (n > 0) {
		if (n % 2 == 0) n /= 2;
		else {
			--n;
			++answer;
		}
	}

	return answer;
}
*/