/*
	{(2017년)KAKAO BLIND RECRUITMENT] {1차] 비밀지도
	https://programmers.co.kr/learn/courses/30/lessons/17681
*/
#include <string>
#include <vector>

using namespace std;

// 지도의 라인을 비교하여 string값으로 반환
string GetMapLine(int n, int mapLine1, int mapLine2) {
	string result = "";
	//        ' '과 '#'사이의 차이가 3
	const int Void = ' ', Offset = 3;

	// or 비트 연산으로 값 계산 => 둘 중하나라도 벽(1)인 경우 1, 둘 다 빈공간(0)인 경우 0
	int getLine = mapLine1 | mapLine2;

	for (int i = 0; i < n; ++i) {
		// getLine % 2로 마지막 비트를 판별 -> Void + 판별 * offset으로 ' ' or '#'을 삽입 
		result = static_cast<char>(Void + (getLine % 2 * Offset)) + result;

		// 비트를 1칸 오른쪽으로 이동
		getLine = getLine >> 1;
	}

	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> result;
	for (int i = 0; i < n; ++i) result.push_back(GetMapLine(n, arr1{i], arr2{i]));

	return result;
}