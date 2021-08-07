/*
	https://programmers.co.kr/learn/courses/30/lessons/60059
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum RotateAngle { ROTATE0, ROTATE90, ROTATE180, ROTATE270 };
enum { HOME, BUMP };

vector<vector<pair<int, int>>> bumps;
vector<pair<int, int>> homes;
vector<vector<int>> locks;
int M, N;

pair<int, int> RotatePoint(int& y, int& x)
{
	swap(x, y);
	x = M - x;

	return pair(y, x);
}

void InitializeKey(const vector<vector<int>>& key)
{
	for (int y = 0; y <= M; ++y)
	{
		for (int x = 0; x <= M; ++x)
		{
			if (key[y][x] == BUMP)
			{
				bumps[ROTATE90].emplace_back(RotatePoint(y, x));
				bumps[ROTATE180].emplace_back(RotatePoint(y, x));
				bumps[ROTATE270].emplace_back(RotatePoint(y, x));
				bumps[ROTATE0].emplace_back(RotatePoint(y, x));
			}
		}
	}
}

void InitializeLock(const vector<vector<int>>& lock)
{
	for (int y = 0; y <= N; ++y)
	{
		for (int x = 0; x <= N; ++x)
		{
			if (lock[y][x] == HOME)
			{
				homes.emplace_back(y, x);
			}
		}
	}
}

const bool IsInsideLock(const int x)
{
	return x >= 0 && x <= N;
}

bool CombineKey(const RotateAngle angle, const int xOffset, const int yOffset)
{
	for (int index = 0; index < bumps[angle].size(); ++index)
	{
		const pair<int, int> point = bumps[angle][index];

		if (IsInsideLock(point.first - yOffset) &&
			IsInsideLock(point.second - xOffset) &&
			locks[point.first - yOffset][point.second - xOffset] == BUMP)
		{
			return false;
		}
	}

	for (int index = 0; index < homes.size(); ++index)
	{
		auto findIter = find_if(bumps[angle].begin(), bumps[angle].end(), [=](const pair<int, int>& p) {
			return p.first == homes[index].first + yOffset && p.second == homes[index].second + xOffset;
		});

		if (findIter == bumps[angle].end())
		{
			return false;
		}
	}

	return true;
}

bool FindCombineKey()
{
	for (const pair<int, int>& home : homes)
	{
		for (int angle = ROTATE0; angle <= ROTATE270; ++angle)
		{
			int xOffset = bumps[angle][0].second - home.second;
			int yOffset = bumps[angle][0].first - home.first;

			if (CombineKey((RotateAngle)angle, xOffset, yOffset) == true)
			{
				return true;
			}
		}
	}

	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	bumps = vector<vector<pair<int, int>>>(4);
	homes = vector<pair<int, int>>();
	locks = vector<vector<int>>();

	locks = lock;
	M = key.size() - 1;
	N = lock.size() - 1;
	
	InitializeKey(key);
	InitializeLock(lock);

	if (homes.size() == 0)
	{
		return true;
	}

	return FindCombineKey();
}

int main()
{
	vector<vector<int>> key{ {0, 0, 1 }, {0, 0, 0}, {0, 0, 0} };
	vector<vector<int>> lock{ {1, 0, 1}, { 1, 1, 1 }, {1, 1, 1} };

	solution(key, lock);
}

/*
* key 는 M X M ( 3 ~ 20 )크기의 2차원 배열 
* lock 은 N X N 크기의 2차원 배열
* M <= N
* key와 lock 은 0, 1로 이루어짐 ( 0 = 홈, 1 = 돌기 )
*/