/*
	https://school.programmers.co.kr/learn/courses/30/lessons/178870?language=cpp
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer{ 0, 1000000 };
    int memIndex = 0, sum = 0;

    for (int i = 0; i < sequence.size(); ++i)
    {
        sum += sequence[i];

        if (sum >= k)
        {
            while (sum > k)
            {
                sum -= sequence[memIndex++];
            }

            if (sum == k && (answer[1] - answer[0]) > (i - memIndex))
            {
                answer = { memIndex, i };
            }
        }
    }

    return answer;
}