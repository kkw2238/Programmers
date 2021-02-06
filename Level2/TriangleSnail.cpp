#include <string>
#include <vector>

using namespace std;

int Maximum = 0;

void LeftSide(vector<vector<int>>& container, int offset, int& nowNum) {
    for (int i = offset; i < container.size() - offset; ++i) {
        if (nowNum > Maximum) return;

        if (container[i][offset] == 0)
            container[i][offset] = nowNum++;
    }
}

void RightSide(vector<vector<int>>& container, int offset, int& nowNum) {
    for (int i = container.size() - ( 1 + offset); i > offset ; --i) {
        if (nowNum > Maximum) return;

        if (container[i][container[i].size() - (1 + offset)] == 0)
            container[i][container[i].size() - (1 + offset)] = nowNum++;
    }
}

void BottomSide(vector<vector<int>>& container, int offset, int& nowNum) {
    for (int& bottomNum : container[container.size() - (1 + offset)]) {
        if (nowNum > Maximum) return;

        if (bottomNum == 0)
            bottomNum = nowNum++;
    }
}

vector<int> solution(int n) {
    Maximum = n * (1 + n) / 2;
    vector<vector<int>> container(n);
    vector<int> answer;

    int nowNum = 1;

    for (int i = 0; i < n; ++i) 
        container[i] = vector<int>(i + 1);
    

    for (int i = 0; i < n / 3 + 1; ++i) {
        LeftSide(container, i, nowNum);
        BottomSide(container, i, nowNum);
        RightSide(container, i, nowNum);
    }

    for (int i = 0; i < n; ++i)
        answer.insert(answer.end(), container[i].begin(), container[i].end());

    return answer;
}

void main() {
    solution(3);
}


/*
    1. 1 ~ n개의 배열에 1 ~ n개의 크기의 배열 삽입 
    2. vector<int> (sum(1 ~ n))개의 배열 생성
*/