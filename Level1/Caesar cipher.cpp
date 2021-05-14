/*
	https://programmers.co.kr/learn/courses/30/lessons/12926
*/

#include <string>
#include <algorithm>

using namespace std;

string solution(string s, int n) {
	const char TOTAL_ALPHABETCOUNT = 'z' - 'a' + 1;
	const char LOWER_START_POS = 'a';

	transform(s.begin(), s.end(), s.begin(), [&n](const char c) {
		// ���ĺ��� �ƴѰ�� �ٷ� ��ȯ
		if (!isalpha(c))
		{
			return c;
		}

		// ��� ���ڿ��� tolower�� ��ȯ�� ���� offset�� ���ϰ�
		const char FINAL_CHARACTER = LOWER_START_POS + (tolower(c) + n - LOWER_START_POS) % TOTAL_ALPHABETCOUNT;

		if (isupper(c))
		{
			// ������ �빮���� ��� toupper�� ��ȯ
			return static_cast<char>(toupper(FINAL_CHARACTER));
		}

		// �� ���� ��� �״�� ��ȯ
		return static_cast<char>(FINAL_CHARACTER);
	});

	return s;
}