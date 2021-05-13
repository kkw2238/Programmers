/*
	https://programmers.co.kr/learn/courses/30/lessons/12943
*/

const int MAXIMUM_COUNT = 500;

long long Collatz(const long long& num)
{
	if (num % 2 == 0)
	{
		return num / 2;
	}
	
	return num * 3 + 1;
}

int solution(int num) {
	long long llNum = static_cast<long long>(num);

	for (int answer = 1; answer < MAXIMUM_COUNT; ++answer)
	{
		llNum = Collatz(llNum);
		if (llNum == 1)
		{
			return answer;
		}
	}

	return -1;
}