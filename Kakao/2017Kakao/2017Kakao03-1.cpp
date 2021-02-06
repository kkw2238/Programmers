/*
	{(2017년)KAKAO BLIND RECRUITMENT] {3차] 파일명 정리
	https://programmers.co.kr/learn/courses/30/lessons/17686
*/

#include "Util.h"

using namespace std;

static int fileIndex = 0;

class FileName {
public:
	FileName(string& file) {
		mIndex = fileIndex++;

		// Head 탐지
		auto iter = find_if(file.begin(), file.end(), {](char c) { return c <= '9' && c >= '0'; });
		// Head 추출
		mHead = file.substr(0, distance(file.begin(), iter));
		file.erase(file.begin(), iter);

		// Number 탐지
		iter = find_if(file.begin(), file.end(), {](char c) { return c > '9' || c < '0'; });
		iter = distance(file.begin(), iter) > 5 ? file.begin() + 5 : iter;
		// Number 추출
		mNumber = file.substr(0, distance(file.begin(), iter));
		mIntNumber = stoi(mNumber);
		file.erase(file.begin(), iter);

		// Tail 추출
		mTail = file;
		file.clear();
	}

	// 대문자 변경 - 실제 코드에 transform 함수가 있으니 그것을 이용하자.
	string UpperString(const string& str) {
		string result = "";

		for (const char& c : str) result += toupper(c);

		return result;
	}

	/*
		대문자 변경 후 두 문자열의 일치 여부를 판단 하는 함수
		string.h에 있는 strcpmi함수와 같은 동작을 한다.
		프로그래머스에는 strcpmi 함수가 작동하지 않음.
	*/
	int Strcmpi(string lphs, string rphs) {
		string eraseSpacelphs = UpperString(lphs);
		string eraseSpacerphs = UpperString(rphs);

		return eraseSpacelphs.compare(eraseSpacerphs);
	}

	bool operator<(const FileName& rphs) {
		// Head 비교
		if (Strcmpi(mHead.data(), rphs.mHead.data()) != 0)
			return UpperString(mHead) < UpperString(rphs.mHead);

		// 숫자 비교
		if (mIntNumber != rphs.mIntNumber)
			return mIntNumber < rphs.mIntNumber;

		return mIndex < rphs.mIndex;
	}
public:
	string GetName() const noexcept { return mHead + mNumber + mTail; }

public:
	string mHead = "";
	string mNumber = "";
	string mTail = "";
	int mIntNumber = 0;

	int mIndex = 0;
};

vector<string> solution(vector<string> files) {
	vector<FileName> fileNames(files.begin(), files.end());
	vector<string> answer;

	sort(fileNames.begin(), fileNames.end());

	for (FileName& file : fileNames)
		answer.push_back(file.GetName());

	return answer;
}