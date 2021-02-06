/*
	{(2017년)KAKAO BLIND RECRUITMENT] {3차] 자동완성
	https://programmers.co.kr/learn/courses/30/lessons/17685
*/
#include "Util.h"
using namespace std;

class Node {
public:
	Node() = default;
	Node(vector<string>& iniDatas, int iniTier, int& iniCount) {
		InitializeNode(iniDatas, iniTier, iniCount);
	}
	~Node() = default;

public:
	void InitializeNode(vector<string>& datas, int tier, int& count) {
		// 내려온 문자열의 개수가 1개인 경우 
		if (datas.size() == 1) {
			count += tier + 1;
			return;
		}

		// tier와 같은 길이의 문자열은 현재 단계에서 완성되는 문자열이기에 구별해 내야 한다. 
		sort(datas.begin(), datas.end(), {](string& a, string& b) { return a.length() < b.length(); });
		auto shorterThanTier = find_if(datas.begin(), datas.end(), {&tier](string& a) { return a.length() > tier; });
		if (shorterThanTier != datas.begin()) {
			// tier와 같은 길이의 문자열도 최종적으로 다음 단계에서 판독되기 때문에 -1 시켜준다.
			count += (-1 * distance(datas.begin(), shorterThanTier));
		}


		// 문자열 순서대로 정렬 
		sort(datas.begin(), datas.end(), {&tier](string& a, string& b) { return a{tier] < b{tier]; });

		for (auto iter = datas.begin(); iter != datas.end();) {
			auto tmpiter = iter;
			char levelCharacter = (*iter){tier];

			// tier번째 index의 문자가 다른 문자열까지 탐색
			iter = find_if(iter, datas.end(), {&levelCharacter, &tier](string& a) { return a{tier] != levelCharacter; });

			// tier번째 index의 문자가 동일한 문자열끼리 구분
			vector<string> filteredDatas(tmpiter, iter);

			if (filteredDatas.size() > 1)
				mNodes{levelCharacter] = Node(filteredDatas, tier + 1, count);

			// tier번째 문자가 동일한 문자열이 1개인 경우 현재 tier에서 정리
			else
				count += (tier + 1);
		}
	}

public:
	map<char, Node> mNodes;
};

int solution(vector<string> words) {
	int answer = 0;
	Node(words, 0, answer);

	return answer;
}