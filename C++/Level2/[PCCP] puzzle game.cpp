/*
* https://school.programmers.co.kr/learn/courses/30/lessons/340212
*/

#include <string>
#include <vector>

using namespace std;

long getElapsedTime(vector<int>& diffs, vector<int>& times, int level) {
    long result = 0;
    int i = 0;
    
    if (diffs[0] > level) {
        result += times[0];
        ++i;
    }

    for (; i < diffs.size(); ++i) {
        if(diffs[i] > level) {
            result += (times[i] + times[i - 1]) * (diffs[i] - level);
        }
        result += times[i];
    }

    return result;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int l = 0, r = 300000;
    int mid = (l + r) / 2;
    int answer = 0;

    while (l < r) {
        mid = (l + r) / 2;

        long time = getElapsedTime(diffs, times, mid);

        if (time <= (long)limit) {
            r = mid - 1;
            answer = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return max(1, answer);
}