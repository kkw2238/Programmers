/*
	{(2017��)KAKAO BLIND RECRUITMENT] {3��] ���ϸ� ����
	https://programmers.co.kr/learn/courses/30/lessons/17686
*/

#include "Util.h"

using namespace std;

static int fileIndex = 0;

class FileName {
public:
	FileName(string& file) {
		mIndex = fileIndex++;

		// Head Ž��
		auto iter = find_if(file.begin(), file.end(), {](char c) { return c <= '9' && c >= '0'; });
		// Head ����
		mHead = file.substr(0, distance(file.begin(), iter));
		file.erase(file.begin(), iter);

		// Number Ž��
		iter = find_if(file.begin(), file.end(), {](char c) { return c > '9' || c < '0'; });
		iter = distance(file.begin(), iter) > 5 ? file.begin() + 5 : iter;
		// Number ����
		mNumber = file.substr(0, distance(file.begin(), iter));
		mIntNumber = stoi(mNumber);
		file.erase(file.begin(), iter);

		// Tail ����
		mTail = file;
		file.clear();
	}

	// �빮�� ���� - ���� �ڵ忡 transform �Լ��� ������ �װ��� �̿�����.
	string UpperString(const string& str) {
		string result = "";

		for (const char& c : str) result += toupper(c);

		return result;
	}

	/*
		�빮�� ���� �� �� ���ڿ��� ��ġ ���θ� �Ǵ� �ϴ� �Լ�
		string.h�� �ִ� strcpmi�Լ��� ���� ������ �Ѵ�.
		���α׷��ӽ����� strcpmi �Լ��� �۵����� ����.
	*/
	int Strcmpi(string lphs, string rphs) {
		string eraseSpacelphs = UpperString(lphs);
		string eraseSpacerphs = UpperString(rphs);

		return eraseSpacelphs.compare(eraseSpacerphs);
	}

	bool operator<(const FileName& rphs) {
		// Head ��
		if (Strcmpi(mHead.data(), rphs.mHead.data()) != 0)
			return UpperString(mHead) < UpperString(rphs.mHead);

		// ���� ��
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