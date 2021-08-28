//
//int solution(vector<int> stones, int k) {
//    int friendsCount = stones.size();
//    int tmpFriendsCount = 0;
//
//    for (int i = 0; i <= stones.size() - k; ++i)
//    {
//        tmpFriendsCount = *max_element(stones.begin() + i, stones.begin() + i + k);
//        if (tmpFriendsCount < friendsCount)
//        {
//            friendsCount = tmpFriendsCount;
//        }
//    }
//
//    return friendsCount;
//}

#include <vector>
#include <map>

using namespace std;

const int MAXIMUM = 200000001;

int solution(vector<int> stones, int k) {
    map<int, int> stepping_counts;
    int count = 0;
    int answer = MAXIMUM;

    for (int i = stones.size() - 1; i >= -1; --i)
    {
        if (++count > k)
        {
            int maximum_count = (*stepping_counts.rbegin()).first;
            if (answer > maximum_count)
            {
                answer = maximum_count;
            }

            --stepping_counts[stones[i + k]];

            if (stepping_counts[stones[i + k]] <= 0)
            {
                stepping_counts.erase(stones[i + k]);
            }
        }

        if (i >= 0) 
        {
            ++stepping_counts[stones[i]];
        }
    }

    return answer;
}