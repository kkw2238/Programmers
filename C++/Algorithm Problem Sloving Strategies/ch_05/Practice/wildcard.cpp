#include <vector>
#include <string>

using namespace std;

const bool isMatch(const char wildChar, const char targetChar)
{
	return wildChar == '?' || wildChar == targetChar;
}

bool isComapre(string wildCard, string target)
{
	int cIndex = 0, targetIndex = 0;

	while (cIndex < wildCard.length() && targetIndex < target.length())
	{
		if (wildCard[cIndex] == '*')
		{
			if ((cIndex + 1) == wildCard.length())
			{
				return true;
			}
			if (isMatch(wildCard[cIndex + 1], target[targetIndex]))
			{
				if (isComapre(wildCard.substr(cIndex + 1), target.substr(targetIndex)))
				{
					return true;
				}
			}
		}
		else if (isMatch(wildCard[cIndex], target[targetIndex]))
		{
			++cIndex;
		}
		else 
		{
			return false;
		}
		++targetIndex;
	}

	return (cIndex == wildCard.length() 
		|| (cIndex == (wildCard.length() -1)) && wildCard[cIndex] == '*') 
		&& targetIndex == target.length();
}

vector<string> solution(string wildCard, vector<string> str)
{
	vector<string> result;
	/* 	
	1. * = �ƹ� ���� <=> ? = �ƹ� ���� 1���� ==> 

	2. *�� ���� ��� ���� ���ڿ� ������ ���� ���� �� ���� Ȯ��

	3. ������ ���� ���°�� 
		�ش� �������� �ڸ� �� ���� �κ��� �Ǵ�

	4. �������� ���� ���
		����ؼ� ���� ����
	*/

	for (int i = 0; i < str.size(); ++i)
	{
		if (isComapre(wildCard, str[i]))
		{
			result.push_back(str[i]);
		}
	}	
	return result;
}

int main()
{
	solution("*p*", { "hello"});
	solution("*bb*", { "babbc" });
	solution("he?p", { "help", "heap", "helpp" });
}