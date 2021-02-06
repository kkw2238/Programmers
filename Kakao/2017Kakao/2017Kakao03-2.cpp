/*
	{(2017��)KAKAO BLIND RECRUITMENT] {3��] �ڵ��ϼ�
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
		// ������ ���ڿ��� ������ 1���� ��� 
		if (datas.size() == 1) {
			count += tier + 1;
			return;
		}

		// tier�� ���� ������ ���ڿ��� ���� �ܰ迡�� �ϼ��Ǵ� ���ڿ��̱⿡ ������ ���� �Ѵ�. 
		sort(datas.begin(), datas.end(), {](string& a, string& b) { return a.length() < b.length(); });
		auto shorterThanTier = find_if(datas.begin(), datas.end(), {&tier](string& a) { return a.length() > tier; });
		if (shorterThanTier != datas.begin()) {
			// tier�� ���� ������ ���ڿ��� ���������� ���� �ܰ迡�� �ǵ��Ǳ� ������ -1 �����ش�.
			count += (-1 * distance(datas.begin(), shorterThanTier));
		}


		// ���ڿ� ������� ���� 
		sort(datas.begin(), datas.end(), {&tier](string& a, string& b) { return a{tier] < b{tier]; });

		for (auto iter = datas.begin(); iter != datas.end();) {
			auto tmpiter = iter;
			char levelCharacter = (*iter){tier];

			// tier��° index�� ���ڰ� �ٸ� ���ڿ����� Ž��
			iter = find_if(iter, datas.end(), {&levelCharacter, &tier](string& a) { return a{tier] != levelCharacter; });

			// tier��° index�� ���ڰ� ������ ���ڿ����� ����
			vector<string> filteredDatas(tmpiter, iter);

			if (filteredDatas.size() > 1)
				mNodes{levelCharacter] = Node(filteredDatas, tier + 1, count);

			// tier��° ���ڰ� ������ ���ڿ��� 1���� ��� ���� tier���� ����
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