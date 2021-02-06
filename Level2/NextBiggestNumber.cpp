/*
	https://programmers.co.kr/learn/courses/30/lessons/12911
*/

using namespace std;

int GetBinary1(int n) {
	int oneCount = 0;
	while (n != 0) {
		oneCount += n % 2 == 1 ? 1 : 0;
		n /= 2;
	}

	return oneCount;
}

int solution(int n) {
	int nOneCount = GetBinary1(n);

	for (int i = n + 1; n < (n << 1); ++i) {
		if (nOneCount == GetBinary1(i))
			return i;
	}
	return n << 1;
}