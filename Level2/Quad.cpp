/*
    https://programmers.co.kr/learn/courses/30/lessons/68936
*/

#include <vector>

using namespace std;

const int CHILD_COUNT = 4;
int oneCount = 0;
int zeroCount = 0;

class Quad
{
public:
    Quad() {};
    Quad(int size, int x, int y, const vector<vector<int>>& arr)
    {
        Quad quad[CHILD_COUNT];
        if (size == 1)
        {
            num = arr[x][y];
            return;
        }
        else
        {
            quad[0] = Quad(size / 2, x, y, arr);
            quad[1] = Quad(size / 2, x + size / 2, y, arr);
            quad[2] = Quad(size / 2, x, y + size / 2, arr);
            quad[3] = Quad(size / 2, x + size / 2, y + size / 2, arr);
        }

        int sum_of_children = quad[0].num + quad[1].num + quad[2].num + quad[3].num;
        if (sum_of_children == 0 || sum_of_children == 4)
        {
            num = quad[0].num;
        }
        else
        {
            for (int i = 0; i < CHILD_COUNT; ++i)
            {
                if (quad[i].num == 1)
                {
                    ++oneCount;
                }
                else if (quad[i].num == 0)
                {
                    ++zeroCount;
                }
            }
        }
    };

public:
    int num = -1;
};

vector<int> solution(vector<vector<int>> arr) {
    Quad quad(arr.size(), 0, 0, arr);

    return vector{ zeroCount, oneCount };
}

int main()
{
    solution({ {1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1} });
}

//#include <string>
//#include <vector>
//
//using namespace std;
//
//const bool Verify(const vector<vector<int>>& arr) {
//    int lastestNumver = arr[0][0];
//
//    for (int i = 0; i < arr.size(); ++i) {
//        for (int j = 0; j < arr.size(); ++j) {
//            if (lastestNumver != arr[i][j])
//                return false;
//        }
//    }
//
//    return true;
//}
//
//vector<int> DistributeQuad(vector<vector<int>>& arr) {
//    vector<int> result = { 0, 0 };
//    vector<vector<int>> container(arr.size() / 2);
//
//    if (Verify(arr)) {
//        ++result[arr[0][0]];
//        return result;
//    }
//
//    for (int i = 0; i < 4; ++i) {
//        int index = 0;
//        container = vector<vector<int>>(arr.size() / 2);
//
//        for (int colum = (arr.size() / 2) * (i / 2); colum < arr.size() / 2 * ((i / 2) + 1); ++colum) {
//            for (int row = arr[0].size() / 2 * (i % 2); row < arr[0].size() / 2 * ((i % 2) + 1); ++row) {
//                container[index].push_back(arr[colum][row]);
//            }
//            ++index;
//        }
//
//        if (!Verify(container)) {
//            vector<int> v = DistributeQuad(container);
//            result[0] += v[0];
//            result[1] += v[1];
//        }
//        else {
//            ++result[container[0][0]];
//        }
//    }
//
//    return result;
//}
//
//vector<int> solution(vector<vector<int>> arr) {
//    return DistributeQuad(arr);
//}
//
//#include <iostream>
//int main() {
//    vector<vector<int>> arr = {
//        {1, 1, 1, 1, 1, 1, 1, 1}, 
//        {1, 1, 1, 1, 1, 1, 1, 1}, 
//        {1, 1, 1, 1, 1, 1, 1, 1}, 
//        {1, 1, 1, 1, 1, 1, 1, 1}, 
//        {1, 1, 1, 1, 1, 1, 1, 1}, 
//        {1, 1, 1, 1, 1, 1, 1, 1}, 
//        {1, 1, 1, 1, 1, 1, 1, 1}, 
//        {1, 1, 1, 1, 1, 1, 1, 1}
//    };
//
//    vector<int> a = solution(arr);
//    cout << a[0] << '\t' << a[1];
//}