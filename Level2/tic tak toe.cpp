/*
    https://school.programmers.co.kr/learn/courses/30/lessons/160585
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int XCount = 0, OCount = 0;
    bool XWin = false, OWin = false;

    string cross = "", reverseCross = "";

    for (int x = 0; x < 3; ++x)
    {
        int heightXCount = 0, heightOCount = 0;

        for (int y = 0; y < 3; ++y)
        {
            if (board[y][x] == 'X')
            {
                ++heightXCount;
            }
            else if (board[y][x] == 'O')
            {
                ++heightOCount;
            }
        }

        cross += board[x][x];
        reverseCross += board[2 - x][x];

        XCount += heightXCount;
        OCount += heightOCount;

        if (board[x] == "XXX" || heightXCount == 3 || reverseCross == "XXX" || cross == "XXX")
        {
            XWin = true;
        }
        if (board[x] == "OOO" || heightOCount == 3 || reverseCross == "OOO" || cross == "OOO")
        {
            OWin = true;
        }
    }

    if (XWin && OWin)
    {
        return 0;
    }
    else if (OWin && (XCount >= OCount))
    {
        return 0;
    }
    else if (XWin && (OCount > XCount))
    {
        return 0;
    }
    int offset = (XCount - OCount);

    if (XCount > OCount)
    {
        return 0;
    }
    else if ((offset * offset) > 1)
    {
        return 0;
    }

    return 1;
}