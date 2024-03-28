/*
    https://programmers.co.kr/learn/courses/30/lessons/87391?language=cpp
*/

//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//enum { LEFT, RIGHT, UP, DOWN};
//enum { X_MIN, X_MAX, Y_MIN, Y_MAX, X_FINALLY, Y_FINALLY};
//
//vector<long long> startAtZero;
//vector<long long> startAtMN;
//
//vector<long long> DistributeQueries(vector<vector<int>>& queries, int m, int n)
//{
//    startAtZero = vector<long long>{ 0, 0 };
//    startAtMN = vector<long long>{ m - 1, n - 1};
//
//    vector<long long> result(6, 0);
//    for (vector<int>& query : queries)
//    {
//        switch (query[0])
//        {
//        case LEFT:
//            startAtZero[0] = max(startAtZero[0] - query[1], (long long)0);
//            startAtMN[0] = max(startAtMN[0] - query[1], (long long)0);
//            break;
//
//        case RIGHT:
//            startAtZero[0] = min(startAtZero[0] + query[1], (long long)m - 1);
//            startAtMN[0] = min(startAtMN[0] + query[1], (long long)m - 1);
//            break;
//
//        case UP:
//            startAtZero[1] = max(startAtZero[1] - query[1], (long long)0);
//            startAtMN[1] = max(startAtMN[1] - query[1], (long long)0);
//            break;
//
//        case DOWN:
//            startAtZero[1] = min(startAtZero[1] + query[1], (long long)n - 1);
//            startAtMN[1] = min(startAtMN[1] + query[1], (long long)n - 1);
//            break;
//        }
//
//        if (query[0] <= RIGHT)
//        {
//            result[X_FINALLY] += query[1];
//            if (result[X_FINALLY] < result[X_MIN])
//            {
//                result[X_MIN] = X_FINALLY;
//            }
//            else if (result[X_FINALLY] > result[X_MAX])
//            {
//                result[X_MAX] = X_FINALLY;
//            }
//        }
//        else
//        {
//            result[Y_FINALLY] += query[1];
//            if (result[Y_FINALLY] < result[Y_MIN])
//            {
//                result[Y_MIN] = Y_FINALLY;
//            }
//            else if (result[Y_FINALLY] > result[Y_MAX])
//            {
//                result[Y_MAX] = Y_FINALLY;
//            }
//        }
//    }
//
//    return result;
//}
//
//long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
//    long long answer = 0;
//
//    vector<long long> distributedQueries = DistributeQueries(queries, m, n);
//    long long requestX = x - distributedQueries[X_FINALLY];
//    long long requestY = y - distributedQueries[Y_FINALLY];
//
//    long long totalBlocks = n * m;
//    
//    if (startAtZero[1] == y) 
//    {
//        if (startAtZero[0] == x)
//        {
//            answer += (startAtZero[0] + 1) * (startAtZero[1] + 1);
//        }
//        if (requestX > startAtZero[0] && requestX < startAtMN[0])
//        {
//            answer += startAtZero[1];
//        }
//        if (startAtMN[0] == x)
//        {
//            answer += (startAtMN[0] + 1) * (startAtZero[1] + 1);
//        }
//    }
//    
//    if (requestY > startAtZero[1] && requestY < startAtMN[1])
//    {
//        if (startAtZero[0] == x)
//        {
//            answer += startAtZero[0];
//        }
//        if (requestX > startAtZero[0] && requestX < startAtMN[0])
//        {
//            ++answer;
//        }
//        if (startAtMN[0] == x)
//        {
//            answer += startAtMN[0];
//        }
//    }
//
//    if (startAtMN[1] == y)
//    {
//        if (startAtZero[0] == x)
//        {
//            answer += (startAtZero[0] + 1) * (startAtMN[1] + 1);
//        }
//        if (requestX > startAtZero[0] && requestX < startAtMN[0])
//        {
//            answer += startAtMN[1];
//        }
//        if (startAtMN[0] == x)
//        {
//            answer += (startAtMN[0] + 1) * (startAtMN[1] + 1);
//        }
//    }
//
//    return answer > totalBlocks ? totalBlocks : answer;
//}

