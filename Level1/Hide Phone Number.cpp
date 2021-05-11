/*
	https://programmers.co.kr/learn/courses/30/lessons/12948
*/

#include <string>

using namespace std;

string solution(string phone_number) {
	return phone_number.replace(phone_number.begin(), phone_number.end() - 4, phone_number.length() - 4, '*');
}