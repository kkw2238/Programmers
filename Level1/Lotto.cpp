/*
    https://programmers.co.kr/learn/courses/30/lessons/77484
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    const vector<int> award{ 6, 6, 5, 4, 3, 2, 1 };
    int best_score = 0;
    int worst_score = 0;

    for (int i = 0; i < lottos.size(); ++i)
    {
        if (lottos[i] == 0)
        {
            ++best_score;
            continue;
        }

        for (int j = 0; j < win_nums.size(); ++j)
        {
            if (win_nums[j] == lottos[i])
            {
                ++best_score;
                ++worst_score;
                break;
            } 
        }
    }

    return vector<int>{award[best_score], award[worst_score]};
}