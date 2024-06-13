/*
	https://school.programmers.co.kr/learn/courses/30/lessons/147354
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    sort(data.begin(), data.end(), [&col](vector<int>& a, vector<int>& b) {
        if (a[col - 1] == b[col - 1])
        {
            return a[0] < b[0];
        }
        return a[col - 1] > b[col - 1];
    });

    for (int i = row_begin; i <= row_end; ++i)
    {
        int sumMod = 0;
        for (int d : data[i - 1])
        {
            sumMod += (d % i);
        }
        answer = answer ^ sumMod;
    }

    return answer;
}