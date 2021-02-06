#include <vector>

using namespace std;
const int BALL_NUMBER = 0, STRIKE_COUNT = 1, BALL_COUNT = 2;

#define FN(x) ( x / 100 )
#define SN(x) (( x / 10 ) % 10)
#define TN(x) ( x % 10 )

int GetBallCount(const int num, const int ball) {
	int ballCount = 0;
	const int dividNum[3] = { FN(num), SN(num), TN(num) };
	for (int i = 0; i < 3; ++i) {
		if (i != 0 && dividNum[i] == FN(ball)) ++ballCount;
		if (i != 1 && dividNum[i] == SN(ball)) ++ballCount;
		if (i != 2 && dividNum[i] == TN(ball)) ++ballCount;
	}

	return ballCount;
}

int GetStrikeCount(const int num, const int ball) {
	int strikeCount = 0;
	if (FN(num) == FN(ball)) ++strikeCount;
	if (SN(num) == SN(ball)) ++strikeCount;
	if (TN(num) == TN(ball)) ++strikeCount;

	return strikeCount;
}

bool IsSuitable(const int number, const vector<vector<int>>& baseball) {
	for (const vector<int>& ball : baseball) {
		if (ball[STRIKE_COUNT] != GetStrikeCount(number, ball[BALL_NUMBER])) return false;
		if (ball[BALL_COUNT] != GetBallCount(number, ball[BALL_NUMBER])) return false;
	}

	return true;
}

vector<int> MakeANumber(const vector<vector<int>>& baseball) {
	vector<int> result;
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			if (i == j) continue;
			for (int k = 1; k <= 9; ++k) {
				if (k == j || k == i) continue;
				if (IsSuitable(100 * i + j * 10 + k, baseball))
					result.push_back(100 * i + j * 10 + k);
			}
		}
	}
	return result;
}

int solution(vector<vector<int>> baseball) {
	return MakeANumber(baseball).size();
}