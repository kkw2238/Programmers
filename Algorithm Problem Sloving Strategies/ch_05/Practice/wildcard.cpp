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
	1. * = 아무 문장 <=> ? = 아무 글자 1개만 ==> 

	2. *이 나온 경우 다음 문자와 동일한 것이 나올 떄 까지 확인

	3. 동일한 것이 나온경우 
		해당 기점으로 자른 뒤 다음 부분을 판단

	4. 동일하지 않은 경우
		계속해서 누적 저장
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