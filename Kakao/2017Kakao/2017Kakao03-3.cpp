/*
	{(2017��)KAKAO BLIND RECRUITMENT] {3��] ����
	https://programmers.co.kr/learn/courses/30/lessons/17684
*/
#include "Util.h"

vector<int> solution(string msg) {
	const int ALPHABET_LENGTH = 26;
	int addDic = 1, offset = 1;
	vector<int> answer;
	map<string, int> dictionary;

	// �����ϱ� �� ��� ���ĺ��� ���� ������ map�� �־�д�. ( ���� ����ó���� ���̱� ���� )
	for (char c : msg) dictionary{string{ c }] = c - 'A' + 1;

	for (int i = 0; i < msg.length();) {
		// offset ������ ������ �����. �̶� �⺻ offset�� 1�� ������ KAKAO�� �������� O�� ���� ����� ����ó���� ����
		string wc = msg.substr(i, offset);

		// ã�� ���� ��� ������ ���
		if (dictionary.find(wc) == dictionary.end()) {
			dictionary{wc] = ALPHABET_LENGTH + addDic;
			++addDic;

			// ������ ����� ��� offset -1 ������ ���ڴ� ������ ��ϵǾ� �ִٴ� ���̱� ������ �ش信 �߰�
			answer.push_back(dictionary{msg.substr(i, offset - 1)]);
			i += (offset - 1);
			offset = 1;
		}
		else if (offset + i == msg.length()) {
			// ������ ������ ���
			answer.push_back(dictionary{wc]);
			break;
		}
		else ++offset;
	}

	return answer;
}