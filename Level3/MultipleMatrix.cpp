/*
    https://programmers.co.kr/learn/courses/30/lessons/12942
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXIMUM = 201;

int memory[MAXIMUM][MAXIMUM];

int minimum(int start, int end, const vector<int>& d)
{
    int result = INT_MAX;
    int minimum = 0;

    for (int k = start; k < end; ++k)
    {
        int value = memory[start][k] + memory[k + 1][end];
        value += d[start - 1] * d[k] * d[end];

        if (result > value)
        {
            result = value;
            minimum = k;
        }
    }

    return result;
}

int mul(vector<int>& d)
{
    for (int i = 0; i < d.size(); ++i)
    {
        memory[i][i] = 0;
    }

    for (int diagonal = 1; diagonal < d.size(); ++diagonal)
    {
        for (int start = 1; start < d.size() - diagonal; ++start)
        {  
            int eleIndex = start + diagonal;
            memory[start][eleIndex] = minimum(start, eleIndex, d);
        }
    }

    return memory[1][d.size() - 1];
}

int solution(vector<vector<int>> matrix_sizes) 
{
    vector<int> d(matrix_sizes.size() + 1);
    d[0] = matrix_sizes[0][0];
    
    for (int i = 0; i < matrix_sizes.size(); ++i)
    {
        d[i + 1] = matrix_sizes[i][1];
    }

    return mul(d);
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
    
    solution({ {5, 3}, {3,10}, {10,6} });
}

/*
    



*/