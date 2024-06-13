#include <algorithm>
#include <string>
#include <vector>

using namespace std;

enum { FIRSTFRIEND_INDEX = 0, SECONDFRIEND_INDEX = 2, SYMBOL_INDEX = 3, DISTANCE_INDEX = 4};

const bool IsRightPermutation(const string& friends, const string& data)
{
    int firstFriendPos = friends.find(data[FIRSTFRIEND_INDEX]);
    int secondFriendPos = friends.find(data[SECONDFRIEND_INDEX]);

    int dist = abs(firstFriendPos - secondFriendPos) - 1;

    switch (data[SYMBOL_INDEX])
    {
    case '>':
        return dist > data[DISTANCE_INDEX] - '0';
    case '<':
        return dist < data[DISTANCE_INDEX] - '0';
    case '=':
        return dist == data[DISTANCE_INDEX] - '0';
    }
}

int solution(int n, vector<string> data) {
    string friends = "ACFJMNRT";
    int answer = 0;

    do {
        bool isRight = true;
        for (const string& s : data)
        {
            if (!IsRightPermutation(friends, s))
            {
                isRight = false;
                break;
            }
        }

        if (isRight)
        {
            ++answer;
        }
    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}