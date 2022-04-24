/*
	https://programmers.co.kr/learn/courses/30/lessons/87694?language=cpp
*/

#include <vector>

#include <iostream>

using namespace std;

enum MARK_TYPE { NONE, OUTLINE, INNER, VISITED, GOAL };
enum RECTANGLE_POSITION_INDEX { START_X_INDEX = 0, START_Y_INDEX = 1, END_X_INDEX = 2, END_Y_INDEX = 3 };

const int MAP_SCALE = 2;
const int BOARD_LENGTH = 52 * MAP_SCALE;

vector<vector<int>> board = vector<vector<int>>(BOARD_LENGTH, vector<int>(BOARD_LENGTH, NONE));

const bool IsRectangleOutLine(int xOffset, int yOffset, int width, int height)
{
    return xOffset == 0 || xOffset == width || yOffset == 0 || yOffset == height;
}

const bool IsMoveAbleOutline(const int xPosition, const int yPosition)
{
    return board[yPosition][xPosition] == OUTLINE || board[yPosition][xPosition] == GOAL;
}

void CreateRectangle(const vector<int>& rectangle)
{
    int width = (rectangle[END_X_INDEX] - rectangle[START_X_INDEX]) * MAP_SCALE;
    int height = (rectangle[END_Y_INDEX] - rectangle[START_Y_INDEX]) * MAP_SCALE;

    for (int xOffset = 0; xOffset <= width; ++xOffset)
    {
        for (int yOffset = 0; yOffset <= height; ++yOffset)
        {
            int positionX = rectangle[START_X_INDEX] * MAP_SCALE + xOffset;
            int positionY = rectangle[START_Y_INDEX] * MAP_SCALE + yOffset;

            if (IsRectangleOutLine(xOffset, yOffset, width, height) && board[positionY][positionX] != INNER)
            {
                board[positionY][positionX] = OUTLINE;
            }
            else
            {
                board[positionY][positionX] = INNER;
            }
        }
    }
}

pair<int, int> FindMoveAblePosition(int characterXPosition, int characterYPosition)
{
    const int XOFFSET[4] = { 0, 0, 1, -1 };
    const int YOFFSET[4] = { 1, -1, 0, 0 };

    for (int i = 0; i < 4; ++i)
    {
        if (IsMoveAbleOutline(characterXPosition + XOFFSET[i], characterYPosition + YOFFSET[i]))
        {
            return pair<int, int>(characterXPosition + XOFFSET[i], characterYPosition + YOFFSET[i]);
        }
    }

    return pair<int, int>(-1, -1);
}

int FindItem(int characterXPosition, int characterYPosition)
{
    pair<int, int> nowPosition = pair<int, int>(characterXPosition, characterYPosition);
    int moveCount = 0;

    while (true)
    {
        nowPosition = FindMoveAblePosition(nowPosition.first, nowPosition.second);
        ++moveCount;

        if (board[nowPosition.second][nowPosition.first] == GOAL)
        {
            return moveCount / MAP_SCALE;
        }
        
        board[nowPosition.second][nowPosition.first] = VISITED;
    }

    return moveCount;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int findFirst = 0;
    int findSecond = 0;

    for (const vector<int>& drawRectangle : rectangle)
    {
        CreateRectangle(drawRectangle);
    } 

    board[itemY * MAP_SCALE][itemX * MAP_SCALE] = GOAL;
    board[characterY * MAP_SCALE][characterX * MAP_SCALE] = VISITED;

    findFirst = FindItem(characterX * MAP_SCALE, characterY * MAP_SCALE);
    findSecond = FindItem(characterX * MAP_SCALE, characterY * MAP_SCALE);

    return findFirst < findSecond ? findFirst : findSecond;
}

int main()
{
    solution({ {1, 1, 7, 4},{3, 2, 5, 5},{4, 3, 6, 9},{2, 6, 8, 8} }, 1, 3, 7, 8);
}

void DrawMap()
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}