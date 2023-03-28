/*
    https://school.programmers.co.kr/learn/courses/30/lessons/169198
*/

#include <string>
#include <vector>

using namespace std;

int calculateLength(int x, int y, int reflectX, int reflectY)
{
    int xOffset = reflectX - x;
    int yOffset = reflectY - y;

    return xOffset * xOffset + yOffset * yOffset;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    for (int i = 0; i < balls.size(); ++i)
    {
        int length = 4000000;

        length = min(length, calculateLength(startX, startY, -balls[i][0], balls[i][1]));
        length = min(length, calculateLength(startX, startY, balls[i][0] + 2 * (m - balls[i][0]), balls[i][1]));
        length = min(length, calculateLength(startX, startY, balls[i][0], balls[i][1] + 2 * (n - balls[i][1])));
        length = min(length, calculateLength(startX, startY, balls[i][0], -balls[i][1]));

        answer.push_back(length);
    }

    return answer;
}

int main()
{
    solution(10, 10, 3, 7, { {2, 7} });
}