/*
	https://school.programmers.co.kr/learn/courses/30/lessons/138476
*/

#include <vector> 
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    sort(tangerine.begin(), tangerine.end());
    vector<int> tangSizeCount(tangerine.back() + 1, 0);

    for (int i : tangerine)
    {
        ++tangSizeCount[i];

        if (tangSizeCount[i] >= k)
        {
            return 1;
        }
    }

    sort(tangSizeCount.begin(), tangSizeCount.end(), ::greater());

    for (int i = 0; i < tangSizeCount.size(); ++i)
    {
        if (k <= 0)
        {
            break;
        }
        k -= tangSizeCount[i];
        ++answer;
    }

    return answer;
}