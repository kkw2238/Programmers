/*
	https://programmers.co.kr/learn/courses/30/lessons/43238
*/
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long l = 1, r = static_cast<long long>(1000000000) * static_cast<long long>(1000000000);
    long long sum, mid;
    while (l < r) {
        sum = 0;
        mid = (l + r) / 2;
        for (int t : times) {
            sum += mid / t;
        }

        if (sum < n) l = mid + 1;
        else r = mid - 1;
    }

    return mid;
}


int main() {
    int n = 6;
    vector<int> times = { 7, 10 };
    cout << solution(n, times);
}