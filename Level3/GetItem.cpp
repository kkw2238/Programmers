/*
	https://programmers.co.kr/learn/courses/30/lessons/87694?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

enum MARK_TYPE { NONE, OUTLINE, INNER, VISITED, GOAL };
enum RECTANGLE_POSITION_INDEX { START_X_INDEX = 0, START_Y_INDEX = 1, END_X_INDEX = 2, END_Y_INDEX = 3 };

const int BOARD_LENGTH = 52;

vector<vector<int>> board = vector<vector<int>>(BOARD_LENGTH, vector<int>(BOARD_LENGTH, NONE));

const bool IsRectangleOutLine(int xOffset, int yOffset, int width, int height)
{
    return xOffset == 0 || xOffset == width - 1 || yOffset == 0 || yOffset == height - 1;
}

const bool IsMoveAbleOutline(const int xPosition, const int yPosition)
{
    return board[yPosition][xPosition] == OUTLINE || board[yPosition][xPosition] == GOAL;
}

void CreateRectangle(const vector<int>& rectangle)
{
    int width = rectangle[END_X_INDEX] - rectangle[START_X_INDEX]; 
    int height = rectangle[END_Y_INDEX] - rectangle[START_Y_INDEX];

    for (int xOffset = 0; xOffset < width; ++xOffset)
    {
        for (int yOffset = 0; yOffset < height; ++yOffset)
        {
            int positionX = rectangle[START_X_INDEX] + xOffset;
            int positionY = rectangle[START_Y_INDEX] + yOffset;

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
            return moveCount;
        }
        
        board[nowPosition.second][nowPosition.first] = VISITED;
    }

    return moveCount;
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
} 

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int findFirst = 0;
    int findSecond = 0;

    board[itemY][itemX] = GOAL;
    board[characterY][characterX] = VISITED;

    for (const vector<int>& drawRectangle : rectangle)
    {
        CreateRectangle(drawRectangle);
    }

    findFirst = FindItem(characterX, characterY);
    findSecond = FindItem(characterX, characterY);

    return answer;
}