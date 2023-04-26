/*
	https://school.programmers.co.kr/learn/courses/30/lessons/138477
*/

#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    multiset<int> ranking;
    vector<int> answer;

    for (int s : score)
    {
        ranking.insert(s);

        if (ranking.size() > k)
        {
            ranking.erase(ranking.begin());
        }

        answer.push_back(*(ranking.begin()));
    }

    return answer;
}