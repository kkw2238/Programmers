/*
    https://programmers.co.kr/learn/courses/30/lessons/81303
*/
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmds) {
    vector<int> characters;
    stack<pair<int, int>> record;

    string answer(n, 'O');

    for (int i = 0; i < n; ++i)
    {
        characters.emplace_back(i);
    }

    int nowPos = k;
  
    for (const string& cmd : cmds)
    {
        int offset = 1;
        int nowNum = characters[nowPos];

        switch (cmd[0])
        {
        case 'U':
            offset = stoi(cmd.substr(2));
            nowPos -= offset;
            break;

        case 'D':
            offset = stoi(cmd.substr(2));
            nowPos += offset;
            break;

        case 'C':
            answer[nowNum] = 'X';
            characters.erase(characters.begin() + nowPos);

            if (characters.size() == nowPos)
            {
                record.emplace(nowPos--, nowNum);
            }
            else
            {
                record.emplace(nowPos, nowNum);
            }

            break;

        case 'Z':
            pair lastestRecord = record.top();
            record.pop();

            answer[lastestRecord.second] = 'O';
            characters.insert(characters.begin() + lastestRecord.first, lastestRecord.second);

            if (lastestRecord.first <= nowPos)
            {
                ++nowPos;
            }

            break;
        }
    }

    return answer;
}

int main()
{
    solution(8, 2, { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C" });
} 

/*
#include <string>
#include <vector>
#include <list>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmds) {
    list<int> characters;
    stack<pair<list<int>::iterator, int>> record;

    string answer(n, 'O');

    for (int i = 0; i < n; ++i)
    {
        characters.emplace_back(i);
    }

    list<int>::iterator nowPos = characters.begin();
    advance(nowPos, k);

    for (const string& cmd : cmds)
    {
        auto tmpIter = nowPos;
        int offset = 0;
        int nowNum = *nowPos;

        switch (cmd[0])
        {
        case 'U':
            offset = stoi(cmd.substr(2));
            advance(nowPos, -offset);

            break;

        case 'D':
            offset = stoi(cmd.substr(2));
            advance(nowPos, offset);

            break;

        case 'C':
            if (nowPos == --(characters.end()))
            {
                offset = -1;
                --nowPos;
            }
            else
            {
                offset = 1;
                ++nowPos;
            }

            answer[nowNum] = 'X';
            characters.erase(tmpIter);

            advance(nowPos, -offset);
            record.emplace(nowPos, nowNum);
            advance(nowPos, offset);

            break;

        case 'Z':
            pair lastestRecord = record.top();
            record.pop();

            answer[lastestRecord.second] = 'O';
            characters.insert(lastestRecord.first, lastestRecord.second);

            break;
        }
    }

    return answer;
}
*/