#include <string>
#include <vector>
#include <algorithm>
#include "Util.h"

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0);
    rocks.push_back(distance);

    sort(rocks.begin(), rocks.end());
    vector<pair<int, int>> distances(rocks.size() - 1);
    for (int i = 1; i < rocks.size(); ++i) {
        distances[i - 1] = pair<int, int>(i, rocks[i] - rocks[i - 1]);
    }

    sort(distances.begin(), distances.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    return answer;
}

#include <iostream>

int main() {
    int distance = 25;
    vector<int> rocks = { 2, 14, 11, 21, 17 };
    int n = 2;
    
    cout << solution(distance, rocks, n);
}