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
		// 알파벳이 아닌경우 바로 반환
		if (!isalpha(c))
		{
			return c;
		}

		// 모든 문자열을 tolower로 변환해 최종 offset을 구하고
		const char FINAL_CHARACTER = LOWER_START_POS + (tolower(c) + n - LOWER_START_POS) % TOTAL_ALPHABETCOUNT;

		if (isupper(c))
		{
			// 원본이 대문자인 경우 toupper로 반환
			return static_cast<char>(toupper(FINAL_CHARACTER));
		}

		// 그 외의 경우 그대로 반환
		return static_cast<char>(FINAL_CHARACTER);
	});

	return s;
}