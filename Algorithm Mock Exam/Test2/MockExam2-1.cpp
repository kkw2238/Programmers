#include <string>
#include <vector>

using namespace std;

int Combination(const vector<int>& number, int count, int index, int sum)
{
    int result = 0;

    if (count == 3)
    {
        return sum == 0;
    }

    for (int i = index; i < number.size(); ++i)
    {
        result += Combination(number, count + 1, i + 1, sum + number[i]);
    }

    return result;
}

int solution(vector<int> number) {
    return Combination(number, 0, 0, 0);
}