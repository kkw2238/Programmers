/*
	https://programmers.co.kr/learn/courses/30/lessons/12911
*/
#include <bitset>

using namespace std;

int solution(int n) {
	int nOneCount = bitset<20>(n).count();

	while (nOneCount != bitset<20>(++n).count()) 
	{
	}

	return n;
}

// 이전 코드
//using namespace std;
//
//int GetBinary1(int n) {
//	int oneCount = 0;
//
//	while (n > 0)
//	{
//		if (n % 2 == 1)
//		{
//			++oneCount;
//		}
//	}
//
//	return oneCount;
//}
//
//int solution(int n) {
//	int nOneCount = GetBinary1(n);
//
//	for (int i = n + 1; n < (n << 1); ++i) 
//	{
//		if (nOneCount == GetBinary1(i))
//		{
//			return i;
//		}
//	}
//
//	return n << 1;
//}