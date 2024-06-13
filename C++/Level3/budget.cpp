/*
	https://programmers.co.kr/learn/courses/30/lessons/43237
*/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int Find_Middle_Index(const vector<int>& budgets, int L, int R, unsigned int M) {
    if (L == R) return L;
    int mid = (L + R) / 2;
    unsigned int sum_of_budgets = accumulate(budgets.begin(), budgets.begin() + mid, 0) + budgets[mid] * (budgets.size() - mid);
    if (sum_of_budgets > M) {
        return Find_Middle_Index(budgets, L, (L + R) / 2, M);
    }
    else {
        if (mid < budgets.size() - 1) {
            if (sum_of_budgets + budgets[mid + 1] - budgets[mid] > M) {
                return R;
            }
            else {
                return Find_Middle_Index(budgets, (L + R) / 2, R, M);
            }
        }
    }

    return R;
}

int solution(vector<int> budgets, int M) {
    int answer = 0;

    sort(budgets.begin(), budgets.end());
    
    if (static_cast<unsigned int>(accumulate(budgets.begin(), budgets.end(), 0)) < static_cast<unsigned int>(M)) return budgets.back();

    int middle_Index = Find_Middle_Index(budgets, 0, budgets.size(), static_cast<unsigned int>(M));
    unsigned int sum_of_budgets = accumulate(budgets.begin(), budgets.begin() + middle_Index, 0);

    return (static_cast<unsigned int>(M) - sum_of_budgets) / (budgets.size() - middle_Index);
}