#include <string>
#include <vector>
#include <set>

using namespace std;

const string BUCKETS[2] = { "{", "}" };
const int LEFT_OFFSET[2] = { 1, 0 };
const int RIGHT_OFFSET[2] = { 0, 1 };

set<string> correct_buckets;

const bool isValidBucket(int n, int leftCount, int rightCount)
{
    return leftCount < rightCount || leftCount > n || rightCount > n;
}

void combBuckets(const int n, int leftCount, int rightCount, string s)
{
    if (isValidBucket(n, leftCount, rightCount))
    {
        return;
    }

    if (s.length() == n * 2)
    {
        if (leftCount == rightCount)
        {
            correct_buckets.insert(s);
            return;
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        s += BUCKETS[i];
        combBuckets(n, leftCount + LEFT_OFFSET[i], rightCount + RIGHT_OFFSET[i], s);
        s.pop_back();
    }
}

int solution(int n) {
    combBuckets(n, 0, 0, "");
    return correct_buckets.size();
}

#include <iostream>

int main()
{
    for (int i = 2; i <= 14; ++i)
    {
        cout << i << " : " << solution(i) << '\n';
        correct_buckets.clear();
    }
}