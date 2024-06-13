/*
	https://school.programmers.co.kr/learn/courses/30/lessons/154538
*/

#include <vector>

using namespace std;

int solution(int x, int y, int n) {
    const int MAXIMUM = 1000000;
    vector<int> least(y + 1, MAXIMUM);
    least[x] = 0;

    for (int i = x; i < y; ++i)
    {
        if (least[i] == MAXIMUM)
        {
            continue;
        }

        if ((i * 3) <= y && (least[i] + 1) < least[i * 3])
        {
            least[i * 3] = least[i] + 1;
        }
        if ((i * 2) <= y && (least[i] + 1) < least[i * 2])
        {
            least[i * 2] = least[i] + 1;
        }
        if ((i + n) <= y && (least[i] + 1) < least[i + n])
        {
            least[i + n] = least[i] + 1;
        }
    }

    if (least[y] == MAXIMUM)
    {
        return -1;
    }

    return least[y];
}