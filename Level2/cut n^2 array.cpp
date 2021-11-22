#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> container;
    long long b = left / n;
    long long e = right / n;

    for (long long i = b; i <= e; ++i)
    {
        vector<int> line(n, i + 1);

        iota(line.begin() + i, line.end(), i + 1);
        container.insert(container.end(), line.begin(), line.end());
    }

    return vector<int>(container.begin() + left - 1 - (b * n), container.begin() + right + 1 - (b * n));
}

int main()
{
    solution(3, 2, 5);
}