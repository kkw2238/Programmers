/*
	{(2017��)KAKAO BLIND RECRUITMENT] {1��] ��Ʈ
	https://programmers.co.kr/learn/courses/30/lessons/17682
*/
#include <string>
#include <algorithm>

using namespace std;

// �� ������ ��� ���� ��ȯ
int RoundResult(const int score, const char bonus, const char option, int& beforeRoundScore) {
	int originScore = score, optionBonusScore = 0;

	// ���ʽ� ������ T�� ��� ^3, D�� ��� ^2 �����ش�.
	switch (bonus) {
	case 'T': originScore *= score;
	case 'D': originScore *= score;
	}

	switch (option) {
	case '*':
		originScore *= 2;
		// ���� ������ �̹� ���� ���忡�� 1ȸ ó���߱� ������ �̹� ���忡�� 1���� ó���� �ָ� �ȴ�.
		optionBonusScore = beforeRoundScore;
		break;
	case '#':
		originScore *= -1;
		break;
	}

	// ���ʽ��� ����� ������ �����Ѵ�.
	beforeRoundScore = originScore;
	return originScore + optionBonusScore;
}

int solution(string dartResult) {
	int answer = 0, beforeRoundScore = 0;
	auto iter = dartResult.begin();
	for (int i = 0; i < 3; ++i) {

		// ���ڰ� �ƴ� ���ڿ�( ���ʽ� ���� )��ġ�� ã�´�.
		auto findIter = find_if(iter, dartResult.end(), {](char c) { return c > '9' || c < '0'; });
		// ������ ã�� ��ġ�κ��� string�� �������� �Ÿ��� 2 �̻��� ��� 2��° ���ڸ�, �ƴ� ��� ������ �����Ѵ�.
		char opt = distance(findIter, dartResult.end()) >= 2 ? findIter{1] : ' ';

		// ������ ����
		answer += RoundResult(stoi(string(iter, findIter)), findIter{0], opt, beforeRoundScore);
		// ���� ���� ������ Ž���Ѵ�.
		iter = find_if(findIter, dartResult.end(), {](char c) { return c <= '9' && c >= '0'; });
	}
	return answer;
}
