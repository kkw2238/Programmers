/*
	https://school.programmers.co.kr/learn/courses/30/lessons/161990
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INTMAX = 2147483647;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer{ INTMAX , INTMAX , 0, 0 };

    for (int y = 0; y < wallpaper.size(); ++y)
    {
        for (int x = 0; x < wallpaper[y].size(); ++x)
        {
            if (wallpaper[y][x] == '#')
            {
                answer = { min(answer[0], x), min(answer[1], y), max(answer[2], x + 1), max(answer[3], y + 1) };
            }
        }
    }

    return answer;
}