#include <string>
#include <vector>
#include <queue>
#include <functional>

#define COUNT_N(x) (x % 5 + x / 5) + 1

using namespace std;

const unsigned int MAXIMUM_NUM = 32000 * 9;
const int MAXIMUM_COUNT = 9;

vector<int> defaultNumbers;
vector<int> usedNumberCount(MAXIMUM_NUM, MAXIMUM_COUNT);

const bool EnableNextStep(const int destIndex, const int nowCount, const int addCount)
{
    if (destIndex >= MAXIMUM_NUM || destIndex <= 0)
    {
        return false;
    }
    else if (nowCount + addCount >= MAXIMUM_COUNT)
    {
        return false;
    }

    return usedNumberCount[destIndex] > nowCount + addCount;
}

int solution(int N, int number) {
    usedNumberCount = vector<int>(MAXIMUM_NUM, MAXIMUM_COUNT);
    queue<pair<int, int>> nextNumbers;
    vector<function<int(const int a, const int b)>> functions{
        [](const int a, const int b) { return a + b; },
        [](const int a, const int b) { return a - b; },
        [](const int a, const int b) { return a * b; },
        [](const int a, const int b) { return a / b; }
    };

    int answer = MAXIMUM_COUNT;

    defaultNumbers = vector<int>{ N, N * 11, N * 111, N * 1111, N * 11111, 1, 11, 111, 1111, 11111 };

    for (int i = 0; i < defaultNumbers.size(); ++i)
    {
        usedNumberCount[defaultNumbers[i]] = COUNT_N(i);
        nextNumbers.push(pair(defaultNumbers[i], COUNT_N(i)));
    }

    while (!nextNumbers.empty())
    {
        auto [nowNumber, count] = nextNumbers.front();
        nextNumbers.pop();

        if (count > usedNumberCount[nowNumber])
        {
            continue;
        }
        else if (nowNumber == number)
        {
            if (answer > count)
            {
                answer = count;
            }

            continue;
        }

        for (int i = 0; i < defaultNumbers.size(); ++i)
        {
            for (auto f : functions)
            {
                int nextIndex = f(nowNumber, defaultNumbers[i]);
                if (EnableNextStep(nextIndex, count, COUNT_N(i)))
                {
                    nextNumbers.push(pair(nextIndex, count + COUNT_N(i)));
                    usedNumberCount[nextIndex] = count + COUNT_N(i);
                }
            }
        }
    }

    if (answer == MAXIMUM_COUNT)
    {
        return -1;
    }
    else 
    {
        return answer;
    }
}
