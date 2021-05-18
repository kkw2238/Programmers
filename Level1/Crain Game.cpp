/*
    https://programmers.co.kr/learn/courses/30/lessons/64061
*/

#include <string>
#include <vector>

using namespace std;

// 0이 제거된 전치행렬로 변환 => 인형 탐색 시간복잡도를 O(1)로 하기 위함
vector<vector<int>> TransposeBoard(vector<vector<int>>& board)
{
    vector<vector<int>> transposedBoard(board[0].size(), vector<int>());

    for (int x = board[0].size() - 1; x >= 0; --x)
    {
        for (int y = board.size() - 1; y >= 0; --y)
        {
            if (board[y][x] == 0)
            {
                break;
            }
            transposedBoard[x].emplace_back(board[y][x]);
        }
    }

    return transposedBoard;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<vector<int>> transposedBoard = TransposeBoard(board);
    vector<int> bucket;
    int answer = 0;

    for (const int move : moves)
    {
        // 해당 줄이 비었을 경우 continue
        if (transposedBoard[move - 1].empty())
        {
            continue;
        }

        // 맨 위에 있는 인형을 긁어온다.
        int doll = transposedBoard[move - 1].back();
        // 맨 위에 있는 인형을 제거
        transposedBoard[move - 1].pop_back();
        
        // 이번 인형이 바구니 속 맨 위 인형과 같은 종류일 경우 바구니속 인형을 삭제
        if (!bucket.empty() && bucket.back() == doll)
        {
            bucket.pop_back();
            ++answer;
        }
        // 그게 아닐 경우 바구니에 인형을 집어 넣는다.
        else
        {
            bucket.emplace_back(doll);
        }
    }

    // 삭제 시킨 횟수 * 2
    return answer * 2;
}

// 이전 코드
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> board, vector<int> moves) {
//	vector<int> basket;
//	int answer = 0;
//
//	for (int move : moves) {
//		int puppet = -1;
//
//		for (int i = 0; i < board.size(); ++i) {
//			if (board[i][move - 1] != 0) {
//				puppet = board[i][move - 1];
//				board[i][move - 1] = 0;
//				break;
//			}
//		}
//
//		if (puppet != -1) {
//			if (basket.size() > 0) {
//				if (basket[basket.size() - 1] == puppet) {
//					basket.erase(basket.end() - 1);
//					++answer;
//					continue;
//				}
//			}
//			basket.push_back(puppet);
//		}
//	}
//
//	return answer * 2;
//}