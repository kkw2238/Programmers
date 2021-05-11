#include "../../Util.h"

/*
	어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

	예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다.

	이 중 가장 큰 숫자는 94 입니다.

	문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다.

	number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

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