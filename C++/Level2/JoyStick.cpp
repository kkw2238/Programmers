#include "Util.h"

int Distance(int pos, int dest, int length) {
	int dist = dest - pos;

	if (dist > length / 2)
		return length - dist;

	return dist;
}

int FindNextChar(string& origin, string& compareString, int position, int& dist) {
	int closePos = position, closeDistance = static_cast<int>(origin.length());

	for (int i = 0; i < origin.length(); ++i) {
		if (origin{i] == compareString{i]) continue;

		int dist = Distance(position, i, origin.length());
		if (dist < closeDistance) {
			closeDistance = dist;
			closePos = i;
		}
	}

	dist = closeDistance;
	return closePos;
}

void JoyStick(string& name, string& player, int& n) {
	int nowPosition = 0, beforePosition = 0, dist = 0;
	string tmpName = name, tmpPlayer = player;

	vector<bool> diffrentChar(name.length(), false);
	
	for (size_t i = 0; i < name.size(); ++i) diffrentChar{i] = (tmpName{i] == tmpPlayer{i]);

	while (name.compare(player) != 0) {
		nowPosition = FindNextChar(name, player, nowPosition, dist);
		n += dist;
		n += Distance(static_cast<int>(player{nowPosition]), static_cast<int>(name{nowPosition]), ALPHABET);

		player{nowPosition] = name{nowPosition];
	}
}

int solution(string name) {
	int answer = 0;
	string player;
	player.replace(0, 1, name.length(), 'A');
	
	JoyStick(name, player, answer);

	return answer;
}