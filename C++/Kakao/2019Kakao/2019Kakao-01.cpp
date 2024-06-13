
#include <string>
#include <vector>

/*
	문자열 압축 효율
	1. for문으로 길이 만큼 확인하며 루프 => 가장 안전
*/

using namespace std;

const bool IsCompare(const string& data, int offset, int length, const string& compareStr) {
	return data.compare(offset, length, compareStr) == 0;
}

int CompressionData(string data, int cutLength) {
	string substr;

	for (int i = 0; i < data.length();) {
		if (i + cutLength > data.length()) break;
		substr = data.substr(i, cutLength);
		int offset = 0;
		while (IsCompare(data, i + cutLength * offset, cutLength, substr)) { ++offset; }

		if (offset > 1) {
			data.replace(data.begin() + i, data.begin() + i + cutLength * offset, to_string(offset) + substr);
			i += (cutLength + to_string(offset).length());
		}
		else i += (offset * cutLength);
	}

	return data.length();
}

int solution(string s) {
	int answer = s.length();

	for (int i = 1; i < s.length(); ++i) {
		int newlength = CompressionData(s, i);
		answer = newlength < answer ? newlength : answer;
	}

	return answer;
}