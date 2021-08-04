/*
    https://programmers.co.kr/learn/courses/30/lessons/81303
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    void PrevLink(Node* prevNode)
    {
        if (prevNode != nullptr)
        {
            prevNode->next = this;
        }
        prev = prevNode;
    }

    void NextLink(Node* nextNode)
    {
        if (nextNode != nullptr)
        {
            nextNode->prev = this;
        }
        next = nextNode;
    }

public:
    Node* next = nullptr;
    Node* prev = nullptr;

    int myIndex = 0;
};

class Table {
public:
    Table(int size, int startPos) :
        tableToString(string(size, 'O')),
        nowNode(startPos)
    {
        table = vector<Node>(size);

        for (int index = 0; index < size - 1; ++index)
        {
            // 현재 인덱스의 노드와 다음 인덱스의 노드를 연결지어줌
            table[index].NextLink(&table[index + 1]);
            table[index + 1].myIndex = index + 1;

            table[index].myIndex = index;
        }
    }
    
    // 현재 위치에서 다음 노드로 count 만큼 이동
    void MoveNext(int count)
    {
        Node* now = &table[nowNode];

        for (int i = 0; i < count; ++i)
        {
            now = now->next;
        }

        nowNode = now->myIndex;
    }

    // 현재 위치에서 이전 노드로 count 만큼 이동
    void MovePrev(int count)
    {
        Node* now = &table[nowNode];

        for (int i = 0; i < count; ++i)
        {
            now = now->prev;
        }

        nowNode = now->myIndex;
    }

    void Delete()
    {
        Node* prev = table[nowNode].prev;
        Node* next = table[nowNode].next;

        record.push(nowNode);
        tableToString[nowNode] = 'X';

        // 다음 노드가 존재할 경우
        if (next != nullptr)
        {
            // 이전 노드와 다음 노드를 연결 시켜준뒤
            next->PrevLink(prev);
            // 현재 노드의 위치를 다음 노드의 인덱스로 정해준다.
            nowNode = next->myIndex;
        }
        // 다음 노드가 존재하지 않을 경우
        else if (prev != nullptr)
        {
            // 이전 노드와 다음 노드(nullpter)를 연결 시켜준뒤
            prev->NextLink(next);
            // 현재 노드의 위치를 이전 노드의 인덱스로 정해준다.
            nowNode = prev->myIndex;
        }
        /* 
            1. 그 외의 다음노드 / 이전 노드가 nullptr인 경우 ( 단독 노드만이 존재할 경우 )
             => Delete가 호출되지 않기에 따로 처리하지 않음( 테이블이 존재하지 않는 경우는 주어지지 않음 )
        */
    }

    void Rollback()
    {
        // 삭제기록의 최상단 데이터를 읽어온다
        int lastestDeleteNode = record.top();
        record.pop();

        /*
            2. 삭제된 노드의 경우 next, prev가 유지돼있다. 
             => 현재의 노드가 롤백된 경우 next, prev의 노드가 달라질 경우가 X 
        */
        Node* prev = table[lastestDeleteNode].prev;
        Node* next = table[lastestDeleteNode].next;

        // next가 nullptr가 아닌 경우 현재 노드와 next노드를 연결 
        if (next != nullptr)
        {
            next->PrevLink(&table[lastestDeleteNode]);
        }
        // prev가 nullptr가 아닌 경우 현재 노드와 prev노드를 연결 
        if (prev != nullptr)
        {
            prev->NextLink(&table[lastestDeleteNode]);
        }

        tableToString[lastestDeleteNode] = 'O';
    }

    string ToString() const
    {
        return tableToString;
    }

private:
    vector<Node> table;
    stack<int> record;
    string tableToString;
    int nowNode = 0;
};

string solution(int n, int k, vector<string> cmds) {
    Table table(n, k);
   
    for (const string& cmd : cmds)
    {
        switch (cmd[0])
        {
        case 'U':
            table.MovePrev(stoi(cmd.substr(2)));
            break;

        case 'D':
            table.MoveNext(stoi(cmd.substr(2)));
            break;

        case 'C':
            table.Delete();
            break;

        case 'Z':
            table.Rollback();
            break;
        }
    }

    return table.ToString();
}


/*
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
*/

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