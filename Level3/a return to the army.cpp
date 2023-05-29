/*
	https://school.programmers.co.kr/learn/courses/30/lessons/132266
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> range;

void pathFind(int b, int s, int d)
{
    if (range[s] != nullptr)
    {
        return ;
    }
    targets[s] = target;
    target->push_back(s);

    for (int i = 1; i < range.size(); ++i)
    {
        if (i != b && range[s][i] == 1)
        {
            pathFind(s, i, d)
        }
    }

}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    range = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

    for (vector<int>& road : roads)
    {
        range[road[0]][road[1]] = 1;
        range[road[1]][road[0]] = 1;
    }



    return answer;
}