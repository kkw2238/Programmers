#include <vector>

using namespace std;


// ���μ� ���� �ϴ� �Լ�
vector<int> factor(int n)
{
	// n == 1�ΰ�� 1 ��ȯ
	if (n == 1)
	{
		return { 1 };
	}

	vector<int> result;

	for (int i = 2; i <= n; ++i)
	{
		// n�� �Ҽ��� ���� �� �ִ� ��� => �ش� �Ҽ��� ���� �� ���� ������ �����ش�.
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