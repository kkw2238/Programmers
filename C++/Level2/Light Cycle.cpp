/*
    https://programmers.co.kr/learn/courses/30/lessons/86052
*/

#include <string>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

enum { UP, RIGHT, DOWN, LEFT };
using Board = vector<vector<vector<bool>>>;

array<int, 4> LightDirection{ UP, RIGHT, DOWN, LEFT };
Board board;
const int DIRECTION = 4;
int board_Width, board_Height;

// Reflection : �ش� ��ġ�� ������ ���� ������ ������ ��ȯ���ִ� �Լ�
const int Refelction(const int inputDirection, const char reflectDirection)
{
    switch (reflectDirection)
    {       
    case 'S':
        // S : ���� ���� �״�� �����Ѵ�.
        return inputDirection;

        /*
            L, R ���� ������� �� ���⿡ ���� �ٸ� ���� ������ ������ �ִµ� 
            Input�� Output�� ���� ����� �Ʒ��� ����.

            UP - L :      �� L < reflectDirection
                            �� < inputDirection
                => Return L

            DOWN - L :      �� < inputDirection
                            L �� < reflectDirection
                => Return R

                ...

                LightDirection �迭 �������� inputDirection�� -1 ��ġ�� �ݻ籤�� ������ ���Ⱚ�� ����ִ�.
        */
    case 'L':
        return (inputDirection + DIRECTION - 1) % DIRECTION;
    case 'R':
        return (inputDirection + 1) % DIRECTION;
    }
}

// Move : ���� ���⿡ ���� ������ ����� ��ȯ���ִ� �Լ�
const void Move(int& xPos, int& yPos, const int direction)
{
    /*
        y = 0�� ��ġ���� ���� ��ų� y = height�� ��ġ���� ���� �Ʒ��� �� ��� 
        �ݴ������� ��ȯ�ϰ� ������ �ϱ⿡
        % board_Height or % board_Width ������ ���� ��ȯ
    */
    switch (direction)
    {
    case UP :
        yPos = (yPos + board_Height - 1) % board_Height;
        break;
    case DOWN:
        yPos = (yPos + 1) % board_Height;
        break;
    case LEFT :
        xPos = (xPos + board_Width - 1) % board_Width;
        break;
    case RIGHT :
        xPos = (xPos + 1) % board_Width;
        break;
    }
}

// Light : ���� ��ġ���� direction �������� ���� �� ��� �� �� �̵��ؾ� ���� ��ȯ�Ǵ��� �˷��ִ� �Լ�
const int Lighting(vector<string> grid, int xPos, int yPos, int direction)
{
    int moveDist = 0;

    // �̹� ������ ������ Ȯ��
    while (!board[yPos][xPos][direction])
    {
        // ������ ���� üũ ���ش�.
        board[yPos][xPos][direction] = true;

        // �̵�
        Move(xPos, yPos, direction);
        // �ݻ�
        direction = Refelction(direction, grid[yPos][xPos]);

        ++moveDist;
    }

    return moveDist;
}

vector<int> solution(vector<string> grid) {
    board_Width = grid[0].length();
    board_Height = grid.size();

    board = Board(board_Height, vector<vector<bool>>(board_Width, vector<bool>(DIRECTION, 0)));
    vector<int> answer;

    for (int y = 0; y < board_Height; ++y)
    {
        for (int x = 0; x < board_Width; ++x)
        {
            for (int dir = 0; dir < DIRECTION; ++dir)
            {
                if (board[y][x][dir])
                    continue;

                int dist = Lighting(grid, x, y, dir);
                
                if (dist > 0)
                {
                    answer.push_back(dist);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}