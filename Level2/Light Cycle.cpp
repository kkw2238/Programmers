/*
    https://programmers.co.kr/learn/courses/30/lessons/86052
*/

#include <string>
#include <array>
#include <vector>

using namespace std;

/*
각 칸마다 S, L, 또는 R가 써져 있는 격자가 있습니다. 당신은 이 격자에서 빛을 쏘고자 합니다. 이 격자의 각 칸에는 다음과 같은 특이한 성질이 있습니다.

빛이 "S"가 써진 칸에 도달한 경우, 직진합니다.
빛이 "L"이 써진 칸에 도달한 경우, 좌회전을 합니다.
빛이 "R"이 써진 칸에 도달한 경우, 우회전을 합니다.
빛이 격자의 끝을 넘어갈 경우, 반대쪽 끝으로 다시 돌아옵니다. 예를 들어, 빛이 1행에서 행이 줄어드는 방향으로 이동할 경우, 같은 열의 반대쪽 끝 행으로 다시 돌아옵니다.
당신은 이 격자 내에서 빛이 이동할 수 있는 경로 사이클이 몇 개 있고, 각 사이클의 길이가 얼마인지 알고 싶습니다. 경로 사이클이란, 빛이 이동하는 순환 경로를 의미합니다.

예를 들어, 다음 그림은 격자 ["SL","LR"]에서 1행 1열에서 2행 1열 방향으로 빛을 쏠 경우, 해당 빛이 이동하는 경로 사이클을 표현한 것입니다.
*/

enum { UP, RIGHT, DOWN, LEFT };
using Board = vector<vector<vector<int>>>;

array<int, 4> LightDirection{ UP, RIGHT, DOWN, LEFT };
Board board;
const int DIRECTION = 4;

const int Refelction(const int inputDirection, const char reflectDirection)
{
    switch (reflectDirection)
    {
    case 'S':
        return inputDirection;
    case 'L':
        return (inputDirection + DIRECTION - 1) % DIRECTION;
    case 'R':
        return (inputDirection + 1) % DIRECTION;
    }
}

const int Move(const int xPos, const int yPos, const int direction)
{
    switch (direction)
    {
    default:
        break;
    }
}

const int Lighting(vector<string> grid, int xPos, int yPos, int direction)
{
    if (board[yPos][xPos][direction] > 0)
        return 0;

    ++board[yPos][xPos][direction];

    
}

vector<int> solution(vector<string> grid) {
    const int LENGTH = grid[0].length();
    board = Board(DIRECTION, vector<vector<int>>(LENGTH, vector<int>(LENGTH, 0)));
    vector<int> answer;

    return answer;
}