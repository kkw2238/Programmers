#include <vector>
#include <iostream>
#include <set>

using namespace std;

//set<vector<int>> makedFriendsPair;
//
//void makeCombination(int index, vector<int> makedPair, vector<bool> existed)
//{
//	makedPair.push_back(index);
//	existed[index] = true;
//
//	if (makedPair.size() == existed.size())
//	{
//		makedFriendsPair.insert(makedPair);
//		return;
//	}
//
//	for (int i = 0; i < existed.size(); ++i)
//	{
//		if (index == i || existed[i])
//		{
//			continue;
//		}
//
//		makeCombination(i, makedPair, existed);
//	}
//}
//
//void Run(int studentCount, int pairCount, vector<int> pairs)
//{
//	makedFriendsPair.clear();
//	vector<vector<bool>> ablePair(studentCount, vector<bool>(studentCount));
//	int ableCount = 0;
//
//	for (int i = 0; i < pairCount; ++i)
//	{
//		int now = min(pairs[i * 2], pairs[i * 2 + 1]);
//		int pairFriend = max(pairs[i * 2], pairs[i * 2 + 1]);
//
//		ablePair[now][pairFriend] = true;
//	}
//
//	for (int i = 0; i < studentCount; ++i)
//	{
//		makeCombination(i, vector<int>(), vector<bool>(studentCount));
//	}
//
//	set<set<pair<int, int>>>ssp;
//	for (vector<int> combination : makedFriendsPair)
//	{
//		set<pair<int, int>> sp;
//
//		int count = 0;
//		for (int i = 0; i < combination.size() / 2; ++i)
//		{
//			if (!ablePair[combination[i * 2]][combination[i * 2 + 1]])
//			{
//				break;
//			}
//
//			sp.insert(make_pair(combination[i * 2], combination[i * 2 + 1]));
//			++count;
//		}
//
//		if (count == combination.size() / 2)
//		{
//			++ableCount;
//			ssp.insert(sp);
//		}
//	}
//
//	cout << ssp.size() << '\n';
//}

const int MAX_STUDENTCOUNT = 10;
bool areFriends[MAX_STUDENTCOUNT][MAX_STUDENTCOUNT];
int gstudentCount = 0;

int makePairs(bool alreadyExist[10])
{
	int result = 0;
	int firstFriends = -1;

	for (int i = 0; i < gstudentCount; ++i)
	{
		if (!alreadyExist[i])
		{
			firstFriends = i;
			break;
		}
	}

	if (firstFriends == -1)
	{
		return 1;
	}

	for (int i = firstFriends + 1; i < gstudentCount; ++i)
	{
		if (!alreadyExist[i] && areFriends[firstFriends][i])
		{
			alreadyExist[i] = true;
			alreadyExist[firstFriends] = true;
			
			result += makePairs(alreadyExist);
			
			alreadyExist[i] = false;
			alreadyExist[firstFriends] = false;
		}
	}

	return result;
}

void Run(int studentCount, int pairCount, vector<int> pairs)
{
	gstudentCount = studentCount;
	for (int i = 0; i < pairCount; ++i)
	{
		int now = min(pairs[i * 2], pairs[i * 2 + 1]);
		int pairFriend = max(pairs[i * 2], pairs[i * 2 + 1]);

		areFriends[now][pairFriend] = true;
	}

	bool alreadyExist[10] = { false, false, false, false, false, false, false, false, false, false };
	cout << makePairs(alreadyExist) <<'\n';
}