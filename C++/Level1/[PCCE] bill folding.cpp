/*
    https://school.programmers.co.kr/learn/courses/30/lessons/340199
*/

#include <string>
#include <vector>

using namespace std;

bool isCanInput(const vector<int>& wallet, const vector<int>& bill) {
    return wallet[0] >= bill[0] && wallet[1] >= bill[1];
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    if (wallet[0] < wallet[1]) {
        swap(wallet[0], wallet[1]);
    }

    while (true) {
        if (bill[0] < bill[1]) {
            swap(bill[0], bill[1]);
        }

        if (isCanInput(wallet, bill)) {
            break;
        }

        bill[0] /= 2;
        answer++;
    }

    return answer;
}