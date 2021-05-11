#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int friendsCount = stones.size();
    int tmpFriendsCount = 0;

    for (int i = 0; i < stones.size() - k; ++i)
    {
        tmpFriendsCount = *max_element(stones.begin() + i, stones.begin() + i + k);
        if (tmpFriendsCount < friendsCount)
        {
            friendsCount = tmpFriendsCount;
        }
    }

    return friendsCount;
}

#include <iostream>

int main()
{
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    int k = 10;

    cout << solution(stones, k) << '\n';
}