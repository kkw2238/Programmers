#include <string>
#include <vector>
#include <set>
using namespace std;

void CreateSet(set<int>& s)
{
	int mul = 2;
	while (s.size() <= 10000)
	{

		for (int n = 1; n < 100000000; ++n)
		{
			int k = 0;
			for (int m = 0; m < mul; ++m)
			{
				if (m == 0)
					k = n;
				else
				{
					k *= (n + m);
				}
			}
			if (k > 1000000000000)
			{
				break;
			}
			else
			{
				s.insert(k);
			}
		}
		mul++;
	}
}

long long solution(int n) {
	long long answer = 0;
	set<int> s;
	CreateSet(s);

	auto b = s.begin();
	int index = 0;
	while (true)
	{
		if (index == n)
		{
			answer = *b;
			break;
		}
		index++;
	}
	return answer;
}