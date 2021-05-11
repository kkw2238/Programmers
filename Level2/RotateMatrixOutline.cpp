#include <vector>

using namespace std;

int RotationMatrix(vector<vector<int>>& matrix, pair<int, int> xMove, pair<int, int> yMove)
{
    int x = xMove.first - 1;
    int y = yMove.first - 1;

    int memNumber = matrix[y][x];
    int smallestNumber = 10001;

    for (x = x + 1; x < xMove.second; ++x)
    {
        if (smallestNumber > memNumber)
        {
            smallestNumber = memNumber;
        }
        int tmpNumber = matrix[y][x];
        matrix[y][x] = memNumber;
        memNumber = tmpNumber;
    }
    --x;
    for (++y; y < yMove.second; ++y)
    {
        if (smallestNumber > memNumber)
        {
            smallestNumber = memNumber;
        }
        int tmpNumber = matrix[y][x];
        matrix[y][x] = memNumber;
        memNumber = tmpNumber;
    }
    --y;

    for (--x; x >= xMove.first - 1; --x)
    {
        if (smallestNumber > memNumber)
        {
            smallestNumber = memNumber;
        }
        int tmpNumber = matrix[y][x];
        matrix[y][x] = memNumber;
        memNumber = tmpNumber;
    }
    ++x;

    for (--y; y >= yMove.first - 1; --y)
    {
        if (smallestNumber > memNumber)
        {
            smallestNumber = memNumber;
        }
        int tmpNumber = matrix[y][x];
        matrix[y][x] = memNumber;
        memNumber = tmpNumber;
    }
    return smallestNumber;
}

vector<vector<int>> Initialize(int rows, int columns)
{
    vector<vector<int>> result(rows, vector<int>(columns));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            result[i][j] = i * columns + j + 1;
        }
    }
    
    return result;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> boards = Initialize(rows, columns);
    vector<int> answer;
    
    for (const vector<int>& query : queries)
    {
        answer.emplace_back(RotationMatrix(boards, pair(query[1], query[3]), pair(query[0], query[2])));
    }
    
    return answer;
}

int main()
{
    int rows = 3;
    int columns = 3;
    vector<vector<int>> queries{ {1, 1, 2, 2}, {1, 2, 2, 3} ,{2, 1, 3, 2},{2, 2, 3, 3} };

    solution(rows, columns, queries);
}

