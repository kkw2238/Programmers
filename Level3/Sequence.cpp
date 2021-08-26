/*
	� ���� x�� �κ� ����(Subsequence)�̶�, 
	x�� ��� ���ҵ��� �����ϰų� �׷��� �ʰ� ���� ���ҵ��� ���� ������ �����Ͽ� ���� �� �ִ� ���ο� ������ ���մϴ�.

	���� ���, [1,3]�� [1,2,3,4,5]�� �κм����Դϴ�. ���� �������� 2, 4, 5�� �����ؼ� ���� �� �ֱ� �����Դϴ�.
	������ ���� ������ ��� �����ϴ� ���� x�� ��Ÿ �����̶�� �����մϴ�.
*/

/*
*	�ذ��ؾ� �� ����
		1. �κ� ����
			=> ������ ���� �ž��ϴ� ����
			=> 10���� ���Ұ� ���� ��� 10 9 8 7 6 5 4 3 2 1���� ���� ����
				-> �ִ� ���� 50���� ���� ���� -> �ð��ʰ� ���ɼ� 
			=> i = 1 ~ n

		2. ��Ÿ ����
			=> O
			=> �ּҰ� 2 

		3. ��Ÿ������ ���� ���̽� X 
*/

#include <string>
#include <vector>

using namespace std;

int longgestLength = 0;

bool HasIntersection(pair<int, int>& setA, const int setBA, const int setBB)
{
	if (setA.first >= 0 && setA.first != setBA && setA.first != setBB)
	{
		setA.first = -1;
	}
	if (setA.second >= 0 && setA.second != setBA && setA.second != setBB)
	{
		setA.second = -1;
	}
	return setA.first + setA.second == -2;
}

bool IsStarSequence(const vector<int>& sequence)
{
	pair setA{ sequence[0], sequence[1] };
	for (int i = 0; i < sequence.size() / 2; ++i)
	{
		if (HasIntersection(setA, sequence[i * 2], sequence[i * 2 + 1]))
		{
			return false;
		}

		if (sequence[i * 2] == sequence[i * 2 + 1])
		{
			return false;
		}
	}

	return true;
}

int MakeSubSequence(const vector<int>& a, vector<int> subSeqence, const int beforenumber, const int nowIndex)
{
	if (a.size() - (nowIndex + subSeqence.size()) < longgestLength)
	{
		return 0;
	}

	int starSequenceLength = 0;
	if (beforenumber != -1)
	{
		subSeqence.emplace_back(beforenumber);
	}

	if (subSeqence.size() % 2 == 0)
	{
		if (IsStarSequence(subSeqence))
		{
			starSequenceLength = subSeqence.size();
		}
		else
		{
			return 0;
		}
	}

	for (int i = nowIndex + 1; i < a.size(); ++i)
	{
		int afterStarSequenceLength = MakeSubSequence(a, subSeqence, a[i], i);
		if (afterStarSequenceLength > starSequenceLength)
		{
			starSequenceLength = afterStarSequenceLength;
		}
	}

	if (longgestLength < starSequenceLength)
	{
		longgestLength = starSequenceLength;
	}
	return starSequenceLength;
}
#include <iostream>

int solution(vector<int> a) {
	int answer = MakeSubSequence(a, vector<int>(), -1, -1);
	return answer;
}


int main()
{
	vector<int> a{ 1, 1, 1, 2, 1, 3 };
	solution(a);
}