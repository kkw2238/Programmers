#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int budget)
{
	const int MAXIMUN_BUY_A = budget % a == 0 ? budget / a : budget / a + 1;

	int result = 0;

	for (int i = 0; i <= MAXIMUN_BUY_A; ++i)
	{
		const int remainBudget = budget - (a * i);

		if (remainBudget % b == 0)
		{
			++result;
		}
	}

	return result;
}