/*
	{(2017년)KAKAO BLIND RECRUITMENT] {1차] 프렌즈 4블록
	https://programmers.co.kr/learn/courses/30/lessons/17679
*/
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 4블럭인지 판단
const bool Is4Blocks(const char* str) {
	return str{0] == str{1] && str{1] == str{2] && str{2] == str{3];
}

// 모든 인덱스를 돌며 4블럭인것들을 조사
void Find4Blocks(const int boardColumCount, const int boardRowCount, vector<string>& board, set<int>& finded4BlockIndex) {
	const int offset{3] = { 1, boardRowCount, boardRowCount + 1 };
	int colum, row;

	for (int index = 0; index < boardColumCount * boardRowCount; ++index) {
		int colum = index / boardRowCount, row = index % boardRowCount;

		/* 
			colum, row가 가장 자리인 경우			or		 비어잇는 블록에 대해서는 판별 X
			=> 가장 자리의 경우 직전 단계에서 처리했기 때문
		*/
		if (colum >= (boardColumCount - 1) || row >= (boardRowCount - 1) || board{colum]{row] == ' ') continue;

		
		// 좌, 하, 대각선의 블럭의 정보를 갖고 있는 문자열 생성
		string subStr = board{colum].substr(row, 2) + board{colum + 1].substr(row, 2);

		// 4블럭인 경우
		if (Is4Blocks(subStr.data())) {
			finded4BlockIndex.insert(index);

			// 찾은 4블럭 인덱스에 삽입 => Set쓴이유 중복으로 삽입을 방지하기 위해
			for (int i = 0; i < 3; ++i) { finded4BlockIndex.insert(index + offset{i]); }
		}
	}
}

// 찾아낸 4Block 인덱스의 문자를 공백으로 변환
void Delete4Blocks(const int boardRowCount, vector<string>& board, set<int>& finded4BlockIndex) {
	for (int index : finded4BlockIndex)
		board{index / boardRowCount]{index % boardRowCount] = ' ';
}

void Swap(string& str1, string& str2, const int row) {
	char tmp = str1{row];
	str1{row] = str2{row];
	str2{row] = tmp;
}

// 찾아낸 블럭 기준 위로으로 위치를 바꾸며 순환
/*
	ABB		  BB	   BB 	
	ABC		 ABC	   BC 
	ABC  =>  ABC  =>  ABC
	 BC      ABC      ABC 
	 BC		  BC	  ABC 
*/
void PushBlock(const int boardRowCount, vector<string>& board, set<int>& finded4BlockIndex) {
	int colum, row;

	// Set은 기본적으로 정렬이 되어있기 때문에 순차적(위 -> 아래)으로 읽어온다.
	for (int index : finded4BlockIndex) {
		colum = index / boardRowCount, row = index % boardRowCount;
		if (board{colum]{row] != ' ') continue;

		for (int j = colum; j > 0; --j)
			Swap(board{j], board{j - 1], row);
	}
}

// 탐색 -> 삭제 -> 푸쉬순으로 진행
bool Run(const int boardColumCount, const int boardRowCount, vector<string>& board, int& answer) {
	set<int> finded4BlockIndex;

	Find4Blocks(boardColumCount, boardRowCount, board, finded4BlockIndex);
	Delete4Blocks(boardRowCount, board, finded4BlockIndex);
	PushBlock(boardRowCount, board, finded4BlockIndex);

	// 찾아낸 4블럭 인덱스 수만큼 해답에 추가
	answer += finded4BlockIndex.size();

	// 반환값 = 4블럭 인덱스가 존재했는지
	return finded4BlockIndex.size() > 0;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	// 4블럭이 존재하지 않을 때까지 반복
	while (Run(m, n, board, answer)) {};
	return answer;
}