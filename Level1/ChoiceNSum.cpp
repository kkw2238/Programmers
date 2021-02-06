#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> container;

    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            container.insert(numbers[i] + numbers[j]);
        }
    }

    return vector<int>(container.begin(), container.end());
}