//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//enum { LEFT, RIGHT, UP, DOWN };
//
//long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
//    long long answer = -1;
//    vector<int> totalDistance(2, 0);
//    vector<pair<int, int>> maximumDistance(4, pair(0, 0));
//
//    int nowType = queries[0][0];
//    int moveDistance = 0;
//    int orders = 0;
//
//    for (vector<int>& query : queries)
//    {
//        if (nowType != query[0])
//        {
//            int lineType = nowType / 2;
//            totalDistance[lineType] += moveDistance;
//
//            if (totalDistance[lineType] > 0 && totalDistance[lineType] > maximumDistance[lineType + 1].first)
//            {
//                maximumDistance[lineType + 1].first = totalDistance[lineType];
//                maximumDistance[lineType + 1].second = orders++;
//            }
//            else if (totalDistance[lineType] < 0 && -totalDistance[lineType] > maximumDistance[lineType].first)
//            {
//                maximumDistance[lineType].first = -totalDistance[lineType];
//                maximumDistance[lineType].second = orders++;
//            }
//        }
//
//        switch (query[0])
//        {
//        case LEFT:
//        case UP:
//            moveDistance -= query[1];
//            break;
//        case RIGHT:
//        case DOWN:
//            moveDistance += query[1];
//            break;
//        }
//    }
//
//    return answer;
//}

//#include <vector>
//
//using namespace std;
//
//struct Range {
//    long long minX = 0, minY = 0;
//    long long maxX = 0, maxY = 0;
//    long long width, height;
//
//    Range(int boardwidth, int boardheight, int x, int y) 
//    {
//        width = static_cast<long long>(boardwidth - 1);
//        height = static_cast<long long>(boardheight - 1);
//        minX = static_cast<long long>(x);
//        maxX = minX;
//        minY = static_cast<long long>(y);
//        maxY = minY;
//    }
//
//    long long LMove(long long x)
//    {
//        if (maxX > 0 && maxX < width && x > maxX)
//        {
//            return -1;
//        }
//
//        if (minX == width || maxX == width)
//        {
//            minX = max(static_cast<long long>(0), width - x);
//        }
//        else
//        {
//            minX = max(static_cast<long long>(0), minX - x);
//            maxX = max(static_cast<long long>(0), maxX - x);
//        }
//
//        return maxX;
//    }
//    
//    long long RMove(long long x)
//    {
//        if (minX > 0 && minX < width && x > width - minX)
//        {
//            return -1;
//        }
//
//        if (maxX == 0 || minX == 0)
//        {
//            maxX = min(width, x);
//        }
//        else
//        {
//            minX = min(width, minX + x);
//            maxX = min(width, maxX + x);
//        }
//        return minX;
//    }
//
//    long long UMove(long long y)
//    {
//        if (maxY < height && maxY > 0 && y > maxY)
//        {
//            return -1;
//        }
//
//        if (minY == height || maxY == height)
//        {
//            minY = max(static_cast<long long>(0), height - y);
//        }
//        else
//        {
//            minY = max(static_cast<long long>(0), minY - y);
//            maxY = max(static_cast<long long>(0), maxY - y);
//        }
//
//        return maxY;
//    }
//    
//    long long DMove(long long y)
//    {
//        if (minY > 0 && minY < height && y > height - minY)
//        {
//            return -1;
//        }
//
//        if (maxY == 0 || minY == 0)
//        {
//            maxY = min(height, y);
//        }
//        else
//        {
//            minY = min(static_cast<long long>(height), minY + y);
//            maxY = min(static_cast<long long>(height), maxY + y);
//        }
//        
//        return minY;
//    }
//
//    long long GetResult() const { return (maxX - minX + 1) * (maxY - minY + 1); };
//};
//
//#include <iostream>
//long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
//    Range answerRange(m, n, y, x);
//    
//    vector<vector<long long>> newQueries;
//
//    for (int i = 0; i < queries.size(); ++i)
//    {
//        if (i > 0 && queries[i][0] == newQueries.back()[0])
//        {
//            newQueries[newQueries.size() - 1][1] += static_cast<long long>(queries[i][1]);
//        }
//        else
//        {
//            newQueries.push_back({ queries[i][0], static_cast<long long>(queries[i][1]) });
//        }
//    }
//
//    for (int i = newQueries.size() - 1; i >= 0; --i)
//    {
//        long long result = 0;
//        switch (newQueries[i][0])
//        {
//        case 0:
//            result = answerRange.RMove(newQueries[i][1]);
//            break;
//        case 1:
//            result = answerRange.LMove(newQueries[i][1]);
//            break;
//        case 2:
//            result = answerRange.DMove(newQueries[i][1]);
//            break;
//        case 3:
//            result = answerRange.UMove(newQueries[i][1]);
//            break;
//        }
//        cout << format("minX : {0}, maxX : {1}, minY : {2}, : maxY : {3}, result : {4}\n", answerRange.minX, answerRange.maxX, answerRange.minY, answerRange.maxY, result);
//
//        
//        if (result == -1)
//        {
//            return 0;
//        }
//    }
//
//    for (int ny = 0; ny < n; ++ny)
//    {
//        for (int nx = 0; nx < m; ++nx)
//        {
//            int tmpx = nx;
//            int tmpy = ny;
//            for (vector<int>& a : queries)
//            {
//                switch (a[0])
//                {
//                case 0:
//                    tmpx = max(0, tmpx - a[1]);
//                    break;
//                case 1:
//                    tmpx = min(m - 1, tmpx + a[1]);
//                    break;
//                case 2:
//                    tmpy = max(0, tmpy - a[1]);
//                    break;
//                case 3:
//                    tmpy = min(n - 1, tmpy + a[1]);
//                }
//            }
//
//            if (tmpx == y && tmpy == x)
//            {
//                cout << nx << " " << ny << '\n';
//            }
//        }
//    }
//
//
//    return answerRange.GetResult();
//}

