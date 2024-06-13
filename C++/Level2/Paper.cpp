#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer = { 0 };

    for (int i = 1; i < n; ++i) {
        answer.insert(answer.end(), answer.begin(), answer.end());
        answer.insert(answer.begin() + answer.size() / 2, 0);

        int changePos = answer.size() * 3 / 4;
        answer[changePos] = answer[changePos] == 0 ? 1 : 0;
    }

    return answer;
}

#include "Util.h"

int main() {
    int n = 1;

    for(int i = 1; i < 5; ++i) 
        cout << solution(i);
}
// 001001100011011