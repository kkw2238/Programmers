/*
	https://programmers.co.kr/learn/courses/30/lessons/70130
*/

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

//#include <vector>
//#include <set>
//
//using namespace std;
//
//const bool hasCross(const pair<int, int>& p, const int pairCount, const vector<int>& cross)
//{
//	return cross[p.first] == pairCount || cross[p.second] == pairCount || cross.empty();
//}
//
//int maxPairCount = 0;
//
//int makeSequence(const vector<int>& vi, int index, int pairCount, vector<set<int>>& sequence, int beforeNum, vector<int>& cross)
//{
//	pair<int, int> pi;
//	int result = pairCount;
//
//	if (beforeNum != -1)
//	{
//		if (beforeNum == vi[index])
//		{
//			return result;
//		}
//
//		pi.first = beforeNum;
//		pi.second = vi[index];
//
//		if (hasCross(pi, pairCount, cross))
//		{
//			if (sequence[pi.first].find(pi.second) == sequence[pi.first].end())
//			{
//				++cross[pi.first];
//				++cross[pi.second];
//
//				++pairCount;
//				maxPairCount = max(pairCount, pairCount);
//
//				for (int i = index + 1; i < vi.size(); ++i)
//				{
//					result = max(result, makeSequence(vi, i, pairCount, sequence, -1, cross));
//				}
//
//				--cross[pi.first];
//				--cross[pi.second];
//				sequence[pi.first].erase(pi.second);
//			}
//		}
//	}
//	else
//	{
//		for (int i = index + 1; i < vi.size(); ++i)
//		{
//			result = max(result, makeSequence(vi, i, pairCount, sequence, vi[index], cross));
//		}
//	}
//
//	return max(result, pairCount);
//}
//
//int solution(vector<int> a) {
//	int answer = -1;
//	vector<set<int>> sequence(a.size(), set<int>());
//	vector<int> cross(a.size());
//
//	for (int i = 0; i < a.size(); ++i) 
//	{
//		answer = max(answer, makeSequence(a, 0, 0, sequence, -1, cross));
//	}
//
//	return answer * 2;
//}



//int totalCount = 0;
//
//int makeSequence(const vector<int>& vi, int idx, const vector<int>& indices, int beforeIndex)
//{
//	set<pair<int, int>> makeSequences;
//	int beginIndex = -1;
//	
//	int result = 0;
//
//	if (vi.size() == 1)
//	{
//		return 0;
//	}
//	
//	for (int i = idx; i < indices.size(); ++i)
//	{
//		int sequenceSize = makeSequences.size();
//		result = sequenceSize;
//
//		if (result > totalCount)
//		{
//			totalCount = result;
//		}
//		if ((indices.size() - i + result) < totalCount)
//		{
//			return result;
//		}
//
//		int nowIndex = indices[i];
//
//		if (nowIndex > 0 && vi[nowIndex - 1] != vi[nowIndex] && (nowIndex - 1) != beforeIndex)
//		{
//			makeSequences.insert(pair(vi[nowIndex - 1], vi[nowIndex]));
//			beforeIndex = nowIndex;
//		}
//		else if (nowIndex < (vi.size() - 1) && vi[nowIndex] != vi[nowIndex + 1])
//		{
//			makeSequences.insert(pair(vi[nowIndex], vi[nowIndex + 1]));
//			beforeIndex = nowIndex + 1;
//		}
//	}
//
//	return result;
//}
//
//int solution(vector<int> a) {
//	int result = 0;
//
//	map<int, vector<int>> eleIndex;
//
//	for (int i = 0; i < a.size(); ++i)
//	{
//		eleIndex[a[i]].push_back(i);
//	}
//
//	vector<pair<int, vector<int>>> vpiv( eleIndex.begin(), eleIndex.end() );
//	sort(vpiv.begin(), vpiv.end(), [](const pair<int, vector<int>>& l, const pair<int, vector<int>>& r) {
//		return l.second.size() > r.second.size();
//	});
//
//	for (const auto& indices : vpiv) {
//		if ((indices.second.size() * 2) < result)
//		{
//			break;
//		}
//		totalCount = 0;
//		result = max(result, makeSequence(a, 0, indices.second, -1) * 2);
//	}
//
//	return result;
//}

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int makeSequence(const vector<int>& vi, int idx, const vector<int>& indices, int beforeIndex)
{
	if (vi.size() == 1)
	{
		return 0;
	}

	int count = 0;
	for (const int index : indices)
	{
		if (index > 0 && vi[index - 1] != vi[index] && (index - 1) != beforeIndex)
		{
			++count;
		}
		else if ((index < (vi.size() - 1) && vi[index] != vi[index + 1]))
		{
			beforeIndex = index + 1;
			++count;
		}
	}

	return count;
}

