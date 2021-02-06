/*
	{(2017��)KAKAO BLIND RECRUITMENT] {1��] �������
	https://programmers.co.kr/learn/courses/30/lessons/17681
*/
#include <string>
#include <vector>

using namespace std;

// ������ ������ ���Ͽ� string������ ��ȯ
string GetMapLine(int n, int mapLine1, int mapLine2) {
	string result = "";
	//        ' '�� '#'������ ���̰� 3
	const int Void = ' ', Offset = 3;

	// or ��Ʈ �������� �� ��� => �� ���ϳ��� ��(1)�� ��� 1, �� �� �����(0)�� ��� 0
	int getLine = mapLine1 | mapLine2;

	for (int i = 0; i < n; ++i) {
		// getLine % 2�� ������ ��Ʈ�� �Ǻ� -> Void + �Ǻ� * offset���� ' ' or '#'�� ���� 
		result = static_cast<char>(Void + (getLine % 2 * Offset)) + result;

		// ��Ʈ�� 1ĭ ���������� �̵�
		getLine = getLine >> 1;
	}

	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> result;
	for (int i = 0; i < n; ++i) result.push_back(GetMapLine(n, arr1{i], arr2{i]));

	return result;
}