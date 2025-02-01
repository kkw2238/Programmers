/*
* https://school.programmers.co.kr/learn/courses/30/lessons/340198
*/

#include <string>
#include <vector>

using namespace std;

bool installMats(int matSize, vector<vector<string>>& park, int x, int y) {
    if ((x + matSize - 1) >= park[0].size() || (y + matSize - 1) >= park.size()) {
        return false;
    }

    for (int i = y; i < park.size(); ++i) {
        for (int j = x; j < park[i].size(); ++j) {
            if (park[i][j][0] != '-') {
                return false;
            }
        }
    }

    return true;
}

int tryInstallMats(vector<int>& mats, vector<vector<string>>& park, int x, int y) {
    int result = -1;
    for (int ms : mats) {
        if (installMats(ms, park, x, y)) {
            result = ms;
        }
    }

    return result;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;

    for (int i = 0; i < park.size(); ++i) {
        for (int j = 0; j < park[i].size(); ++j) {
            if (park[i][j][0] == '-') {
                answer = max(answer, tryInstallMats(mats, park, j, i));
            }
        }
    }

    return answer;
}