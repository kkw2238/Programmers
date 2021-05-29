/*
	https://programmers.co.kr/learn/courses/30/lessons/12980
*/

using namespace std;

int solution(int n)
{
	int answer = 0;
	
	// n��ġ���� ��Ʈ��ŷ
	while (n > 0)
	{
		// ¦���� ���( 2�� ������ �������� ��� ) �ڷ���Ʈ
		if (n % 2 == 0) 
		{
			n /= 2;
		}
		// �ƴ� ��� 1ĭ�� �̵�
		else
		{
			--n;
			++answer;
		}
	}

	return answer;
}

/* ���� �ڵ�
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