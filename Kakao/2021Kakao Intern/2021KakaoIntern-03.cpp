#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

const int COMMAND_INDEX = 0;
const int ADDITIONAL_INDEX = 2;
const char ZERO = '0';

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    vector<int> friends(n + 1);
    stack<int> deleteCommandList;

    iota(friends.begin(), friends.end(), 0);

    int biggestNumber = n - 1;
    auto iter = friends.begin() + k;

    for (string& command : cmd)
    {
        switch (command[COMMAND_INDEX])
        {
        case 'U':
            iter -= command[ADDITIONAL_INDEX] - ZERO;
            break;
        case 'D':
            iter += command[ADDITIONAL_INDEX] - ZERO;
            break;

        case 'C':
            answer[*iter] = 'X';
            deleteCommandList.push(k);
            friends.erase(iter);
            if (iter == friends.end())
            {
                --iter;
            }
            break;
        case 'Z':
            int lastestDeleteNumber = deleteCommandList.top();
            answer[lastestDeleteNumber] = 'O';
            deleteCommandList.pop();

            if (lastestDeleteNumber > biggestNumber)
            {
                biggestNumber = lastestDeleteNumber;
            }
            break;
        }
    }

    return answer;
}

#include <iostream>

int main()
{
    vector<string> cmd = { "C","C","C","C","C","C","C", "Z","Z","Z","Z","Z","Z","Z", "C", "Z" };
    int n = 8;
    int k = 2;

    cout << solution(n, k, cmd);
}