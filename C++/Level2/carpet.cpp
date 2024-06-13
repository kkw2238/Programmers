/*
	https://programmers.co.kr/learn/courses/30/lessons/42842
*/

#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    const int SQRT = sqrt(yellow) + 1;
    int width = 3;
    int height = 3;

    for (int height = 3; height <= SQRT + 2; ++height)
    {
        if (yellow % (height - 2) != 0)
        {
            continue;
        }
        width = yellow / (height - 2) + 2;

        if ((height + width - 2) * 2 == brown)
        {
            return { width, height };
        }
    }
}

// 예전 코드
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//const bool IsFactor(int num, int factor) {
//	return num % factor == 0;
//}
//
//const int GetBrownCount(int width, int height) {
//	return width * 2 + (height - 2) * 2;
//}
//
//vector<int> FindWidthHeight(int brown, int red) {
//	int totalBlock = brown + red;
//	int sqrtTotalBlock = static_cast<int>(sqrt(totalBlock)) + 1;
//	vector<int> result(2);
//
//	for (int width = 1; width <= sqrtTotalBlock; ++width) {
//		if (!IsFactor(totalBlock, width)) continue;
//
//		int height = totalBlock / width;
//		if (GetBrownCount(width, height) == brown) {
//			result[0] = width > height ? width : height;
//			result[1] = totalBlock / result[0];
//
//			return result;
//		}
//	}
//
//	return result;
//}
//
//vector<int> solution(int brown, int red) {
//	return FindWidthHeight(brown, red);
//}
