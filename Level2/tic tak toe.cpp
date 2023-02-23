/*
    https://school.programmers.co.kr/learn/courses/30/lessons/160585
*/

#include <string>
#include <vector>

using namespace std;


int solution(vector<string> board) {
    int answer = -1;

    int XCount = 0;
    int OCount = 0;

    for (int y = 0; y < 3; ++y)
    {
        int widthXCount = 0;
        int widthYCount = 0;

        for (int x = 0; x < 3; ++x)
        {
            if (board[y][x] == 'X')
            {
                ++widthXCount;
            }
            else if (board[y][x] == 'O')
            {
                ++widthYCount;
            }
        }
    }

    if (XCount > OCount)
    {
        return 0;
    }

    return answer;
}