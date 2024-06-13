/*
	https://programmers.co.kr/learn/courses/30/lessons/42885

*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int duoCount = 0;
    int singleCount = 0;
    
    sort(people.begin(), people.end());
    
    for (int i = people.size() - 1; i >= duoCount; --i)
    {
        if (people[i] + people[duoCount] <= limit)
        {
            ++duoCount;
        }
        else
        {
            ++singleCount;
        }
    }

    return duoCount + singleCount;
}

/* 예전 코드
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int result = 0, offset = 0;
    sort(people.begin(), people.end());

    for (int i = people.size() - 1; i > offset; --i) {
        if (people[offset] + people[i] <= limit) {
            ++result;
            ++offset;
        }
    }

    return result + people.size() - offset * 2;
}
*/