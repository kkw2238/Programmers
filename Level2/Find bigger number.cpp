/*
	https://school.programmers.co.kr/learn/courses/30/lessons/154539
*/

#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pair<int, int>> frontNumbers;

    for (int i = 0; i < numbers.size(); ++i)
    {
        while (!frontNumbers.empty())
        {
            pair<int, int> frontNumber = frontNumbers.top();

            if (frontNumber.second < numbers[i])
            {
                frontNumbers.pop();
                answer[frontNumber.first] = numbers[i];
            }
            else
            {
                break;
            }
        }

        frontNumbers.push(pair(i, numbers[i]));
    }

    return answer;
}