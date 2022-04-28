#include <vector>

using namespace std;


// 소인수 분해 하는 함수
vector<int> factor(int n)
{
	// n == 1인경우 1 반환
	if (n == 1)
	{
		return { 1 };
	}

	vector<int> result;

	for (int i = 2; i <= n; ++i)
	{
		// n을 소수로 나눌 수 있는 경우 => 해당 소수로 나눌 수 없을 때까지 나눠준다.
		while (n % i == 0)
		{
			n /= i;
			result.push_back(i);
		}
	}

	return result;
}

//#include <iostream>
//void operator<<(ostream& os, vector<int> data)
//{
//	for (int n : data) {
//		os << n << ", ";
//	}
//	os << '\n';
//}
//
//int main()
//{
//
//	for (int i = 1; i < 100; ++i) {
//		cout << factor(i);
//	}
//
//}