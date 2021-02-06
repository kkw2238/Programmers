/*
	https://programmers.co.kr/learn/courses/30/lessons/17687
*/

#include <string>
#include <array>

using namespace std;

const int Max_N = 16;
const array<char, Max_N> Line_Up = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

string Make_Number(int number, const int n) {
	string result = "";

	while (number / n != 0) {
		result.insert(result.begin(), Line_Up[number % n]);
		number /= n;
	}

	result.insert(result.begin(), Line_Up[number % n]);
	return result;
}

string solution(int n, int t, int m, int p) {
	string answer = "", tmpanswer = "";
	for (int i = 0; i < t * m; ++i) {
		tmpanswer.append(Make_Number(i, n));
		if (tmpanswer.length() > t* m)
			break;
	}
	for (int i = 0; i < t; ++i) {
		answer += tmpanswer[i * m + p - 1];
	}

	return answer;
}
