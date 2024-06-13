/*
	https://programmers.co.kr/learn/courses/30/lessons/12951
*/

#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
	bool isJaden = true;

	transform(s.begin(), s.end(), s.begin(), [&isJaden](char c) {
		if (c == ' ')
		{
			isJaden = true;
		}
		else if (isJaden)
		{
			c = toupper(c);
			isJaden = false;
		}
		else
		{
			c = tolower(c);
		}
		return c;
	});

	return s;
}

// 예전 코드
//#include <string>
//#include <algorithm>
//#include <cctype>
//
//using namespace std;
//
//string solution(string s) {
//	bool isFirstWord = true;
//	transform(s.begin(), s.end(), s.begin(), [&isFirstWord](char c) {
//		if (c == ' ') {
//			isFirstWord = true;
//			return c;
//		}
//		else if (isFirstWord) {
//			isFirstWord = false;
//			return static_cast<char>(toupper(c));
//		}
//		else {
//			return static_cast<char>(tolower(c));
//		}
//
//	});
//
//	return s;
//}