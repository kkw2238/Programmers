/*
    https://school.programmers.co.kr/learn/courses/30/lessons/172928?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

int width = 0;
int height = 0;

const bool isInside(const int x, const int y)
{
    return x >= 0 && x < width && y >= 0 && y < height;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    int x, y;

    height = park.size();
    width = park[0].size();

    for (y = 0; y < park.size(); ++y)
    {
        x = park[y].find('S');

        if (x != string::npos)
        {
            break;
        }
    }

    for (string route : routes)
    {
        int xDir = 0;
        int yDir = 0;
        int dist = route[2] - '0';

        switch (route[0])
        {
        case 'N':
            yDir = -1;
            break;
        case 'S':
            yDir = 1;
            break;
        case 'E':
            xDir = 1;
            break;
        case 'W':
            xDir = -1;
            break;
        }

        if (!isInside(x + xDir * dist, y + yDir * dist))
        {
            continue;
        }

        for (int i = 1; i <= dist; ++i)
        {
            if (park[y + yDir * i][x + xDir * i] == 'X')
            {
                dist = 0;
                break;
            }
        }

        y += yDir * dist;
        x += xDir * dist;
    }

    return {y , x};
}