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

// Reflection : 해당 위치에 도달한 빛이 진행할 방향을 반환해주는 함수
const int Refelction(const int inputDirection, const char reflectDirection)
{
    switch (reflectDirection)
    {       
    case 'S':
        // S : 들어온 방향 그대로 진행한다.
        return inputDirection;

        /*
            L, R 이전 블럭에서 쏜 방향에 따라 다른 진행 방향을 리턴해 주는데 
            Input과 Output의 리턴 관계는 아래와 같다.

            UP - L :      ← L < reflectDirection
                            ↑ < inputDirection
                => Return L

            DOWN - L :      ↓ < inputDirection
                            L → < reflectDirection
                => Return R

                ...

                LightDirection 배열 기준으로 inputDirection의 -1 위치에 반사광이 진행할 방향값이 들어있다.
        */
    case 'L':
        return (inputDirection + DIRECTION - 1) % DIRECTION;
    case 'R':
        return (inputDirection + 1) % DIRECTION;
    }
}

// Move : 빛의 방향에 따라 진행한 결과를 반환해주는 함수
const void Move(int& xPos, int& yPos, const int direction)
{
    /*
        y = 0인 위치에서 위로 쏘거나 y = height인 위치에서 빛을 아래로 쏠 경우 
        반대쪽으로 순환하게 만들어야 하기에
        % board_Height or % board_Width 연산을 통해 순환
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

// Light : 시작 위치에서 direction 방향으로 빛을 쏠 경우 몇 번 이동해야 빛이 순환되는지 알려주는 함수
const int Lighting(vector<string> grid, int xPos, int yPos, int direction)
{
    int moveDist = 0;

    // 이미 지나간 곳인지 확인
    while (!board[yPos][xPos][direction])
    {
        // 지나간 곳을 체크 해준다.
        board[yPos][xPos][direction] = true;

        // 이동
        Move(xPos, yPos, direction);
        // 반사
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