// 아1 위2 오1 위3 왼1 위1 아1 위2 오1 위3 왼1 위1

#include <vector>

using namespace std;

long long afterProcess(pair<long long, long long>& lResult, pair<long long, long long>& rResult, long long& l, long long& r, long long maxRange, long long d)
{
    if (lResult.first == -1 && rResult.first == -1)
    {
        return -1;
    }
    else if (lResult.first != -1 && rResult.first != -1)
    {
        l = min(lResult.first, rResult.first);
        r = max(lResult.second, rResult.second);

        return l;
    }

    if (d > 0)
    {
        if (lResult.first == -1)
        {
            l = rResult.first;
            r = maxRange;
        }
        else if (rResult.first == -1)
        {
            l = lResult.first;
            r = maxRange;
        }
    }
    else
    {
        if (lResult.first == -1)
        {
            l = 0;
            r = rResult.second;
        }
        else if (rResult.first == -1)
        {
            l = 0;
            r = lResult.first;
        }
    }
    return l;
}

pair<long long, long long> processQuery(long long& x, long long minRange, long long maxRange, long long d)
{
    pair<long long, long long> result;

    if (d > 0)
    {
        if (x > 0)
        {
            if (d + x > maxRange)
            {
                return pair(-1, -1);
            }
        }
        else
        {
            return pair(0, min(maxRange, x + d));
        }
    }
    else
    {
        if (x < maxRange)
        {
            if (d + x < 0)
            {
                return pair(-1 ,- 1);
            }
        }
        else
        {
            return pair(max((long long)0, x + d), maxRange);
        }
    }

    return pair(x + d, x + d);
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    long long l = y, r = y, b = x, t = x;
    vector<vector<long long>> newQueries;

    for (int i = queries.size() - 1; i >= 0; --i)
    {
        if (newQueries.empty() || newQueries.back()[0] != queries[i][0])
        {
            newQueries.push_back({ queries[i][0], static_cast<long long>(queries[i][1]) });
        }
        else
        {
            newQueries.back()[1] += static_cast<long long>(queries[i][1]);
        }
    }

    for (vector<long long>& query : newQueries)
    {
        pair<long long, long long> lresult, rresult;
        long long result = 0;
        switch (query[0])
        {
        case 1:
            query[1] = -query[1];
        case 0:
            lresult = processQuery(l, 0, m - 1, query[1]);
            rresult = processQuery(r, 0, m - 1, query[1]);

            result = afterProcess(lresult, rresult, l, r, m - 1, query[1]);
            break;
        case 3:
            query[1] = -query[1];
        case 2:
            lresult = processQuery(t, 0, n - 1, query[1]);
            rresult = processQuery(b, 0, n - 1, query[1]);

            result = afterProcess(lresult, rresult, t, b, n - 1, query[1]);
            break;
        }

        if (result == -1)
        {
            return 0;
        }
    }

    return (r - l + 1) * (b - t + 1);
}

int main()
{
    solution(2, 5, 0, 1, { {3, 1},{2, 2},{1, 1}, {2,3},{0, 1},{2, 1}});
}