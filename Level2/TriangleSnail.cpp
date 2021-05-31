/*
    https://programmers.co.kr/learn/courses/30/lessons/68645
*/

#include <string>
#include <vector>

using namespace std;

int nowNum = 0;

void LeftSide(vector<vector<int>>& pyramid, int offset)
{
    for (int i = offset; i < pyramid.size(); ++i)
    {
        if (pyramid[i][offset] == 0) 
        {
            pyramid[i][offset] = ++nowNum;
        }
    }
}

void RightSide(vector<vector<int>>& pyramid, int offset)
{
    for (int i = pyramid.size() - 1 - offset; i >= offset; --i)
    {
        if (pyramid[i][i - offset] == 0)
        {
            pyramid[i][i - offset] = ++nowNum;
        }
    }
}

void BottomSide(vector<vector<int>>& pyramid, int offset)
{
    int bottomOffset = pyramid.size() - (offset + 1);

    for (int i = offset; i < pyramid[bottomOffset].size() - offset; ++i)
    {
        if (pyramid[bottomOffset][i] == 0)
        {
            pyramid[bottomOffset][i] = ++nowNum;
        }
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> pyramid(n, vector<int>());

    for (int i = 0; i < n; ++i)
    {
        pyramid[i] = vector<int>(i + 1);
        pyramid[i][0] = ++nowNum;
    }

    for (int i = 1; i <= n; ++i)
    {
        switch (i % 3)
        {
        case 0:
            LeftSide(pyramid, i / 3);
            break;
        case 1:
            BottomSide(pyramid, i / 3);
            break;
        case 2:
            RightSide(pyramid, i / 3);
            break;
        }
    }

    for (vector<int>& vi : pyramid)
    {
        answer.insert(answer.end(), vi.begin(), vi.end());
    }

    return answer;
}

/* 예전 코드
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

*/