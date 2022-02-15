/*
    https://programmers.co.kr/learn/courses/30/lessons/87391?language=cpp
*/

#include <vector>

using namespace std;

enum { LEFT, RIGHT, UP, DOWN};
enum { X_MIN, X_MAX, Y_MIN, Y_MAX, X_FINALLY, Y_FINALLY};

vector<long long> startAtZero;
vector<long long> startAtMN;

vector<long long> DistributeQueries(vector<vector<int>>& queries, int m, int n)
{
    vector<long long> startAtZero{ 0, 0};
    vector<long long> startAtMN{ m - 1, n - 1};

    vector<long long> result(6, 0);
    for (vector<int>& query : queries)
    {
        switch (query[0])
        {
        case LEFT:
            startAtZero[0] = max(startAtZero[0] - query[1], (long long)0);
            startAtMN[0] = max(startAtMN[0] - query[1], (long long)0);
            break;

        case RIGHT:
            startAtZero[0] = min(startAtZero[0] + query[1], (long long)m - 1);
            startAtMN[0] = min(startAtMN[0] + query[1], (long long)m - 1);
            break;

        case UP:
            startAtZero[1] = max(startAtZero[1] - query[1], (long long)0);
            startAtMN[1] = max(startAtMN[1] - query[1], (long long)0);
            break;

        case DOWN:
            startAtZero[1] = min(startAtZero[1] + query[1], (long long)n - 1);
            startAtMN[1] = min(startAtMN[1] + query[1], (long long)n - 1);
            break;
        }

        if (query[0] <= RIGHT)
        {
            result[X_FINALLY] += query[1];
            if (result[X_FINALLY] < result[X_MIN])
            {
                result[X_MIN] = X_FINALLY;
            }
            else if (result[X_FINALLY] > result[X_MAX])
            {
                result[X_MAX] = X_FINALLY;
            }
        }
        else
        {
            result[Y_FINALLY] += query[1];
            if (result[Y_FINALLY] < result[Y_MIN])
            {
                result[Y_MIN] = Y_FINALLY;
            }
            else if (result[Y_FINALLY] > result[Y_MAX])
            {
                result[Y_MAX] = Y_FINALLY;
            }
        }
    }

    return result;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;

    vector<long long> distributedQueries = DistributeQueries(queries, m, n);
    long long requestX = x - distributedQueries[X_FINALLY];
    long long requestY = y - distributedQueries[Y_FINALLY];

    long long totalBlocks = n * m;
    
    if (startAtZero[1] == y)
    {
        if (startAtZero[0] == x)
        {
            answer += distributedQueries[X_MIN] * distributedQueries[Y_MIN];
        }
        if (requestX > startAtZero[0] && requestX < startAtMN[0])
        {
            answer += -distributedQueries[Y_MIN];
        }
        if (startAtMN[0] == x)
        {
            answer += (m - distributedQueries[X_MAX]) * distributedQueries[Y_MIN];
        }
    }
    if (startAtZero[1] < requestY && startAtMN[1] > requestY)
    {
        if (startAtZero[0] == x)
        {
            answer += distributedQueries[X_MIN] * distributedQueries[Y_MIN];
        }
        if (requestX > startAtZero[0] && requestX < startAtMN[0])
        {
            answer += -distributedQueries[Y_MIN];
        }
        if (startAtMN[0] == x)
        {
            answer += (m - distributedQueries[X_MAX]) * distributedQueries[Y_MIN];
        }
    }
    
    return answer;
}