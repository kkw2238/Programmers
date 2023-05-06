/*
	https://school.programmers.co.kr/learn/courses/30/lessons/134239
*/

#include <vector>

using namespace std;

double getIntegral(double a, double b)
{
    double minimun = min(a, b);
    double maximum = max(a, b);
    return minimun + (maximum - minimun) / 2.0;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> lIntegral{ 0.0 };
    vector<double> integral{ (double)k };
    double totalSum = 0.0;
    int index = 1;

    while (k != 1)
    {
        if (k % 2 == 0)
        {
            k /= 2;
        }
        else
        {
            k = k * 3 + 1;
        }

        integral.push_back((double)k);
        ++index;

        if (index > 1)
        {
            totalSum += getIntegral(integral[index - 1], integral[index - 2]);
            lIntegral.push_back(totalSum);
        }
    }

    for (vector<int> ran : ranges)
    {
        int l = ran[0];
        int r = lIntegral.size() + ran[1] - 1;

        if (r < l)
        {
            answer.push_back(-1.0);
        }
        else
        {
            answer.push_back(lIntegral[r] - lIntegral[l]);
        }
    }

    return answer;
}

int main()
{
    solution(5, { {0, 0},{0, -1},{2, -3},{3, -3} });
}