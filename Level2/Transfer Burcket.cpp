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

		// ')'�� '(' �������� ���� ��� => ())( Ȥ�� )( �� ���� ��� 
		if (burcketCount[0] < burcketCount[1])
		{
			// �ùٸ� ���ڿ��� �ƴϱ⿡ false��ȯ
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
		// ')' '(' �� ���� �ݴ� ��ȣ�� ����
		result.push_back(burckets[(int)c - BURCKET_CHAR_START]);
	}

	return result;
}

string DistributeUV(string& p)
{
	// Step1. p �� ����ִ� ��� p�� ��ȯ
	if (p.empty())
	{
		return p;
	}

	string U = "";
	string V = "";
	int burcketCount[2]{ 0, 0 };

	// Step2. �������� ��ȣ ���ڿ� U�� ������ V�� �и�
	for (size_t i = 0; i < p.size(); ++i)
	{
		// �������� ��ȣ ���ڿ� �Ǵ��� ���� ī����
		++burcketCount[p[i] - BURCKET_CHAR_START];

		U.push_back(p[i]);

		if (burcketCount[0] == burcketCount[1])
		{
			// U�� ������ �������� V�� ����
			V = p.substr(i + 1);
			break;
		}
	}

	// V�� ���� 1���� �ٽ� ����( U�� �ùٸ� ��ȣ ���ڿ� ���� ��� ���� V�� step1���� �ٽ� �ؾ��Ѵ�. )
	V = DistributeUV(V);

	// Step3. U�� �ùٸ� ��ȣ ���ڿ��� ��� 
	if (IsCorrectBurcket(U))
	{
		// Step3 - 1. 1�ܰ���� ������ V�� �ڿ� ����
		U.append(V);
	}
	// Step4. U�� �ùٸ��� ���� ��ȣ ���ڿ��� ���
	else
	{
		// Step4 - 1. ���ڿ��� '(' �߰�
		string newp = "(";

		// Step4 - 2, 3, Step 1���� ������ V�� ')' �� �ڿ� �ٿ��ش�.
		newp.append(V + ")");
		// Step4 - 4. U�� �� ��,�� ���ڿ��� �ڸ��� ���� ���ڿ��� ���� ��ȣ�� ������ �ڿ� ���δ�.
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