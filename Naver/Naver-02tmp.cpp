#include <vector>
#include <string>
#include <set>

using namespace std;

const int MAXIMUM = 100000000000;

long long GetMul(int startNum, int length) {
	long long result = 1;
	for (int i = 0; i < length; ++i)
		result *= (startNum + i);

	return result;
}

long long GetSetIndexVal(set<long long>& pocket, int n) {
	if (n - (pocket.size() / 2) < 0) {
		auto iter = pocket.begin();

		for (int i = 0; i < n; ++i)
			++iter;

		return *iter;
	}
	else {
		auto iter = pocket.rbegin();

		for (int i = 0; i < pocket.size() - n; i++)
			++iter;

		return *iter;
	}
}

void CreateSet(set<long long>& pocket, int length, int n) {
	int val = 1;
	for (int i = 1; i <= 1000000; ++i) {
		// °ö
		val = GetMul(i, length);

		// ¸Æ½Ã¸Øº¸´Ù Å« °æ¿ì
		if (val > MAXIMUM) return;

		// pocketÀÇ n¹øÂ° ÀÎµ¦½º º¸´Ù Å« °æ¿ì
		if (pocket.size() > n)
		{
			if (val > GetSetIndexVal(pocket, n))
				return;
		}
		pocket.insert(val);
	}
}

long long solution(int n) {
	long long answer = 0;
	set<long long> pocket;

	int i = 2;
	while (true) {
		if (pocket.size() > n)
		{
			if (GetMul(1, i) > GetSetIndexVal(pocket, n)) break;
		}
		CreateSet(pocket, i, n);
		++i;
	}

	return GetSetIndexVal(pocket, n);
}