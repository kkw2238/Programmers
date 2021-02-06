/* https://programmers.co.kr/learn/courses/30/lessons/72410 */

/*
	���̵��� ���̴� 3�� �̻� 15�� ���Ͽ��� �մϴ�.
	���̵�� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.) ���ڸ� ����� �� �ֽ��ϴ�.
	��, ��ħǥ(.)�� ó���� ���� ����� �� ������ ���� �������� ����� �� �����ϴ�.
*/

/*
	1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
	2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
	3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
	4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
	5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
	6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
		 ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
	7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 15;
const int MIN_SIZE = 3;

const bool IsWrongChar(const char c) {
	if (c >= 'a' && c <= 'z') return false;
	else if (c >= '0' && c <= '9') return false;
	else if (c == '-' || c == '_' || c == '.') return false;

	return true;
}

void CH1(string& new_id) {
	std::transform(new_id.begin(), new_id.end(), new_id.begin(), tolower);
}

void CH2(string& new_id) {
	auto iter = find_if(new_id.begin(), new_id.end(), IsWrongChar);
	
	while (iter != new_id.end()) {
		new_id.erase(iter);
		iter = find_if(iter, new_id.end(), IsWrongChar);
	}
}

void CH3(string& new_id) {
	int index = 0;
	while (index > -1) {
		index = new_id.find("..", index);
		if (index > -1) {
			new_id.replace(new_id.begin() + index, new_id.begin() + index + 2, ".");
		}
	}
}

void CH4(string& new_id) {
	if (new_id[0] == '.') new_id.erase(new_id.begin());
	if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.end() - 1);
}

void CH5(string& new_id) {
	if (new_id.empty()) {
		new_id = "a";
	}
}

void CH6(string& new_id) {
	if (new_id.length() > MAX_SIZE) {
		new_id.erase(new_id.begin() + MAX_SIZE, new_id.end());
	}

	CH3(new_id);
}

void CH7(string& new_id) {
	if (new_id.length() < MIN_SIZE) {
		for (int i = 0; i < MIN_SIZE - new_id.length();) {
			new_id.push_back(new_id[new_id.length() - 1]);
		}
	}
}

string solution(string new_id) {
	CH1(new_id);
	CH2(new_id);
	CH3(new_id);
	CH4(new_id);
	CH5(new_id);
	CH6(new_id);
	CH7(new_id);
	return new_id;
}

#include <iostream>

int main() {
	string new_id = "=.=";
	cout << solution(new_id);
}