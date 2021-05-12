/* https://programmers.co.kr/learn/courses/30/lessons/72410 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 15;
const int MIN_SIZE = 3;

// a ~ z / 0 ~ 9 / - _ .를 제외한 문자열 판단
const bool IsWrongChar(const char c) {
	if (c >= 'a' && c <= 'z') 
	{
		return false;
	}
	else if (c >= '0' && c <= '9') 
	{
		return false;
	}
	else if (c == '-' || c == '_' || c == '.') 
	{
		return false;
	}

	return true;
}

void CH1(string& new_id) {
	// 모든 대문자를 소문자로 치환
	std::transform(new_id.begin(), new_id.end(), new_id.begin(), tolower);
}

void CH2(string& new_id) {

	auto iter = find_if(new_id.begin(), new_id.end(), IsWrongChar);
	// 잘못된 문자열을 제거
	while (iter != new_id.end()) {
		new_id.erase(iter);
		iter = find_if(iter, new_id.end(), IsWrongChar);
	}
}

void CH3(string& new_id) {
	int index = 0;
	while (index > -1) {
		// ".."의 위치 탐색
		index = new_id.find("..", index);
		if (index > -1) 
		{
			// ... 의 경우 첫 단계를 거쳐 ..로 변환 후 다음 차례에 .로 변환
			new_id.replace(new_id.begin() + index, new_id.begin() + index + 2, ".");
		}
	}
}

void CH4(string& new_id) {
	if (new_id[0] == '.') 
	{
		// 문자열의 시작이 '.'일 경우 삭제
		new_id.erase(new_id.begin());
	}
	if (new_id[new_id.length() - 1] == '.') 
	{
		// 문자열의 끝이 '.'인 경우 삭제
		new_id.erase(new_id.end() - 1);
	}
}

void CH5(string& new_id) {
	if (new_id.empty()) 
	{
		// 빈 문자열일 경우 "a" 추가
		new_id = "a";
	}
}

void CH6(string& new_id) {
	// 문자열이 16자 이상인 경우 뒷 부분을 제거
	if (new_id.length() > MAX_SIZE) {
		
		new_id.erase(new_id.begin() + MAX_SIZE, new_id.end());
	}

	CH4(new_id);
}

void CH7(string& new_id) {
	// 문자열의 길이가 2이하인 경우 마지막 문자를 추가
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