int solution(vector<int> a) {
	int result = 0;

	map<int, vector<int>> eleIndex;

	for (int i = 0; i < a.size(); ++i)
	{
		eleIndex[a[i]].push_back(i);
	}

	vector<pair<int, vector<int>>> vpiv(eleIndex.begin(), eleIndex.end());
	sort(vpiv.begin(), vpiv.end(), [](const pair<int, vector<int>>& l, const pair<int, vector<int>>& r) {
		return l.second.size() > r.second.size();
		});

	for (const auto& indices : vpiv) {
		if ((indices.second.size() * 2) < result)
		{
			break;
		}
		result = max(result, makeSequence(a, 0, indices.second, -1) * 2);
	}

	return result;
}

#include <iostream>

int main()
{
	vector<int> a{ 5,2,3,3,5,3 };
	cout << solution(a);
}
/*
	vector<vector<int>> �� �׸� index�� ���

*/


/*

#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int totalCount = 0;

int makeSequence(const vector<int>& vi, int idx, const vector<int>& indices, set<pair<int, int>>& makedSequences, int beforeIndex)
{

	set<pair<int, int>> makeSequences;
	int beginIndex = -1;
	const int sequenceSize = makedSequences.size();
	int result = sequenceSize;

	if (vi.size() == 1)
	{
		return 0;
	}
	if (indices.size() - idx < totalCount)
	{
		return result;
	}

	for (int i = idx; i < indices.size(); ++i)
	{
		int nowIndex = indices[i];

		if (nowIndex > 0 && vi[nowIndex - 1] != vi[nowIndex] && (nowIndex - 1) != beforeIndex)
		{
			makedSequences.insert(pair(vi[nowIndex - 1], vi[nowIndex]));
			if (sequenceSize != makedSequences.size())
			{
				result = max(result, makeSequence(vi, i + 1, indices, makedSequences, nowIndex));
				makedSequences.erase(pair(vi[nowIndex - 1], vi[nowIndex]));
			}
		}
		else if (nowIndex < (vi.size() - 1) && vi[nowIndex] != vi[nowIndex + 1])
		{
			makedSequences.insert(pair(vi[nowIndex], vi[nowIndex + 1]));
			if (sequenceSize != makedSequences.size())
			{
				result = max(result, makeSequence(vi, i + 1, indices, makedSequences, nowIndex + 1));
				makedSequences.erase(pair(vi[nowIndex], vi[nowIndex + 1]));
			}
		}
	}

	if (result > totalCount)
	{
		totalCount = result;
	}
	return result;
}

int solution(vector<int> a) {
	int result = 0;

	map<int, vector<int>> eleIndex;

	for (int i = 0; i < a.size(); ++i)
	{
		eleIndex[a[i]].push_back(i);
	}

	vector<pair<int, vector<int>>> vpiv(eleIndex.begin(), eleIndex.end());
	sort(vpiv.begin(), vpiv.end(), [](const pair<int, vector<int>>& l, const pair<int, vector<int>>& r) {
		return l.second.size() > r.second.size();
		});

	for (const auto& indices : vpiv) {
		if ((indices.second.size() * 2) < result)
		{
			break;
		}
		totalCount = 0;
		result = max(result, makeSequence(a, 0, indices.second, -1) * 2);
	}

	return result;
}
*/