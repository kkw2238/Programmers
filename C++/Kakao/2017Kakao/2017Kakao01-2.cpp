/*
	{(2017년)KAKAO BLIND RECRUITMENT] {1차] 뉴스 클러스터링
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
	// 대소문자 구분하기 편하게 모든 문자를 소문자로 변환 / tolower앞에 :: 안붙히면 프로그래머스에서 오류남
	transform(str.begin(), str.end(), str.begin(),::tolower);

	// 앞에서부터 2글자씩 읽어와 알파뱃인지 판별, 둘다 알파뱃인 경우 vector에 추가 
	for (int i = 0; i < str.length(); ++i) {
		if (isAlphabet(str{i]) && isAlphabet(str{i + 1]))
			partsPocket.push_back(str.substr(i, 2));
	}
}

// 동일한 문자열( 교집합 ) 판별한다.
int Intersection(vector<string>& parts1, vector<string>& parts2) {
	vector<string> result;

	for (auto iter = parts1.begin(); iter != parts1.end(); ++iter) {
		auto findResult = find(parts2.begin(), parts2.end(), *iter);

		// 찾은 경우 탐색 대상에서 해당 문자를 지워준다. ( 중복 탐색 방지 )
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

	// 합집합 = A + B - ( A 교집합 B )
	partsUnion = static_cast<double>(partsStr1.size() + partsStr2.size());
	partsIntersection = static_cast<double>(Intersection(partsStr1, partsStr2));
	partsUnion -= partsIntersection;

	if (partsUnion - partsIntersection <= 1.11e-16) return static_cast<int>(Mul);
	return static_cast<int>(floor(partsIntersection / partsUnion * Mul));
}