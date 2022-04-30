#include <vector>
#include <iostream>

using namespace std;


const bool isAllPair(const vector<bool>& alreadyExistFriend)
{
	for (bool existFriend : alreadyExistFriend)
	{
		if (!existFriend)
		{
			return false;
		}
	}

	return true;
}

int findAllPairPicnic(const vector<vector<bool>>& ablePair, int nowFriend, vector<bool> alreadyExist)
{
	int ablePairCount = 0;

	if (nowFriend == alreadyExist.size())
	{
		return (int)isAllPair(alreadyExist);
	}

	for (int p : ablePair[nowFriend])
	{
		if (ablePair[nowFriend][p] && !alreadyExist[nowFriend] && !alreadyExist[p])
		{
			alreadyExist[nowFriend] = true;
			alreadyExist[p] = true;

			ablePairCount += findAllPairPicnic(ablePair, nowFriend + 1, alreadyExist);

			alreadyExist[nowFriend] = false;
			alreadyExist[p] = false;
		}
	}

	return ablePairCount;
}

void Run(int studentCount, int pairCount, const vector<int> pairs)
{
	vector<vector<bool>> ablePair = vector<vector<bool>>(studentCount, vector<bool>(studentCount, false));

	for (int i = 0; i < pairCount; ++i)
	{
		int nowFriend = min(pairs[2 * i], pairs[2 * i + 1]);
		int pairFriend = max(pairs[2 * i], pairs[2 * i + 1]);

		ablePair[nowFriend][pairFriend] = 1;
	}

	vector<bool> alreadyExistFriend(studentCount);

	cout << findAllPairPicnic(ablePair, 0, alreadyExistFriend) << '\n';
}


int main()
{
	//Run(2, 1,  { 0, 1 });
	Run(4, 6,  { 0, 1, 1, 2, 2, 3, 3, 0, 0, 2, 1, 3 });
	Run(6, 10, { 0, 1, 0, 2, 1, 2, 1, 3, 1, 4, 2, 3, 2, 4, 3, 4, 3, 5, 4, 5 });

}

/*
	0 : 1 2 3
	1 : 2 3
	2 : 3

	0, 1 /    0, 2    / 0, 3 
	2, 3 /    1, 3    / 1, 2 
*/