/*
	https://programmers.co.kr/learn/courses/30/lessons/17682
*/

#include <string>
#include <vector>
#include <sstream>

using namespace std;

const int GAME_COUNT = 3;

int RoundResult(const int originalThisRoundScore, const char bonus) 
{
	// S
	int totalScoreThisRound = originalThisRoundScore;

	switch (bonus)
	{
		// T�� ��� �Ʒ��� �������鼭 D���� ó���ϱ⿡ 3���� ����
	case 'T':
		totalScoreThisRound *= originalThisRoundScore;
	case 'D':
		totalScoreThisRound *= originalThisRoundScore;
	}

	return totalScoreThisRound;
}

void ProcessingOption(vector<int>& scores, const char option)
{
	// solution���� emplace_back�� ���� �����߱� ������ size() - 1�� �׻� ���� ���带 ����Ų��.
	const int THIS_ROUND = scores.size() - 1;
	switch (option)
	{
	case '*':
		// ���� ���ھ 2�� ó��
		scores[THIS_ROUND] *= 2;
		if (THIS_ROUND > 0)
		{
			// ���� ���ھ ���� ��� �ش� ���ھ 2�� ó��
			scores[THIS_ROUND - 1] *= 2;
		}
		break;
	case '#':
		// ���� ���� ���� ó��
		scores[THIS_ROUND] *= -1;
		break;
	}
}

const bool IsNotOption(const char option)
{
	return option != '*' && option != '#';
}

int solution(string dartResult) {
	stringstream ss(dartResult);
	vector<int> scores;
	int answer = 0;

	for (int round = 0; round < GAME_COUNT; ++round)
	{
		int score = 0;
		char bonus = '\0';
		char option = '\0';
		
		// sstream�� �̿��Ͽ� ���ھ�, ���ʽ�, �ɼ��� �����س���.
		ss >> score >> bonus >> option;
		scores.emplace_back(RoundResult(score, bonus));
		
		// option�� ����ִ��� �Ǻ� ('*', '#')
		if (IsNotOption(option))
		{
			// �ɼ��� �ƴ� ��� seek�� 1ĭ ������ ������.
			ss.unget();
		}
		else
		{
			// �ɼ��� ��� �ɼǿ� �´� ��� ����
			ProcessingOption(scores, option);
		}
	}

	// ���� ���ھ���� �ջ�
	for (int score : scores)
	{
		answer += score;
	}

	return answer;
}