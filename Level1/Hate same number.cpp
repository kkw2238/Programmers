/*
    https://programmers.co.kr/learn/courses/30/lessons/12906
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer(1, arr[0]);

    for (const int n : arr)
    {
        if (n != answer.back())
        {
            answer.emplace_back(n);
        }
    }

    return answer;
}