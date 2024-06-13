/*
	https://programmers.co.kr/learn/courses/30/lessons/77485
*/

#include <vector>

using namespace std;

enum { Y_START, X_START, Y_END, X_END};

int RotateBoard(vector<vector<int>>& board, const vector<int>& query)
{
    int minimumNumber = board[query[Y_START] - 1][query[X_START] - 1];
    int memNum = minimumNumber;

    for (int x = query[X_START] - 1; x <= query[X_END] - 1; ++x)
    {
        minimumNumber = min(minimumNumber, board[query[Y_START] - 1][x]);
        swap(board[query[Y_START] - 1][x], memNum);
    }

    for (int y = query[Y_START]; y <= query[Y_END] - 1; ++y)
    {
        minimumNumber = min(minimumNumber, board[y][query[X_END] - 1]);
        swap(board[y][query[X_END] - 1], memNum);
    }

    for (int x = query[X_END] - 2; x >= query[X_START] - 1; --x)
    {
        minimumNumber = min(minimumNumber, board[query[Y_END] - 1][x]);
        swap(board[query[Y_END] - 1][x], memNum);
    }

    for (int y = query[Y_END] - 2; y >= query[Y_START] - 1; --y)
    {
        minimumNumber = min(minimumNumber, board[y][query[X_START] - 1]);
        swap(board[y][query[X_START] - 1], memNum);
    }

    return minimumNumber;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int>(columns, 0));

    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < columns; ++x)
        {
            board[y][x] = (y * columns) + (x + 1);
        }
    }

    for (const vector<int>& query : queries)
    {
        answer.emplace_back(RotateBoard(board, query));
    }
      
    return answer;
}

//#include <vector>
//
//using namespace std;
//
//int RotationMatrix(vector<vector<int>>& matrix, pair<int, int> xMove, pair<int, int> yMove)
//{
//    int x = xMove.first - 1;
//    int y = yMove.first - 1;
//
//    int memNumber = matrix[y][x];
//    int smallestNumber = 10001;
//
//    for (x = x + 1; x < xMove.second; ++x)
//    {
//        if (smallestNumber > memNumber)
//        {
//            smallestNumber = memNumber;
//        }
//        int tmpNumber = matrix[y][x];
//        matrix[y][x] = memNumber;
//        memNumber = tmpNumber;
//    }
//    --x;
//    for (++y; y < yMove.second; ++y)
//    {
//        if (smallestNumber > memNumber)
//        {
//            smallestNumber = memNumber;
//        }
//        int tmpNumber = matrix[y][x];
//        matrix[y][x] = memNumber;
//        memNumber = tmpNumber;
//    }
//    --y;
//
//    for (--x; x >= xMove.first - 1; --x)
//    {
//        if (smallestNumber > memNumber)
//        {
//            smallestNumber = memNumber;
//        }
//        int tmpNumber = matrix[y][x];
//        matrix[y][x] = memNumber;
//        memNumber = tmpNumber;
//    }
//    ++x;
//
//    for (--y; y >= yMove.first - 1; --y)
//    {
//        if (smallestNumber > memNumber)
//        {
//            smallestNumber = memNumber;
//        }
//        int tmpNumber = matrix[y][x];
//        matrix[y][x] = memNumber;
//        memNumber = tmpNumber;
//    }
//    return smallestNumber;
//}
//
//vector<vector<int>> Initialize(int rows, int columns)
//{
//    vector<vector<int>> result(rows, vector<int>(columns));
//
//    for (int i = 0; i < rows; ++i)
//    {
//        for (int j = 0; j < columns; ++j)
//        {
//            result[i][j] = i * columns + j + 1;
//        }
//    }
//    
//    return result;
//}
//
//vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
//    vector<vector<int>> boards = Initialize(rows, columns);
//    vector<int> answer;
//    
//    for (const vector<int>& query : queries)
//    {
//        answer.emplace_back(RotationMatrix(boards, pair(query[1], query[3]), pair(query[0], query[2])));
//    }
//    
//    return answer;
//}
