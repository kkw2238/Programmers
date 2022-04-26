//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int solution(vector<int> stones, int k) {
//    int biggestCount = 200000001;
//
//    map<int, int> steppigCount; 
//
//    for (int i = 0; i < stones.size(); ++i)
//    {
//        ++steppigCount[stones[i]];
//
//        if (steppigCount.size() == k)
//        {
//            int allowSteppingCount = (*steppigCount.rbegin()).first;
//
//            if (biggestCount > allowSteppingCount)
//            {
//                biggestCount = allowSteppingCount;
//            }
//            
//            --steppigCount[stones[i - k + 1]];
//            if (steppigCount[stones[i - k + 1]] <= 0)
//            {
//                steppigCount.erase(stones[i - k + 1]);
//            }
//        }
//    }
//
//    return biggestCount;
//}


#include <string>
#include <vector>

using namespace std;

enum {START_X, START_Y, END_X, END_Y};
enum { NONE, INNER, OUTLINE };
const int SCALE = 2;

const bool IsOutline(const int x, const int y, const vector<int>& rectangle)
{
    return x == rectangle[START_X] * SCALE || x == rectangle[END_X] * SCALE 
        || y == rectangle[START_Y] * SCALE || y == rectangle[END_Y] * SCALE;
}

void DrawRectangle(vector<vector<int>>& board, const vector<int>& rectangle)
{
    for (int x = rectangle[START_X] * SCALE; x < rectangle[END_X] * SCALE; ++x)
    {
        for (int y = rectangle[START_Y] * SCALE; y < rectangle[END_Y] * SCALE; ++y)
        {
            if (IsOutline(x, y, rectangle) && board[y][x] == NONE)
            {
                board[y][x] = OUTLINE;
            }
            else
            {
                board[y][x] = INNER;
            }
        }
    }
}

int PathFind(vector<vector<int>>& board, int characterX, int characterY, int itemX, int itemY) {
    

}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> board(101, vector<int>(101, NONE));

    for (const vector<int>& rect : rectangle)
    {
        DrawRectangle(board, rect);
    }



    return answer;
}

//int main()
//{
//    solution({2, 4, 5, 3, 3, 2, 1, 4, 2, 5, 1}, 3);
//}