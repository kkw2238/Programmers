#include "../../Util.h"

/*
	� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

	���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�.

	�� �� ���� ū ���ڴ� 94 �Դϴ�.

	���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�.

	number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

/*
string RefineNumber(set<char, greater<char>>& parts, string& number, int& k) {
	int index = 0;
	auto iter = parts.begin();
	
	while (iter != parts.end()) {
		index = number.find(*iter);
		if (index == -1)
			parts.erase(iter);

		while (index != -1) {
			if (number.length() - k >= index && index <= k) {
				number.erase(number.begin(), number.begin() + index);
				k -= index;
				return number;
			}
			index = number.find(*iter, index + 1);
		}
		++iter;
	}

	return number;
}

string solution(string number, int k) {
	const int WANT_SIZE = number.size() - k;
	
	return string(number.begin(), number.begin() + k);
	string result = "";
	set<char, greater<char>> parts(number.begin(), number.end());
	
	if (parts.size() == 1)
		return string(WANT_SIZE, number[0]);

	while (k != 0) {
		RefineNumber(parts, number, k);
		result = result + number[0];
		number.erase(0, 1);
	}

	return result + number;
}
*/

#include <map>

void EraseCharInDictionary(map<char, int>& dictionary, string s) {
	for (const char c : s) {
		--dictionary[c];
		if (dictionary[c] == 0)
			dictionary.erase(c);
	}
}

string RefineNumber(map<char, int>& dictionary, string& number, int& k) {
	int index = 0;
	auto iter = --dictionary.end();

	while (iter != dictionary.begin()) {
		index = number.find((*iter).first);

		while (index != -1) {
			if (number.length() - k >= index && index <= k) {
				EraseCharInDictionary(dictionary, string(number.begin(), number.begin() + index));
				number.erase(number.begin(), number.begin() + index);
				k -= index;
				return number;
			}
			index = number.find((*iter).first, index + 1);
		}
		--iter;
	}

	return number;
}

string solution(string number, int k) {
	map<char, int> dictionary;
	for (const char c : number)
		++dictionary[c];

	RefineNumber(dictionary, number, k);
	
	int index = 0;
	while (k != 0) {
		index = number.find((*dictionary.begin()).first, index);
		number.erase(index, 1);
		--(*dictionary.begin()).second;
		--k;

		if ((*dictionary.begin()).second == 0) {
			dictionary.erase(dictionary.begin());
			index = 0;
		}
	}

	return number;
}

int main() {
	string number = "4177252841";
	int k = 4;
	// 1924 19  9 2 4 
	cout << solution(number, k);
}

// 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000123456789