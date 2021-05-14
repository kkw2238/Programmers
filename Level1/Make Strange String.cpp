/*
	https://programmers.co.kr/learn/courses/30/lessons/12930
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	int index = 0;

	for (char& c : s) 
	{
		// ���� ������ index�� �ʱ�ȭ
		if (c == ' ') 
		{
			index = 0;
			continue;
		}
		
		// �� ���ڿ��� Ȧ����° ���ڴ� �빮�ڷ� ��ȯ 
		if (index % 2 == 0)
		{
			c = toupper(c);
		}
		// �� ���� ��� �ҹ��ڷ� ��ȯ
		else
		{
			c = tolower(c);
		}

		++index;
	}

	return s;
}