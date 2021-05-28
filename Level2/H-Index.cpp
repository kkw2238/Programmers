/*
    https://programmers.co.kr/learn/courses/30/lessons/42747
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int maximum = citations.size();
    
    sort(citations.begin(), citations.end(), greater());

    for (int index = 0; index < maximum; ++index)
    {
        int h = citations[index];
        
        if (h <= index)
        {
            return index + 1;
        }
    }

    return maximum;
}