#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<int> fib = { 1, 2 };

    for (int i = 2; i < n; ++i)
    {
        fib.emplace_back(fib[i - 1] - fib[i - 2]);
    }

    return fib[fib.size() - 1];
}
