/*
	https://programmers.co.kr/learn/courses/30/lessons/60059
*/
#include <vector>
#include <algorithm>

using namespace std;

enum RotateAngle { ROTATE0, ROTATE90, ROTATE180, ROTATE270 };
enum { HOME, BUMP };

using Point = pair<int, int>;

const int ANGLE_COUNT = 4;

vector<vector<Point>> key_Bumps = vector<vector<Point>>(ANGLE_COUNT); // 열쇠 돌기 index
vector<Point> lock_Homes = vector<Point>(); // 자물쇠 홈 index
int M, N;

// 90도 회전한 후의 위치를 반환하는 함수
pair<int, int> RotatePoint(int& y, int& x)
{
	y = M - y;
	swap(x, y);

	return Point(y, x);
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
				key_Bumps[ROTATE90].emplace_back(RotatePoint(y, x));
				key_Bumps[ROTATE180].emplace_back(RotatePoint(y, x));
				key_Bumps[ROTATE270].emplace_back(RotatePoint(y, x));
				key_Bumps[ROTATE0].emplace_back(RotatePoint(y, x));
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
				lock_Homes.emplace_back(y, x);
			}
		}
	}
}

const bool IsLockArea(const Point& point)
{
	return (point.second >= 0 && point.second <= N) && (point.first >= 0 && point.first <= N);
}

bool CombineKey(const vector<vector<int>>& lock, const RotateAngle angle, const int xOffset, const int yOffset)
{
	for (int index = 0; index < key_Bumps[angle].size(); ++index)
	{
		const Point point = Point(key_Bumps[angle][index].first - yOffset, key_Bumps[angle][index].second - xOffset);

		if (IsLockArea(point) && lock[point.first][point.second] == BUMP)
		{
			return false;
		}
	}

	for (const pair<int, int>& home : lock_Homes)
	{
		auto findIter = find_if(key_Bumps[angle].begin(), key_Bumps[angle].end(), [&](const Point& p) {
			return (p.first == home.first + yOffset) && (p.second == home.second + xOffset);
		});

		if (findIter == key_Bumps[angle].end())
		{
			return false;
		}
	}

	return true;
}

bool FindCombineKey(const vector<vector<int>>& lock)
{
	for (const Point& home : lock_Homes)
	{
		for (int angle = ROTATE0; angle <= ROTATE270; ++angle)
		{
			for (int index = 0; index < key_Bumps[angle].size(); ++index) 
			{
				int xOffset = key_Bumps[angle][index].second - home.second;
				int yOffset = key_Bumps[angle][index].first - home.first;

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

	if (lock_Homes.size() == 0)
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