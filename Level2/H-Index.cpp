/*
    https://programmers.co.kr/learn/courses/30/lessons/42747
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());

    for (int i = citations.size() - 1; i >= 0; --i)
    {
        int h = citations[i - 1];
        if (h <= citations.size() - i)
        {
            return i;
        }
    }

    return answer;
}