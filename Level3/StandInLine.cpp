/*
	https://programmers.co.kr/learn/courses/30/lessons/12936
*/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const long long Factorial(const int n)
{
    long long result = 1;

    for (int i = n; i > 0; --i)
    {
        result = result * i;
    }

    return result;
}

vector<int> solution(int n, long long k) {
    vector<int> answer(n, 1);
    iota(answer.begin(), answer.end(), 1);
    
    do {
        --k;
    } while (k > 0 && next_permutation(answer.begin(), answer.end()));

    return answer;
}