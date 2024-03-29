/*
    https://programmers.co.kr/learn/courses/30/lessons/92344
*/
#include <string>
#include <vector>

using namespace std;

enum { TYPE, START_Y, START_X, END_Y, END_X, DAMAGE};
enum { HEAL, DEAL };

int destroyed_buildingCount = 0;

#pragma region �����ڵ�

#include <iostream>

void DrawBoard(vector<vector<int>>& board)
{
    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            cout << board[y][x] << '\t';
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

int before_solution(vector<vector<int>> board, vector<vector<int>> skill) {
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

#pragma endregion
//
//#include <vector>
//
//using namespace std;
//
//enum { TYPE, START_Y, START_X, END_Y, END_X, DAMAGE };
//enum { HEAL, DEAL };

void usedSkill(const vector<int>& skillRange, vector<vector<int>>& accumulateDamage)
{
    int damage = skillRange[DAMAGE];
    if (skillRange[TYPE] == DEAL)
    {
        damage = -damage;
    }

    accumulateDamage[skillRange[START_Y]][skillRange[START_X]] += damage;
    accumulateDamage[skillRange[END_Y] + 1][skillRange[END_X] + 1] += damage;
    accumulateDamage[skillRange[START_Y]][skillRange[END_X] + 1] -= damage;
    accumulateDamage[skillRange[END_Y] + 1][skillRange[START_X]] -= damage;
}

void frefixSum(vector<vector<int>>& accumulateDamage)
{
    for (int y = 0; y < accumulateDamage.size(); ++y)
    {
        for (int x = 1; x < accumulateDamage[y].size(); ++x)
        {
            accumulateDamage[y][x] += accumulateDamage[y][x - 1]; 
        }
    }

    for (int x = 0; x < accumulateDamage[0].size(); ++x)
    {
        for (int y = 1; y < accumulateDamage.size(); ++y)
        {
            accumulateDamage[y][x] += accumulateDamage[y - 1][x];
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int result = 0;

    vector<vector<int>> accumulateDamage(board.size() + 1, vector<int>(board[0].size() + 1, 0));

    for (const vector<int>& skillRange : skill)
    {
        usedSkill(skillRange, accumulateDamage);
    }
    DrawBoard(accumulateDamage);

    frefixSum(accumulateDamage);

    DrawBoard(accumulateDamage);

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            board[y][x] += accumulateDamage[y][x];
            if (board[y][x] <= 0)
            {
                ++result;
            }
        }
    }
   
    DrawBoard(board);
    return result;
}

int main()
{
    vector<vector<int>> board = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> skill = {{1, 1, 1, 2, 2, 4}, {1, 0, 0, 1, 1, 2}, {2, 2, 0, 2, 0, 100}};

    solution(board, skill);
}