/*
	https://school.programmers.co.kr/learn/courses/30/lessons/1836
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

const int XIndex = 1;
const int YIndex = 0;

bool isAble(vector<vector<int>>& pos, vector<string>& board)
{
    int xDir = pos[0][XIndex] > pos[1][XIndex] ? -1 : 1;
    int yDir = pos[0][YIndex] > pos[1][YIndex] ? -1 : 1;

    char target = board[pos[0][YIndex]][pos[0][XIndex]];

    for (int y = pos[0][YIndex] + yDir; y != pos[1][YIndex] + yDir; y += yDir)
    {
        int x = pos[0][XIndex];
        if (board[y][x] != target && board[y][x] != '.')
        {
            break;
        }
        for (; x != pos[1][XIndex] + xDir; x += xDir)
        {
            if (board[y][x] != target && board[y][x] != '.')
            {
                break;
            }
            if (board[y][x] == target)
            {
                return true;
            }
        }
    }

    for (int x = pos[0][XIndex] + xDir; x != pos[1][XIndex] + xDir; x += xDir)
    {
        int y = pos[0][YIndex];
        if (board[y][x] != target && board[y][x] != '.')
        {
            break;
        }
        for (; y != pos[1][YIndex] + yDir; y += yDir)
        {
            if (board[y][x] != target && board[y][x] != '.')
            {
                break;
            }
            if (board[y][x] == target)
            {
                return true;
            }
        }
    }

    return false;
}

string solution(int m, int n, vector<string> board) {
    map<char, vector<vector<int>>> friends;
    string answer = "";

    for (int y = 0; y < m; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (isalpha(board[y][x]))
            {
                friends[board[y][x]].push_back({ y, x });
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        if (friends.find(c) == friends.end())
        {
            continue;
        }
        if (isAble(friends[c], board))
        {
            board[friends[c][0][YIndex]][friends[c][0][XIndex]] = '.';
            board[friends[c][1][YIndex]][friends[c][1][XIndex]] = '.';
            answer += c;
            friends.erase(c);

            c = 'A' - 1;
        }
    }

    if (!friends.empty())
    {
        return "IMPOSSIBLE";
    }

    return answer;
}

int main()
{
    solution(3, 3, { "DBA", "C*A", "CDB" });
}