/*
	https://programmers.co.kr/learn/courses/30/lessons/60058
*/

#include <string>
#include <vector>

using namespace std;

const int BURCKET_CHAR_START = '(';

bool IsCorrectBurcket(const string& s)
{
	int burcketCount[2]{ 0, 0 };

	for (const char c : s)
	{
		++burcketCount[c - BURCKET_CHAR_START];

		// ')'이 '(' 갯수보다 많은 경우 => ())( 혹은 )( 와 같은 경우 
		if (burcketCount[0] < burcketCount[1])
		{
			// 올바른 문자열이 아니기에 false반환
			return false;
		}
	}

	return true;
}

string ReverseBurcket(const string& p)
{
	string result = "";

	const char burckets[2]{ ')', '(' };

	for (const char c : p)
	{
		// ')' '(' 에 따라 반대 괄호를 삽입
		result.push_back(burckets[(int)c - BURCKET_CHAR_START]);
	}

	return result;
}

string DistributeUV(string& p)
{
	// Step1. p 가 비어있는 경우 p를 반환
	if (p.empty())
	{
		return p;
	}

	string U = "";
	string V = "";
	int burcketCount[2]{ 0, 0 };

	// Step2. 균형잡힌 괄호 문자열 U와 나머지 V로 분리
	for (size_t i = 0; i < p.size(); ++i)
	{
		// 균형잡힌 괄호 문자열 판단을 위한 카운팅
		++burcketCount[p[i] - BURCKET_CHAR_START];

		U.push_back(p[i]);

		if (burcketCount[0] == burcketCount[1])
		{
			// U를 제외한 나머지를 V에 저장
			V = p.substr(i + 1);
			break;
		}
	}

	// V에 대해 1부터 다시 시작( U가 올바른 괄호 문자열 여부 상관 없이 V는 step1부터 다시 해야한다. )
	V = DistributeUV(V);

	// Step3. U가 올바른 괄호 문자열인 경우 
	if (IsCorrectBurcket(U))
	{
		// Step3 - 1. 1단계부터 시작한 V를 뒤에 연결
		U.append(V);
	}
	// Step4. U가 올바르지 못한 괄호 문자열인 경우
	else
	{
		// Step4 - 1. 빈문자열에 '(' 추가
		string newp = "(";

		// Step4 - 2, 3, Step 1부터 시작한 V와 ')' 를 뒤에 붙여준다.
		newp.append(V + ")");
		// Step4 - 4. U의 맨 앞,뒤 문자열을 자르고 남은 문자열에 대해 괄호를 뒤집어 뒤에 붙인다.
		newp.append(ReverseBurcket(U.substr(1, U.length() - 2)));
		U = newp;
	}

	return U;
}

string solution(string p) {
	return DistributeUV(p);
}

/*
#include <string>
#include <vector>

using namespace std;

const char RB = ')', LB = '(';

int FinduIndex(const string& str) {
	int rightBracket = 0, leftBracket = 0;

	for (const char c : str) {
		if (c == RB) ++rightBracket;
		else ++leftBracket;

		if (rightBracket == leftBracket) break;
	}

	return rightBracket + leftBracket;
}

bool IsRightString(const string& str) {
	int rightBracket = 0, leftBracket = 0;

	for (const char c : str) {
		if (c == RB) ++rightBracket;
		else ++leftBracket;

		if (rightBracket > leftBracket) return false;
	}

	return true;
}

string MakeReverseBrackets(const string& str) {
	string result = str.substr(1, str.length() - 2);
	for (char& c : result) {
		if (c == RB) c = LB;
		else c = RB;
	}

	return result;
}

string MakeRightBrackets(const string& str) {
	if (str.empty()) return "";

	int uIndex = FinduIndex(str);
	string u = str.substr(0, uIndex), v = str.substr(uIndex);

	if (!IsRightString(u)) return "(" + MakeRightBrackets(v) + ")" + MakeReverseBrackets(u);
	else return u + MakeRightBrackets(v);
}

string solution(string p) {
	if (p.empty()) return p;

	string answer = "";

	answer = MakeRightBrackets(p);

	return answer;
}
*/