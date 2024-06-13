/*
	{(2017��)KAKAO BLIND RECRUITMENT] {1��] ���� Ŭ�����͸�
	https://programmers.co.kr/learn/courses/30/lessons/17677
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const bool isAlphabet(const char c) {
	return c <= 'z' && c >= 'a';
}

void MakeParts(string& str, vector<string>& partsPocket) {
	// ��ҹ��� �����ϱ� ���ϰ� ��� ���ڸ� �ҹ��ڷ� ��ȯ / tolower�տ� :: �Ⱥ����� ���α׷��ӽ����� ������
	transform(str.begin(), str.end(), str.begin(),::tolower);

	// �տ������� 2���ھ� �о�� ���Ĺ����� �Ǻ�, �Ѵ� ���Ĺ��� ��� vector�� �߰� 
	for (int i = 0; i < str.length(); ++i) {
		if (isAlphabet(str{i]) && isAlphabet(str{i + 1]))
			partsPocket.push_back(str.substr(i, 2));
	}
}

// ������ ���ڿ�( ������ ) �Ǻ��Ѵ�.
int Intersection(vector<string>& parts1, vector<string>& parts2) {
	vector<string> result;

	for (auto iter = parts1.begin(); iter != parts1.end(); ++iter) {
		auto findResult = find(parts2.begin(), parts2.end(), *iter);

		// ã�� ��� Ž�� ��󿡼� �ش� ���ڸ� �����ش�. ( �ߺ� Ž�� ���� )
		if (findResult != parts2.end()) {
			result.push_back(*findResult);
			parts2.erase(findResult);
		}
	}

	return result.size();
}

int solution(string str1, string str2) {
	const double Mul = 65536.0;
	double partsUnion, partsIntersection;

	vector<string> partsStr1, partsStr2;

	MakeParts(str1, partsStr1);
	MakeParts(str2, partsStr2);

	// ������ = A + B - ( A ������ B )
	partsUnion = static_cast<double>(partsStr1.size() + partsStr2.size());
	partsIntersection = static_cast<double>(Intersection(partsStr1, partsStr2));
	partsUnion -= partsIntersection;

	if (partsUnion - partsIntersection <= 1.11e-16) return static_cast<int>(Mul);
	return static_cast<int>(floor(partsIntersection / partsUnion * Mul));
}