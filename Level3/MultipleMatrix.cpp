/*
    https://programmers.co.kr/learn/courses/30/lessons/12942
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXIMUM = 201;

int memory[MAXIMUM][MAXIMUM];

int minimum(int start, int mid, int end, const vector<int>& d)
{
    int result = INT_MAX;

    return 0;
}

int mul(vector<int>& d)
{
    for (int i = 0; i < d.size(); ++i)
    {
        memory[i][i] = 0;
    }

    for (int start = 1; start < d.size(); ++start)
    {
        for (int mid = 1; mid < d.size() - start + 1; ++mid)
        {  
            int end = start + mid;
            memory[start][end] = minimum(start, mid, end, d);
        }
    }

    return 0;
}

int solution(vector<vector<int>> matrix_sizes) 
{
    vector<int> d(matrix_sizes.size() + 1);
    d[0] = matrix_sizes[0][0];
    
    for (int i = 0; i < matrix_sizes.size(); ++i)
    {
        d[i + 1] = matrix_sizes[i][1];
    }
    
    return 0;
}

//
//
//const int MAXINT = 2147483647;
//
//const int getMulCount(const vector<int>& a, const vector<int>& b)
//{
//    return a[0] * a[1] * b[1];
//}
//
//int solution(vector<vector<int>> matrix_sizes) {
//    int answer = MAXINT;
//    int count = 0;
//    vector<int> permutationData;
//
//    for (int i = 0; i < matrix_sizes.size() - 1; ++i)
//    {
//        permutationData.push_back(i);
//    }
//
//    do {
//        vector<vector<int>> tmpMatrix_sizes = matrix_sizes;
//        int tmpResult = 0;
//        for (int i = 0; i < permutationData.size(); ++i)
//        {
//            int index = permutationData[i];
//
//            tmpResult += getMulCount(tmpMatrix_sizes[index], tmpMatrix_sizes[index + 1]);
//
//            if (tmpResult > answer)
//            {
//                break;
//            }
//
//            tmpMatrix_sizes[index] = { tmpMatrix_sizes[index][0], tmpMatrix_sizes[index + 1][1] };
//            tmpMatrix_sizes[index + 1] = { tmpMatrix_sizes[index][0], tmpMatrix_sizes[index + 1][1] };
//        }
//
//        answer = min(tmpResult, answer);
//    } while (next_permutation(permutationData.begin(), permutationData.end()));
//
//    return answer;
//}

int main()
{
    
    solution({ {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6}, {5, 3}, {3,10}, {10,6} });
}

/*
    



*/