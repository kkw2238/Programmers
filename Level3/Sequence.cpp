/*
	어떤 수열 x의 부분 수열(Subsequence)이란, 
	x의 몇몇 원소들을 제거하거나 그러지 않고 남은 원소들이 원래 순서를 유지하여 얻을 수 있는 새로운 수열을 말합니다.

	예를 들어, [1,3]은 [1,2,3,4,5]의 부분수열입니다. 원래 수열에서 2, 4, 5를 제거해서 얻을 수 있기 때문입니다.
	다음과 같은 조건을 모두 만족하는 수열 x를 스타 수열이라고 정의합니다.
*/

/*
*	해결해야 할 내용
		1. 부분 수열
			=> 순서가 유지 돼야하는 수열
			=> 10개의 원소가 있을 경우 10 9 8 7 6 5 4 3 2 1개의 수열 존재
				-> 최대 길이 50만의 수열 존재 -> 시간초과 가능성 
			=> i = 1 ~ n

		2. 스타 수열
			=> O
			=> 최소값 2 

		3. 스타수열이 없는 케이스 X 
*/
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int longgestLength = 0;
//
//bool HasIntersection(pair<int, int>& setA, const int setBA, const int setBB)
//{
//	if (setA.first >= 0 && setA.first != setBA && setA.first != setBB)
//	{
//		setA.first = -1;
//	}
//	if (setA.second >= 0 && setA.second != setBA && setA.second != setBB)
//	{
//		setA.second = -1;
//	}
//	return setA.first + setA.second == -2;
//}
//
//bool IsStarSequence(const vector<int>& sequence)
//{
//	pair setA{ sequence[0], sequence[1] };
//	for (int i = 0; i < sequence.size() / 2; ++i)
//	{
//		if (HasIntersection(setA, sequence[i * 2], sequence[i * 2 + 1]))
//		{
//			return false;
//		}
//
//		if (sequence[i * 2] == sequence[i * 2 + 1])
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
//
//int MakeSubSequence(const vector<int>& a, vector<int> subSeqence, const int beforenumber, const int nowIndex)
//{
//	if (a.size() - (nowIndex + subSeqence.size()) < longgestLength)
//	{
//		return 0;
//	}
//
//	int starSequenceLength = 0;
//	if (beforenumber != -1)
//	{
//		subSeqence.emplace_back(beforenumber);
//	}
//
//	if (subSeqence.size() % 2 == 0)
//	{
//		if (IsStarSequence(subSeqence))
//		{
//			starSequenceLength = subSeqence.size();
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//	for (int i = nowIndex + 1; i < a.size(); ++i)
//	{
//		int afterStarSequenceLength = MakeSubSequence(a, subSeqence, a[i], i);
//		if (afterStarSequenceLength > starSequenceLength)
//		{
//			starSequenceLength = afterStarSequenceLength;
//		}
//	}
//
//	if (longgestLength < starSequenceLength)
//	{
//		longgestLength = starSequenceLength;
//	}
//	return starSequenceLength;
//}
//#include <iostream>
//
//int solution(vector<int> a) {
//	int answer = MakeSubSequence(a, vector<int>(), -1, -1);
//	return answer;
//}

#include <vector>
#include <set>

using namespace std;

const bool hasCross(const pair<int, int>& p, const int pairCount, const vector<int>& cross)
{
	return cross[p.first] == pairCount || cross[p.second] == pairCount || cross.empty();
}

int maxPairCount = 0;

int makeSequence(const vector<int>& vi, int index, int pairCount, vector<set<int>>& sequence, int beforeNum, vector<int>& cross)
{
	pair<int, int> pi;
	int result = pairCount;

	if (beforeNum != -1)
	{
		if (beforeNum == vi[index])
		{
			return result;
		}

		pi.first = beforeNum;
		pi.second = vi[index];

		if (hasCross(pi, pairCount, cross))
		{
			if (sequence[pi.first].find(pi.second) == sequence[pi.first].end())
			{
				++cross[pi.first];
				++cross[pi.second];

				++pairCount;
				maxPairCount = max(pairCount, pairCount);

				for (int i = index + 1; i < vi.size(); ++i)
				{
					result = max(result, makeSequence(vi, i, pairCount, sequence, -1, cross));
				}

				--cross[pi.first];
				--cross[pi.second];
				sequence[pi.first].erase(pi.second);
			}
		}
	}
	else
	{
		for (int i = index + 1; i < vi.size(); ++i)
		{
			result = max(result, makeSequence(vi, i, pairCount, sequence, vi[index], cross));
		}
	}

	return max(result, pairCount);
}

int solution(vector<int> a) {
	int answer = -1;
	vector<set<int>> sequence(a.size(), set<int>());
	vector<int> cross(a.size());

	for (int i = 0; i < a.size(); ++i) 
	{
		answer = max(answer, makeSequence(a, 0, 0, sequence, -1, cross));
	}

	return answer * 2;
}

int main()
{
	vector<int> a{ 1, 1, 1, 2, 1, 3 };
	solution(a);
}
/*
	vector<vector<int>> 각 항목별 index를 기억

*/