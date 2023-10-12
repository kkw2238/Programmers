/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12984
*/

#include <vector>
#include <map>

using namespace std;

long long getCost(map<long long, long long>& hCount, int mid, int P, int Q)
{
    long long cost = 0;

    for (auto c : hCount)
    {
        if (mid < c.first)
        {
            cost += ((c.first - mid) * (long long)Q * c.second);
        }
        else
        {
            cost += ((mid - c.first) * (long long)P * c.second);
        }
    }

    return cost;
}

#include <iostream>

long long solution(vector<vector<int>> land, int P, int Q) {
    long long answer = -1;
    int l = 2147483647, r = -2147483647;
    long long total = 0;
    long long n = (long long)land.size();

    map<long long, long long> heightCount;

    for (long long i = 0; i < n; ++i)
    {
        for (long long j = 0; j < n; ++j)
        {
            ++heightCount[land[i][j]];

            total += (long long)land[i][j];

            l = min(l, land[i][j]);
            r = max(r, land[i][j]);
        }
    }

    total = total / (n * n);

    int mid = (int)total;
    long long bCost = getCost(heightCount, mid, P, Q);
    
    if (P > Q)
    {
        r = l;
        l = mid - 1;
    }
    else
    { 
        l = mid + 1;
    }
    
    while (((P > Q) && (r < l)) || (P <= Q) && (r > l))
    {
        mid = (l + r) / 2;
        long long nCost = getCost(heightCount, mid, P, Q);

        if (nCost >= bCost)
        {
            r = mid + ((P > Q) ? 1 : -1);
        }
        else
        {
            l = mid + ((P > Q) ? 1 : -1);
            bCost = nCost;

            cout << mid << ' ' << bCost << '\n';
        }
    }

    return bCost;
}

int main()
{
    solution({{4, 4, 3}, {3, 2, 2}, {2, 1, 0}}, 5, 3);
}