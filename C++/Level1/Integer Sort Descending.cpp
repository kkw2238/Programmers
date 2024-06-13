/*
	https://programmers.co.kr/learn/courses/30/lessons/12933
*/

#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	// ���ڿ��� ��ȯ
	string numStr = to_string(n);

	// ��ȯ�� ���ڿ��� ������������ ����
	sort(numStr.begin(), numStr.end(), greater<char>());

	// ������ ���ڸ� long long ����ȯ
	return stoll(numStr);
}