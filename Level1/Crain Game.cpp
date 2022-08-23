/*
    https://programmers.co.kr/learn/courses/30/lessons/64061
*/

#include <string>
#include <vector>

using namespace std;

// 0�� ���ŵ� ��ġ��ķ� ��ȯ => ���� Ž�� �ð����⵵�� O(1)�� �ϱ� ����
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
        // �ش� ���� ����� ��� continue
        if (transposedBoard[move - 1].empty())
        {
            continue;
        }

        // �� ���� �ִ� ������ �ܾ�´�.
        int doll = transposedBoard[move - 1].back();
        // �� ���� �ִ� ������ ����
        transposedBoard[move - 1].pop_back();
        
        // �̹� ������ �ٱ��� �� �� �� ������ ���� ������ ��� �ٱ��ϼ� ������ ����
        if (!bucket.empty() && bucket.back() == doll)
        {
            bucket.pop_back();
            ++answer;
        }
        // �װ� �ƴ� ��� �ٱ��Ͽ� ������ ���� �ִ´�.
        else
        {
            bucket.emplace_back(doll);
        }
    }

    // ���� ��Ų Ƚ�� * 2
    return answer * 2;
}

// ���� �ڵ�
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