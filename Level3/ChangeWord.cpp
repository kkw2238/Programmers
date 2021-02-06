#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int smallestCount = 2147483647;

const bool CompareWithOut1(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.length(); ++i) {
        diff += (int)(a[i] != b[i]);
        if (diff > 1)
            return false;
    }

    return true;
}

void DFS(const string& target, string now, vector<string> words, vector<set<char>>& enableCharaters, int count) {
    auto iter = find(words.begin(), words.end(), now);
    if (iter == words.end())
        return;

    if (CompareWithOut1(target, now)) {
        smallestCount = smallestCount < count + 1 ? smallestCount : count + 1;
        return;
    }

    if(iter != words.end()) 
        words.erase(iter);

    for (int i = 0; i < target.length(); ++i) {
        string memNow = now;
        for (char c : enableCharaters[i]) {
            memNow[i] = c;
            DFS(target, memNow, words, enableCharaters, count + 1);
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    vector<set<char>> enableCharacters(begin.length(), set<char>());
    for (string& word : words) {
        for (int i = 0; i < word.length(); ++i) {
            enableCharacters[i].insert(word[i]);
        }
    }
    DFS(begin, target, words, enableCharacters, 0);

    return smallestCount;
}
#include <iostream>

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };

    cout << solution(begin, target, words);
}