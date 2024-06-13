/*
    https://programmers.co.kr/learn/courses/30/lessons/86491
*/

#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int longSide = 0;
    int shortSide = 0;

    for (vector<int>& size : sizes)
    {
        if (size[0] < size[1])
        {
            swap(size[0], size[1]);
        }

        longSide = longSide < size[0] ? size[0] : longSide;
        shortSide = shortSide < size[1] ? size[1] : shortSide;
    }

    return longSide * shortSide;
}