/*
    https://programmers.co.kr/learn/courses/30/lessons/42885
*/
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

#include <iostream>
void main() {
    vector<int> people = { 70, 50, 80, 50 };
    int limit = 100;

    cout << solution(people, limit);
}
