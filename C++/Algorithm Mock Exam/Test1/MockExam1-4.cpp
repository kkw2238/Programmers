#include <vector>

using namespace std;

using Board = vector<vector<int>>;

int result = 101;

const bool isCorrect(const Board& a, const Board& b)
{
    for (int y = 0; y < a.size(); ++y)
    {
        for (int x = 0; x < a[y].size(); ++x)
        {
            if (a[y][x] != b[y][x])
            {
                return false;
            }
        }
    }

    return true;
}

void reverse(int& num)
{
    num = (num == 1) ? 0 : 1;
}

void reverseRow(Board& board, int index)
{
    if (index < board.size())
    {
        for (int& block : board[index])
        {
            reverse(block);
        }
    }
}

void reverseColumn(Board& board, int index)
{
    if (index < board[0].size())
    {
        for (int i = 0; i < board.size(); ++i)
        {
            reverse(board[i][index]);
        }
    }
}

void FindAnswer(Board beginning, const Board& target, int row, int column, int count)
{
    if (isCorrect(beginning, target) && count < result)
    {
        result = count;
        return;
    }
    else if (count > result)
    {
        return;
    }

    if (row < beginning.size())
    {
        for (int y = row; y < beginning.size(); ++y)
        {
            reverseRow(beginning, y);
            FindAnswer(beginning, target, y + 1, column, count + 1);
            reverseRow(beginning, y);
        }

        FindAnswer(beginning, target, beginning.size(), column, count);
    }
    else if (column < beginning[0].size())
    {
        for (int x = column; x < beginning[0].size(); ++x)
        {
            reverseColumn(beginning, x);
            FindAnswer(beginning, target, row, x + 1, count + 1);
            reverseColumn(beginning, x);
        }

        FindAnswer(beginning, target, row, beginning[0].size(), count);
    }
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    FindAnswer(beginning, target, 0, 0, 0);
    if (result == 101)
    {
        return -1;
    }
    return result;
}