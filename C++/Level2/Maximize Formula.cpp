/*
	https://programmers.co.kr/learn/courses/30/lessons/67257
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void CombPriorities(string combinatedExpress, string express, vector<string>& priority, int index)
{
    if (combinatedExpress.size() == 3) {
        priority.emplace_back(combinatedExpress);
        return;
    }

    string memCombinatedExpress = combinatedExpress;
    for (int i = index; i < 3; ++i) {
        swap(express[index], express[i]);
        combinatedExpress += express[index];
        CombPriorities(combinatedExpress, express, priority, index + 1);
        combinatedExpress = memCombinatedExpress;
    }
}

long long Calcul(long long a, long long b, char c) {

    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    default:
        return a * b;
    }
}

long long GetCalculresult(vector<long long> numbers, vector<char> express, string& priority)
{
    long long result = 0;

    for (int i = 0; i < 3; ++i) {
        auto iter = express.begin();
        while (true) {
            iter = find(express.begin(), express.end(), priority[i]);
            if (iter == express.end())
                break;

            int dist = distance(express.begin(), iter);
            numbers[dist] = Calcul(numbers[dist], numbers[dist + 1], priority[i]);
            numbers.erase(numbers.begin() + dist + 1);
            express.erase(iter);
        }
    }

    return numbers[0] < 0 ? numbers[0] * -1 : numbers[0];
}

void Distribute(vector<long long>& numbers, vector<char>& express, string expression)
{
    int findIndex = 0;
    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] > '9' || expression[i] < '0') {
            numbers.push_back(stoll(expression.substr(findIndex, i - findIndex)));
            express.push_back(expression[i]);
            findIndex = i + 1;
        }
    }

    numbers.push_back(stoi(expression.substr(findIndex, expression.length() - findIndex)));
}

long long solution(string expression) {
    vector<string> priority;
    vector<long long> numbers;
    vector<char> express;

    long long answer = 0;
    Distribute(numbers, express, expression);
    CombPriorities("", "+-*", priority, 0);

    for (string& s : priority) {
        long long result = GetCalculresult(numbers, express, s);
        answer = answer > result ? answer : result;
    }
    return answer;
}