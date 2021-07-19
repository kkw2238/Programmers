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
    list<int> characters;
    stack<pair<int, int>> record;
    
    string answer(n, 'O');
    int index = k;

    for (int i = 0; i < n; ++i)
    {
        characters.emplace_back(i);
    }

    for (const string& cmd : cmds)
    {
        auto tmpIter = characters.begin();
        int offset = 0;

        switch (cmd[0])
        {
        case 'U':
            offset = stoi(cmd.substr(2));
            index -= offset;

            break;

        case 'D':
            offset = stoi(cmd.substr(2));
            index += offset;

            break;

        case 'C':
            advance(tmpIter, index);
            record.emplace(index, *tmpIter);
            
            if (characters.size() > 1)
            {
                if (index == characters.size() - 1)
                {
                    --index;
                }
            }
            
            answer[*tmpIter] = 'X';
            characters.erase(tmpIter);
            break;

        case 'Z':
            pair lastestRecord = record.top();
            record.pop();

            answer[lastestRecord.second] = 'O';
            advance(tmpIter, lastestRecord.first);
            characters.insert(tmpIter, lastestRecord.second);

            if (lastestRecord.first < index)
            {
                ++index;
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
    stack<pair<int, int>> record;

    string answer(n, 'O');

    for (int i = 0; i < n; ++i)
    {
        characters.emplace_back(i);
    }

    auto nowPos = characters.begin();
    advance(nowPos, k);

    for (const string& cmd : cmds)
    {
        auto tmpIter = nowPos;
        int offset = 0;

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
            if (characters.size() > 1)
            {
                if (nowPos == --(characters.end()))
                {
                    advance(nowPos, -1);
                }
                else
                {
                    advance(nowPos, 1);
                }
            }

            answer[*tmpIter] = 'X';
            record.emplace(distance(characters.begin(), tmpIter), *tmpIter);
            characters.erase(tmpIter);

            break;

        case 'Z':
            pair lastestRecord = record.top();
            auto begin = characters.begin();
            record.pop();

            answer[lastestRecord.second] = 'O';
            advance(begin, lastestRecord.first);
            characters.insert(begin, lastestRecord.second);

            break;
        }
    }

    return answer;
}
*/