/*
	https://school.programmers.co.kr/learn/courses/30/lessons/258712
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    const int friendCount = friends.size();
    vector<vector<int>> giveCount(friendCount, vector<int>(friendCount, 0));
    vector<int> giftScore(friendCount, 0);
    vector<int> nextMonthCount(friendCount, 0);
    map<string, int> indices;

    for (int i = 0; i < friendCount; ++i)
    {
        indices[friends[i]] = i;
    }

    for (string& gift : gifts)
    {
        int mid = gift.find(' ');

        int from = indices[gift.substr(0, mid)];
        int to = indices[gift.substr(mid + 1)];

        ++giveCount[from][to];
        --giftScore[to];
        ++giftScore[from];
    }

    for (int i = 0; i < friendCount; ++i)
    {
        for (int j = i + 1; j < friendCount; ++j)
        {
            if (giveCount[i][j] == giveCount[j][i])
            {
                if (giftScore[i] > giftScore[j])
                {
                    ++nextMonthCount[i];
                }
                else if (giftScore[i] < giftScore[j])
                {
                    ++nextMonthCount[j];
                }
            }
            else if (giveCount[i][j] > giveCount[j][i])
            {
                ++nextMonthCount[i];
            }
            else
            {
                ++nextMonthCount[j];
            }
        }
    }
       
    for (int i = 0; i < friendCount; ++i)
    {
        answer = max(nextMonthCount[i], answer);
    }

    return answer;
}