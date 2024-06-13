/*
    https://programmers.co.kr/learn/courses/30/lessons/12913
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    for (int row = 1; row < land.size(); ++row)
    {
        for (int column = 0; column < land[row].size(); ++column)
        {
            int score = 0;
            for (int beforeColumn = 0; beforeColumn < land[row].size(); ++beforeColumn)
            {
                // ���� ���� ���� ���� ���� ������ ��� 
                if (column == beforeColumn)
                {
                    continue;
                }

                // ���� �� + ���� �� ���� �� ���� ���� ������ ���
                score = max(score, land[row - 1][beforeColumn] + land[row][column]);
            }

            land[row][column] = score;
        }
    }

    return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}