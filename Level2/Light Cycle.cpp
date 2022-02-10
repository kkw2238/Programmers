/*
    https://programmers.co.kr/learn/courses/30/lessons/86052
*/

#include <string>
#include <array>
#include <vector>

using namespace std;

/*
�� ĭ���� S, L, �Ǵ� R�� ���� �ִ� ���ڰ� �ֽ��ϴ�. ����� �� ���ڿ��� ���� ����� �մϴ�. �� ������ �� ĭ���� ������ ���� Ư���� ������ �ֽ��ϴ�.

���� "S"�� ���� ĭ�� ������ ���, �����մϴ�.
���� "L"�� ���� ĭ�� ������ ���, ��ȸ���� �մϴ�.
���� "R"�� ���� ĭ�� ������ ���, ��ȸ���� �մϴ�.
���� ������ ���� �Ѿ ���, �ݴ��� ������ �ٽ� ���ƿɴϴ�. ���� ���, ���� 1�࿡�� ���� �پ��� �������� �̵��� ���, ���� ���� �ݴ��� �� ������ �ٽ� ���ƿɴϴ�.
����� �� ���� ������ ���� �̵��� �� �ִ� ��� ����Ŭ�� �� �� �ְ�, �� ����Ŭ�� ���̰� ������ �˰� �ͽ��ϴ�. ��� ����Ŭ�̶�, ���� �̵��ϴ� ��ȯ ��θ� �ǹ��մϴ�.

���� ���, ���� �׸��� ���� ["SL","LR"]���� 1�� 1������ 2�� 1�� �������� ���� �� ���, �ش� ���� �̵��ϴ� ��� ����Ŭ�� ǥ���� ���Դϴ�.
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