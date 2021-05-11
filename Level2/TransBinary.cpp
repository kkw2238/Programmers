/* https://programmers.co.kr/learn/courses/30/lessons/70129?language=cpp */
/*
0�� 1�� �̷���� � ���ڿ� x�� ���� ���� ��ȯ�� ������ ���� �����մϴ�.

1. x�� ��� 0�� �����մϴ�.
2. x�� ���̸� c��� �ϸ�, x�� c�� 2�������� ǥ���� ���ڿ��� �ٲߴϴ�.
	���� ���, x = "0111010"�̶��, x�� ���� ��ȯ�� ���ϸ� x = "0111010" -> "1111" -> "100" �� �˴ϴ�.

0�� 1�� �̷���� ���ڿ� s�� �Ű������� �־����ϴ�.s�� 1�� �� ������ ����ؼ� s�� ���� ��ȯ�� ������ ��, 
���� ��ȯ�� Ƚ���� ��ȯ �������� ���ŵ� ��� 0�� ������ ���� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int DeletedZero(string& s) {
	int zeroCount = 0;
	s.erase(remove_if(s.begin(), s.end(), [&zeroCount](const char c) {
		if (c != '0') return false;
		
		++zeroCount;
		return true;
	}), s.end());

	return zeroCount;
}

string TransLengthBinary(const string& s) {
	string result = bitset<32>(s.length()).to_string();
	
	return result.substr(result.find('1'));
}

#include <iostream>
vector<int> solution(string s) {
	vector<int> answer(2);

	while (s.compare("1") != 0) {
		++answer[0];
		answer[1] += DeletedZero(s);
		s = TransLengthBinary(s);
	}

	return answer;
}


int main() {
	string s = "110010101001";
	
	solution(s);
}