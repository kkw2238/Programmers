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
		// T의 경우 아래로 내려가면서 D까지 처리하기에 3제곱 수행
	case 'T':
		totalScoreThisRound *= originalThisRoundScore;
	case 'D':
		totalScoreThisRound *= originalThisRoundScore;
	}

	return totalScoreThisRound;
}

void ProcessingOption(vector<int>& scores, const char option)
{
	// solution에서 emplace_back을 통해 삽입했기 때문에 size() - 1은 항상 현재 라운드를 가르킨다.
	const int THIS_ROUND = scores.size() - 1;
	switch (option)
	{
	case '*':
		// 현재 스코어를 2배 처리
		scores[THIS_ROUND] *= 2;
		if (THIS_ROUND > 0)
		{
			// 이전 스코어가 있을 경우 해당 스코어도 2배 처리
			scores[THIS_ROUND - 1] *= 2;
		}
		break;
	case '#':
		// 현재 라운드 음수 처리
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
		
		// sstream을 이용하여 스코어, 보너스, 옵션을 추출해낸다.
		ss >> score >> bonus >> option;
		scores.emplace_back(RoundResult(score, bonus));
		
		// option이 들어있는지 판별 ('*', '#')
		if (IsNotOption(option))
		{
			// 옵션이 아닐 경우 seek를 1칸 앞으로 보낸다.
			ss.unget();
		}
		else
		{
			// 옵션일 경우 옵션에 맞는 계산 수행
			ProcessingOption(scores, option);
		}
	}

	// 최종 스코어들을 합산
	for (int score : scores)
	{
		answer += score;
	}

	return answer;
}