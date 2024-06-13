/*
	https://school.programmers.co.kr/learn/courses/30/lessons/131703
*/

#include <vector>

using namespace std;

int minimum = 100000;
int width, height;

void reverseColumn(vector<vector<int>>& board, int index)
{
    for (int i = 0; i < height; ++i)
    {
        board[i][index] = board[i][index] == 0 ? 1 : 0;
    }
}

void reverseRow(vector<vector<int>>& board, int index)
{
    int y = index - width;
    for (int i = 0; i < width; ++i)
    {
        board[y][i] = board[y][i] == 0 ? 1 : 0;
    }
}

bool isCorrect(vector<vector<int>>& board, const vector<vector<int>>& target, int index)
{
    if (index <= width)
    {
        return true;
    }

    for (int y = 0; y < index - width; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (board[y][x] != target[y][x])
            {
                return false;
            }
        }
    }

    return true;
}

void DFS(vector<vector<int>>& board, const vector<vector<int>>& target, int index, int count)
{
    if (index >= width)
    {
        bool correct = isCorrect(board, target, index);
        
        if (correct && (index == width + height))
        {
            minimum = min(minimum, count);

            return;
        }
        else if (!correct)
        {
            return;
        }
    }

    if (index >= width)
    {
        reverseRow(board, index);
        DFS(board, target, index + 1, count + 1);
        reverseRow(board, index);
    }
    else
    {
        reverseColumn(board, index);
        DFS(board, target, index + 1, count + 1);
        reverseColumn(board, index);
    }

    DFS(board, target, index + 1, count);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    width = target[0].size();
    height = target.size();

    DFS(beginning, target, 0, 0);

    if (minimum == 100000)
    {
        return -1;
    }

    return minimum;
}