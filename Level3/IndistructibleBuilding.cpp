/*
    https://programmers.co.kr/learn/courses/30/lessons/92344
*/
#include <string>
#include <vector>

using namespace std;

enum { TYPE, START_Y, START_X, END_Y, END_X, DAMAGE};

int destroyed_buildingCount = 0;

#include <iostream>

void DrawBoard(vector<vector<int>>& board)
{
    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            cout << board[y][x] << ' ';
        }

        cout << '\n';
    }
}

const bool IsRevive(const int hp, const int heal)
{
    return (hp - heal <= 0) && (hp > 0);
}

const bool IsDead(const int hp, const int damage)
{
    return (hp + damage > 0) && (hp <= 0);
}

void HealBuilding(const vector<int>& skillRange, vector<vector<int>>& board)
{
    for (int x = skillRange[START_X]; x <= skillRange[END_X]; ++x)
    {
        for (int y = skillRange[START_Y]; y <= skillRange[END_Y]; ++y)
        {
            if (board[y][x] += skillRange[DAMAGE]; IsRevive(board[y][x], skillRange[DAMAGE]))
            {
                cout << "REVIVE ! " << x << ", " << y << '\n';
                --destroyed_buildingCount;
            }
        }
    }
}

void DamageBuilding(const vector<int>& skillRange, vector<vector<int>>& board)
{
    for (int x = skillRange[START_X]; x <= skillRange[END_X]; ++x)
    {
        for (int y = skillRange[START_Y]; y <= skillRange[END_Y]; ++y)
        {
            if (board[y][x] -= skillRange[DAMAGE]; IsDead(board[y][x], skillRange[DAMAGE]))
            {
                cout << "DEAD ! " << x << ", " << y << '\n';
                ++destroyed_buildingCount;
            }
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    for (const vector<int>& skillRange : skill)
    {
        if (skillRange[TYPE] == 1)
        {
            DamageBuilding(skillRange, board);
        }
        else
        {
            HealBuilding(skillRange, board);
        }

        DrawBoard(board);
    }

    return board.size() * board[0].size() - destroyed_buildingCount;
}

int main()
{
    vector<vector<int>> board = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> skill = {{1, 1, 1, 2, 2, 4}, {1, 0, 0, 1, 1, 2}, {2, 2, 0, 2, 0, 100}};

    solution(board, skill);
}