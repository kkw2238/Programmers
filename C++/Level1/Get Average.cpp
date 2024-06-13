/*
    https://programmers.co.kr/learn/courses/30/lessons/12944
*/
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    double total = accumulate(arr.begin(), arr.end(), 0);
    
    return total / arr.size();
}