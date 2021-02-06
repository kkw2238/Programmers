/*
	{(2017년)KAKAO BLIND RECRUITMENT] {1차] 다트
	https://programmers.co.kr/learn/courses/30/lessons/17682
*/
#include <string>
#include <algorithm>

using namespace std;

// 매 라운드의 결과 값을 반환
int RoundResult(const int score, const char bonus, const char option, int& beforeRoundScore) {
	int originScore = score, optionBonusScore = 0;

	// 보너스 점수가 T인 경우 ^3, D인 경우 ^2 시켜준다.
	switch (bonus) {
	case 'T': originScore *= score;
	case 'D': originScore *= score;
	}

	switch (option) {
	case '*':
		originScore *= 2;
		// 이전 점수는 이미 이전 라운드에서 1회 처리했기 때문에 이번 라운드에서 1번만 처리헤 주면 된다.
		optionBonusScore = beforeRoundScore;
		break;
	case '#':
		originScore *= -1;
		break;
	}

	// 보너스가 적용된 점수를 저장한다.
	beforeRoundScore = originScore;
	return originScore + optionBonusScore;
}

int solution(string dartResult) {
	int answer = 0, beforeRoundScore = 0;
	auto iter = dartResult.begin();
	for (int i = 0; i < 3; ++i) {

		// 숫자가 아닌 문자열( 보너스 점수 )위치를 찾는다.
		auto findIter = find_if(iter, dartResult.end(), {](char c) { return c > '9' || c < '0'; });
		// 위에서 찾은 위치로부터 string의 끝까지의 거리가 2 이상인 경우 2번째 문자를, 아닌 경우 공백을 저장한다.
		char opt = distance(findIter, dartResult.end()) >= 2 ? findIter{1] : ' ';

		// 점수를 저장
		answer += RoundResult(stoi(string(iter, findIter)), findIter{0], opt, beforeRoundScore);
		// 다음 원래 점수를 탐색한다.
		iter = find_if(findIter, dartResult.end(), {](char c) { return c <= '9' && c >= '0'; });
	}
	return answer;
}
