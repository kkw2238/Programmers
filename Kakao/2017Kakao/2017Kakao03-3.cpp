/*
	{(2017년)KAKAO BLIND RECRUITMENT] {3차] 압축
	https://programmers.co.kr/learn/courses/30/lessons/17684
*/
#include "Util.h"

vector<int> solution(string msg) {
	const int ALPHABET_LENGTH = 26;
	int addDic = 1, offset = 1;
	vector<int> answer;
	map<string, int> dictionary;

	// 시작하기 전 모든 알파벳에 대한 정보를 map에 넣어둔다. ( 나중 예외처리를 줄이기 위함 )
	for (char c : msg) dictionary{string{ c }] = c - 'A' + 1;

	for (int i = 0; i < msg.length();) {
		// offset 길이의 문장을 끊어낸다. 이때 기본 offset이 1인 이유는 KAKAO와 마지막에 O만 남는 경우의 예외처리를 위함
		string wc = msg.substr(i, offset);

		// 찾지 못한 경우 사전에 등록
		if (dictionary.find(wc) == dictionary.end()) {
			dictionary{wc] = ALPHABET_LENGTH + addDic;
			++addDic;

			// 사전에 등록할 경우 offset -1 까지의 문자는 사전에 등록되어 있다는 뜻이기 때문에 해답에 추가
			answer.push_back(dictionary{msg.substr(i, offset - 1)]);
			i += (offset - 1);
			offset = 1;
		}
		else if (offset + i == msg.length()) {
			// 마지막 글자의 경우
			answer.push_back(dictionary{wc]);
			break;
		}
		else ++offset;
	}

	return answer;
}