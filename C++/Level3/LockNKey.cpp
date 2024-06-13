#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define ROW(x) x.first
#define COLUMN(x) x.second

pair<int, int> keySize;
pair<int, int> lockSize;

vector<vector<int>> RotateKey(const vector<vector<int>>& key)
{
    vector<vector<int>> rotatedKey(ROW(keySize), vector<int>(COLUMN(keySize), 0));

    for (int i = 0; i < ROW(keySize); ++i)
    {
        for (int j = 0; j < COLUMN(keySize); ++j)
        {
            if (key[i][j] == 1)
            {
                rotatedKey[j][ROW(keySize) - i - 1] = 1;
            }
        }
    }
    return rotatedKey;
}

vector<vector<int>> ResizingKey(const vector<vector<int>>& key)
{
    if (lockSize == keySize)
    {
        return key;
    }

    vector<vector<int>> resizedKey(ROW(lockSize), vector<int>(COLUMN(lockSize), 0));

    for (int y = 0; y < ROW(keySize); ++y)
    {
        for (int x = 0; x < COLUMN(keySize); ++x)
        {
            resizedKey[y][x] = key[y][x];
        }
    }

    return resizedKey;
}

const bool IsUnlock(const vector<vector<int>>& lock)
{
    for (auto vi : lock)
    {
        if (find(vi.begin(), vi.end(), 0) != vi.end())
        {
            return false;
        }
    }

    return true;
}

vector<vector<int>> MergeKeyLock(const vector<vector<int>>& key, const vector<vector<int>>& lock, const int xOffset, const int yOffset)
{
    vector<vector<int>> mergedLock(ROW(lockSize), vector<int>(COLUMN(lockSize), 0));

    for (int y = yOffset; y < ROW(lockSize); ++y)
    {
        for (int x = xOffset; x < ROW(lockSize); ++x)
        {
            mergedLock[y][x] = key[y][x] + lock[y - yOffset][x - xOffset];
        }
    }

    return mergedLock;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    keySize = pair{ key.size(), key[0].size() };
    lockSize = pair{ lock.size(), lock[0].size() };

    for (int i = 0; i < 4; ++i) {
        key = RotateKey(key);
        vector<vector<int>> resizedKey = ResizingKey(key);

        for (int y = -ROW(lockSize) + 1; y < ROW(lockSize); ++y)
        {
            for (int x = -COLUMN(lockSize) + 1; x < COLUMN(lockSize); ++x)
            {
                vector<vector<int>> mergedLock = MergeKeyLock(key, lock, x, y);
                if (IsUnlock(mergedLock))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

#include <iostream>
int main()
{
    vector<vector<int>> key{ {0, 0, 0} ,{1, 0, 0},{0, 1, 1} };
    vector<vector<int>> lock{ {1, 1, 1} ,{1, 1, 0},{1, 0, 1} };

    cout << solution(key, lock);
}
 