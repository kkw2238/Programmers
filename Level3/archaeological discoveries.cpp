/*
	https://school.programmers.co.kr/learn/courses/30/lessons/131702?language=cpp
*/

#include <vector>

using namespace std;

int offSetX[5]{ -1, 1, 0, 0, 0 };
int offSetY[5]{ 0, 0, -1, 1, 0 };

int rotCount = 1000;
int width, height;

void rot(vector<vector<int>>& clockHands, int x, int y, int rotCount)
{
    if (rotCount == 0)
    {
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        int nextX = x + offSetX[i];
        int nextY = y + offSetY[i];

        if (nextX >= 0 && nextX < width)
        {
            if (nextY >= 0 && nextY < height)
            {
                clockHands[nextY][nextX] = (clockHands[nextY][nextX] + 4 + rotCount) % 4;
            }
        }
    }
}

bool isCorrect(vector<vector<int>>& clockHands, int index, int xOffset)
{
    int y = index / width - 1;

    if (y >= 0)
    {
        for (int x = 0; x < xOffset + 1; ++x)
        {
            if (clockHands[y][x] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

void DFS(vector<vector<int>>& clockHands, int index, int rc)
{
    if (index >= clockHands.size() * width)
    {
        if (isCorrect(clockHands, index, width - 1))
        {
            rotCount = min(rotCount, rc);
        }

        return;
    }
    else if (rc > rotCount)
    {
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        rot(clockHands, index % width, index / width, i);
        if (isCorrect(clockHands, index, index % width))
        {
            DFS(clockHands, index + 1, rc + i);
        }
        rot(clockHands, index % width, index / width, -i);
    }
}

int solution(vector<vector<int>> clockHands) {
    width = clockHands[0].size();
    height = clockHands.size();
    DFS(clockHands, 0, 0);

    return rotCount;
}