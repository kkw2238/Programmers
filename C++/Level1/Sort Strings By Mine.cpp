/*
	https://programmers.co.kr/learn/courses/30/lessons/12915
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	
	sort(strings.begin(), strings.end(), [&n](const string& a, const string& b)
	{
		// n��° �ε����� ���ڰ� ���� ��� ���ڿ� ��ü�� �������� ����
		if (a[n] == b[n])
		{
			return a < b;
		}
		// �� �ܿ��� n��° �ε����� ���� �������� ����
		return a[n] < b[n];
	});
	
	return strings;
}
