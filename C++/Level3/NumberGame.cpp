/*
    https://programmers.co.kr/learn/courses/30/lessons/12987
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, offset = 0;

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    if (*A.begin() >= *B.begin()) return 0;
    
    for (int i = 0; i < A.size() ; ++i) {
        if (A[i] < B[offset]) {
            ++offset;
            ++answer;
        }
    }

    return answer;
}

#include <iostream>
int main() {
    vector<int> A = { 7,5,3,1 };
    vector<int> B = { 8,6,2,2 };

    cout << solution(A, B);
}