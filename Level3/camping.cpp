/*
	https://school.programmers.co.kr/learn/courses/30/lessons/1833
*/

#include <vector>
#include <algorithm>

using namespace std;

struct camp
{
    int xMin, yMin;
    int xMax, yMax;
    int index;
};

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    vector<camp> camps;
    sort(data.begin(), data.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    for (int i = 0; i < data.size(); ++i)
    {
        for (int j = i + 1; j < data.size(); ++j)
        {
            if (data[i][0] == data[j][0] || data[i][1] == data[j][1])
            {
                continue;
            }

            camp newCamp{ data[i][0], min(data[i][1], data[j][1]), 
                data[j][0], max(data[i][1], data[j][1]), i
            };

            camps.push_back(newCamp);
        }
    }

    for (camp& c : camps)
    {
        bool isAble = true;

        for (int i = c.index; i < data.size(); ++i)
        {
            if (data[i][0] > c.xMin && data[i][0] < c.xMax && data[i][1] > c.yMin && data[i][1] < c.yMax)
            {
                isAble = false;
                break;
            }
            else if (data[i][0] > c.xMax)
            {
                isAble = true;
                break;
            }
        }

        if (isAble)
        {
            ++answer;
        }
    }

    return answer;
}