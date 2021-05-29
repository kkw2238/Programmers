/*
    https://programmers.co.kr/learn/courses/30/lessons/68936
*/

#include <vector>

using namespace std;

const int CHILD_COUNT = 4;
vector<int> numCount{ 0, 0 };

void AddCount(const vector<int>& nums)
{
    for (const int num : nums)
    {
         ++numCount[num];
    }
}

int Quad(int size, int x, int y, const vector<vector<int>>& arr)
{
    // 최소 사이즈인 경우 현재 위치 반환
    if (size == 1)
    {
        return arr[y][x];
    }

    // 다음 시작 위치
    const int NEXT_XPOS[CHILD_COUNT] = { x, x + size / (CHILD_COUNT / 2), x, x + size / (CHILD_COUNT / 2) };
    const int NEXT_YPOS[CHILD_COUNT] = { y, y, y + size / (CHILD_COUNT / 2), y + size / (CHILD_COUNT / 2) };
    
    vector<int> children;
    int sum_of_children = 0;
    
    for (int i = 0; i < CHILD_COUNT; ++i)
    {
        int child = Quad(size / (CHILD_COUNT / 2), NEXT_XPOS[i], NEXT_YPOS[i], arr);
        
        // child가 합쳐져있는 경우( 0, 1값을 갖고 있는 경우 )
        if (child != -1)
        {
            // children에 삽입한다
            children.emplace_back(child);
            sum_of_children += child;
        }
    }

    // 자식이 합쳐진 원소로만 이루어져 있고, 동일한 숫자 4개로 이루어진 경우
    if (!children.size() == CHILD_COUNT && sum_of_children == children.front() * CHILD_COUNT)
    {
        // 압축
        return children[0];
    }
    else
    {
        // 아닐 경우 0과 1의 개수를 더해줌
        AddCount(children);

        // 압축이 이루어지지 않은 경우 -1 반환
        return -1;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    int num = Quad(arr.size(), 0, 0, arr);
    
    // 모든 숫자가 한가지 숫자로만 이루어져 있는 경우 판단
    if (num != -1)
    {
        ++numCount[num];
    }

    return numCount;
}
/*

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
*/
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