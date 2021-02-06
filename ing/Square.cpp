#include <iostream>
#include <vector>
using namespace std;

enum Type{ Right, Down, Diagonal};
int solution(vector<vector<int>> board)
{
    int answer = 1;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 1) {

            }
        }
    }

    return answer;
}

int FindSquare(vector<vector<int>>& board, Type type, int distance, int i, int j) {
    if (board[i][j] == 0) return distance;

    switch (type) {
    case Right : 
        break;
    case Down :
        break;
    case Diagonal :
        break;
    }

}
int main() {
    vector<vector<int>> board = { 
        {0, 1, 1, 1}, 
        {1, 1, 1, 1}, 
        {1, 1, 1, 1}, 
        {0, 0, 1, 0} 
    };
    cout << solution(board);


}