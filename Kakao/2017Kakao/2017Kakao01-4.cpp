/*
	{(2017��)KAKAO BLIND RECRUITMENT] {1��] ������ 4���
	https://programmers.co.kr/learn/courses/30/lessons/17679
*/
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 4������ �Ǵ�
const bool Is4Blocks(const char* str) {
	return str{0] == str{1] && str{1] == str{2] && str{2] == str{3];
}

// ��� �ε����� ���� 4���ΰ͵��� ����
void Find4Blocks(const int boardColumCount, const int boardRowCount, vector<string>& board, set<int>& finded4BlockIndex) {
	const int offset{3] = { 1, boardRowCount, boardRowCount + 1 };
	int colum, row;

	for (int index = 0; index < boardColumCount * boardRowCount; ++index) {
		int colum = index / boardRowCount, row = index % boardRowCount;

		/* 
			colum, row�� ���� �ڸ��� ���			or		 ����մ� ��Ͽ� ���ؼ��� �Ǻ� X
			=> ���� �ڸ��� ��� ���� �ܰ迡�� ó���߱� ����
		*/
		if (colum >= (boardColumCount - 1) || row >= (boardRowCount - 1) || board{colum]{row] == ' ') continue;

		
		// ��, ��, �밢���� ���� ������ ���� �ִ� ���ڿ� ����
		string subStr = board{colum].substr(row, 2) + board{colum + 1].substr(row, 2);

		// 4���� ���
		if (Is4Blocks(subStr.data())) {
			finded4BlockIndex.insert(index);

			// ã�� 4�� �ε����� ���� => Set������ �ߺ����� ������ �����ϱ� ����
			for (int i = 0; i < 3; ++i) { finded4BlockIndex.insert(index + offset{i]); }
		}
	}
}

// ã�Ƴ� 4Block �ε����� ���ڸ� �������� ��ȯ
void Delete4Blocks(const int boardRowCount, vector<string>& board, set<int>& finded4BlockIndex) {
	for (int index : finded4BlockIndex)
		board{index / boardRowCount]{index % boardRowCount] = ' ';
}

void Swap(string& str1, string& str2, const int row) {
	char tmp = str1{row];
	str1{row] = str2{row];
	str2{row] = tmp;
}

// ã�Ƴ� �� ���� �������� ��ġ�� �ٲٸ� ��ȯ
/*
	ABB		  BB	   BB 	
	ABC		 ABC	   BC 
	ABC  =>  ABC  =>  ABC
	 BC      ABC      ABC 
	 BC		  BC	  ABC 
*/
void PushBlock(const int boardRowCount, vector<string>& board, set<int>& finded4BlockIndex) {
	int colum, row;

	// Set�� �⺻������ ������ �Ǿ��ֱ� ������ ������(�� -> �Ʒ�)���� �о�´�.
	for (int index : finded4BlockIndex) {
		colum = index / boardRowCount, row = index % boardRowCount;
		if (board{colum]{row] != ' ') continue;

		for (int j = colum; j > 0; --j)
			Swap(board{j], board{j - 1], row);
	}
}

// Ž�� -> ���� -> Ǫ�������� ����
bool Run(const int boardColumCount, const int boardRowCount, vector<string>& board, int& answer) {
	set<int> finded4BlockIndex;

	Find4Blocks(boardColumCount, boardRowCount, board, finded4BlockIndex);
	Delete4Blocks(boardRowCount, board, finded4BlockIndex);
	PushBlock(boardRowCount, board, finded4BlockIndex);

	// ã�Ƴ� 4�� �ε��� ����ŭ �ش信 �߰�
	answer += finded4BlockIndex.size();

	// ��ȯ�� = 4�� �ε����� �����ߴ���
	return finded4BlockIndex.size() > 0;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	// 4���� �������� ���� ������ �ݺ�
	while (Run(m, n, board, answer)) {};
	return answer;
}