#include <string>
#include <vector>

using namespace std;

bool IsBall(vector<int>& number, vector<int>& ask, int ballCount) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            if (number[i] == ask[j])
                --ballCount;
        }
    }

    return ballCount == 0;
}

bool IsStrike(vector<int>& number, vector<int>& ask, int strikeCount) {
    for (int i = 0; i < 3; ++i) {
        if (number[i] == ask[i])
            --strikeCount;
    }

    return strikeCount == 0;
}

vector<int> DistributeNumber(int n) {
    vector<int> result(3);

    result[0] = n / 100;
    n -= 100 * result[0];

    result[1] = n / 10;
    n -= 10 * result[1];

    result[2] = n;
    return result;
}

bool IsAnswer(const int number, const vector<vector<int>>& baseball) {
    const int NUMBER_INDEX = 0, STRIKE_INDEX = 1, BALL_INDEX = 2;
    vector<int> distNumber = DistributeNumber(number);
    vector<int> distaskNumber;

    for (int i = 0; i < baseball.size(); ++i) {
        distaskNumber = DistributeNumber(baseball[i][NUMBER_INDEX]);
        if (!IsStrike(distNumber, distaskNumber, baseball[i][STRIKE_INDEX])) {
            return false;
        }

        if (!IsBall(distNumber, distaskNumber, baseball[i][BALL_INDEX])) {
            return false;
        }
    }

    return true;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    for (int i = 1; i < 10; ++i) {
        for (int m = 1; m < 10; ++m) {
            if (i == m) continue;
            for (int n = 1; n < 10; ++n) {
                if (n == i || n == m) continue;
                answer += IsAnswer(i * 100 + m * 10 + n, baseball);
            }
        }
    }

    return answer;
}

#include <iostream>
int main() {
    vector<vector<int>> baseball = { {123, 1, 1} ,{356, 1, 0},{327, 2, 0},{489, 0, 1} };

    cout << solution(baseball);
}