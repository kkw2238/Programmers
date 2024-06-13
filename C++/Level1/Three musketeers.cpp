/*
    https://school.programmers.co.kr/learn/courses/30/lessons/131705
*/

#include <string>
#include <vector>

using namespace std;

int getPerpumation(const vector<int>& numbers, int sum, int count, int index)
{
    int result = 0;

    if (count == 3)
    {
        return (int)(sum == 0);
    }
    
    for (int i = index; i < numbers.size(); ++i)
    {
        result += getPerpumation(numbers, sum + numbers[i], count + 1, i + 1);
    }
    
    return result;
}

int solution(vector<int> number) {
    return getPerpumation(number, 0, 0, 0);
}