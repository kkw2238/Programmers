///*
//    https://programmers.co.kr/learn/courses/30/lessons/87391?language=cpp
//*/
//
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
//
//int main()
//{
//    solution(2, 5, 0, 1, { {3, 1},{2, 2},{1, 1},{2, 3},{0, 1},{2, 1} });
//}