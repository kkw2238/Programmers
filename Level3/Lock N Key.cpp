/*
	https://programmers.co.kr/learn/courses/30/lessons/60059
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum RotateAngle { ROTATE0, ROTATE90, ROTATE180, ROTATE270 };
enum { HOME, BUMP };

const int ANGLE_COUNT = 4;

vector<vector<pair<int, int>>> bumps = vector<vector<pair<int, int>>>(ANGLE_COUNT);
vector<pair<int, int>> homes = vector<pair<int, int>>();
int M, N;

pair<int, int> RotatePoint(int& y, int& x)
{
	y = M - y;
	swap(x, y);

	return pair(y, x);
}

void InitializeKey(const vector<vector<int>>& key)
{
	M = key.size() - 1;

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
	N = lock.size() - 1;

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

const bool IsLockArea(const pair<int, int>& point)
{
	return (point.second >= 0 && point.second <= N) && (point.first >= 0 && point.first <= N);
}

bool CombineKey(const vector<vector<int>>& lock, const RotateAngle angle, const int xOffset, const int yOffset)
{
	for (int index = 0; index < bumps[angle].size(); ++index)
	{
		const pair<int, int> point = pair(bumps[angle][index].first - yOffset, bumps[angle][index].second - xOffset);

		if (IsLockArea(point) && lock[point.first][point.second] == BUMP)
		{
			return false;
		}
	}

	for (const pair<int, int>& home : homes)
	{
		auto findIter = find_if(bumps[angle].begin(), bumps[angle].end(), [&](const pair<int, int>& p) {
			return (p.first == home.first + yOffset) && (p.second == home.second + xOffset);
		});

		if (findIter == bumps[angle].end())
		{
			return false;
		}
	}

	return true;
}

bool FindCombineKey(const vector<vector<int>>& lock)
{
	for (const pair<int, int>& home : homes)
	{
		for (int angle = ROTATE0; angle <= ROTATE270; ++angle)
		{
			for (int index = 0; index < bumps[angle].size(); ++index) 
			{
				int xOffset = bumps[angle][index].second - home.second;
				int yOffset = bumps[angle][index].first - home.first;

				if (CombineKey(lock, (RotateAngle)angle, xOffset, yOffset) == true)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	InitializeKey(key);
	InitializeLock(lock);

	if (homes.size() == 0)
	{
		return true;
	}

	return FindCombineKey(lock);
}

int main()
{
	vector<vector<int>> key{ {1, 1, 1 }, {1, 1, 1}, {1,1, 1} };
	vector<vector<int>> lock{ {0, 0, 0}, { 0, 0, 0 }, {0, 0, 1} };

	solution(key, lock);
}

/*
* key 는 M X M ( 3 ~ 20 )크기의 2차원 배열 
* lock 은 N X N 크기의 2차원 배열
* M <= N
* key와 lock 은 0, 1로 이루어짐 ( 0 = 홈, 1 = 돌기 )
*/