using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	vector<int> basket;
	int answer = 0;

	for (int move : moves) {
		int puppet = -1;

		for (int i = 0; i < board.size(); ++i) {
			if (board[i][move - 1] != 0) {
				puppet = board[i][move - 1];
				board[i][move - 1] = 0;
				break;
			}
		}

		if (puppet != -1) {
			if (basket.size() > 0) {
				if (basket[basket.size() - 1] == puppet) {
					basket.erase(basket.end() - 1);
					++answer;
					continue;
				}
			}
			basket.push_back(puppet);
		}
	}

	return answer * 2;
}
