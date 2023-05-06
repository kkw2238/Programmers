/*
    https://school.programmers.co.kr/learn/courses/30/lessons/131130
*/

#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0, groupCount = 1;
    vector<int> groupIndex(cards.size(), 0);

    priority_queue<int> score;

    for (int i = 0; i < cards.size(); ++i)
    {
        if (groupIndex[i] != 0)
        {
            continue;
        }

        int nextIndex = cards[i] - 1;
        int counts = 1;
        while (nextIndex != i)
        {
            groupIndex[nextIndex] = groupCount;
            nextIndex = cards[nextIndex] - 1;
            ++counts;
        }

        groupIndex[nextIndex] = groupCount++;
        score.push(counts);
    }

    answer = score.top();
    score.pop();

    if (!score.empty())
    {
        answer *= score.top();
    }

    return answer * !(score.empty());
}