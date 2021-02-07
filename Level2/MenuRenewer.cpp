/* https://programmers.co.kr/learn/courses/30/lessons/72411 */

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<map<string, int>> menuCombination(8);

void Swap(string& s, int a, int b) {
    char c = s[a];
    s[a] = s[b];
    s[b] = c;
}

void CombinationOrder(string order, string makedComb, int index, set<string>& combinatedMenu) {
    if (index > order.length()) return;

    sort(makedComb.begin(), makedComb.end());

    if (makedComb.length() >= 2 && combinatedMenu.find(makedComb) == combinatedMenu.end()) {
        combinatedMenu.insert(makedComb);
        ++menuCombination[makedComb.length() - 2][makedComb];
    }

    for (int i = index; i < order.length(); ++i) {
        string tmpComb = makedComb;

        Swap(order, i, index);
        tmpComb += order[index];
        CombinationOrder(order, tmpComb, index + 1, combinatedMenu);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); ++i) {
        set<string> s;
        CombinationOrder(orders[i], "", 0, s);
    }

    for (int i = 0; i < course.size(); ++i) {
        int maximum = 2;
        vector<string> pocket;
        for(pair<const string, int>& p : menuCombination[course[i] - 2]) {
            if (p.second > maximum) {
                pocket.clear();
                pocket.push_back(p.first);

                maximum = p.second;
            }
            else if (p.second == maximum) {
                pocket.push_back(p.first);
            }
        }
        answer.insert(answer.end(), pocket.begin(), pocket.end());
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    solution(orders, vector<int>{2, 3, 4});
}