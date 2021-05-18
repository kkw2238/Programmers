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
		// n번째 인덱스의 문자가 같을 경우 문자열 전체를 기준으로 정렬
		if (a[n] == b[n])
		{
			return a < b;
		}
		// 그 외에는 n번째 인덱스의 문자 기준으로 정렬
		return a[n] < b[n];
	});
	
	return strings;
}
