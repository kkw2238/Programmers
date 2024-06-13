#include <string>
#include <vector>
#include <tuple>

using namespace std;

const bool HasCross(const vector<int>& line1, const vector<int>& line2)
{
    return (line1[0] * line2[1]) - (line1[1] * line2[0]) != 0;
}

pair<int, int> GetCrossPos(const vector<int>& line1, const vector<int>& line2)
{
    long long A, B, C, D, E, F;
    tie(A, B, E) = make_tuple(line1[0], line1[1], line1[2]);
    tie(C, D, F) = make_tuple(line2[0], line2[1], line2[2]);
    
    long long AD_BC = A * D - B * C;

    int XPos = ((B * F) - (E * D)) / AD_BC;
    int YPos = ((E * C) - (A * F)) / AD_BC;

    return pair(XPos, YPos);
}

const bool Verify(const vector<int>& line, const pair<int, int>& point)
{
    return (line[0] * point.first + line[1] * point.second) == -line[2];
}

vector<string> solution(vector<vector<int>> line) {
    vector<pair<int, int>> crossPoints;
    pair<int, int> XSize(INT_MAX, -INT_MAX);
    pair<int, int> YSize(INT_MAX, -INT_MAX);

    for (int line1 = 0; line1 < line.size(); ++line1)
    {
        for (int line2 = line1 + 1; line2 < line.size(); ++line2)
        {
            if (!HasCross(line[line1], line[line2]))
            {
                continue;
            }

            pair<int, int> cross = GetCrossPos(line[line1], line[line2]);
            if (!(Verify(line[line1], cross) && Verify(line[line2], cross)))
            {
                continue;
            }

            XSize.first = min(XSize.first, cross.first);
            XSize.second = max(XSize.second, cross.first);

            YSize.first  = min(YSize.first, cross.second);
            YSize.second = max(YSize.second, cross.second);

            crossPoints.push_back(cross);
        }
    }

    string str = string(XSize.second - XSize.first + 1, '.');
    vector<string> answer(YSize.second - YSize.first + 1, str);

    for (const pair<int, int>& point : crossPoints)
    {
        answer[answer.size() - (point.second - YSize.first) - 1][point.first - XSize.first] = '*';
    }

    return answer;
}