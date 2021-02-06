/*
	https://programmers.co.kr/learn/courses/30/lessons/42842
*/
#include <vector>
#include <cmath>

using namespace std;

const bool IsFactor(int num, int factor) {
	return num % factor == 0;
}

const int GetBrownCount(int width, int height) {
	return width * 2 + (height - 2) * 2;
}

vector<int> FindWidthHeight(int brown, int red) {
	int totalBlock = brown + red;
	int sqrtTotalBlock = static_cast<int>(sqrt(totalBlock)) + 1;
	vector<int> result(2);

	for (int width = 1; width <= sqrtTotalBlock; ++width) {
		if (!IsFactor(totalBlock, width)) continue;

		int height = totalBlock / width;
		if (GetBrownCount(width, height) == brown) {
			result[0] = width > height ? width : height;
			result[1] = totalBlock / result[0];

			return result;
		}
	}

	return result;
}

vector<int> solution(int brown, int red) {
	return FindWidthHeight(brown, red);
}
