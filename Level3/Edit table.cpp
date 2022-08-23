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
            // ���� �ε����� ���� ���� �ε����� ��带 ����������
            table[index].NextLink(&table[index + 1]);
            table[index + 1].myIndex = index + 1;

            table[index].myIndex = index;
        }
    }
    
    // ���� ��ġ���� ���� ���� count ��ŭ �̵�
    void MoveNext(int count)
    {
        Node* now = &table[nowNode];

        for (int i = 0; i < count; ++i)
        {
            now = now->next;
        }

        nowNode = now->myIndex;
    }

    // ���� ��ġ���� ���� ���� count ��ŭ �̵�
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

        // ���� ��尡 ������ ���
        if (next != nullptr)
        {
            // ���� ���� ���� ��带 ���� �����ص�
            next->PrevLink(prev);
            // ���� ����� ��ġ�� ���� ����� �ε����� �����ش�.
            nowNode = next->myIndex;
        }
        // ���� ��尡 �������� ���� ���
        else if (prev != nullptr)
        {
            // ���� ���� ���� ���(nullpter)�� ���� �����ص�
            prev->NextLink(next);
            // ���� ����� ��ġ�� ���� ����� �ε����� �����ش�.
            nowNode = prev->myIndex;
        }
        /* 
            1. �� ���� ������� / ���� ��尡 nullptr�� ��� ( �ܵ� ��常�� ������ ��� )
             => Delete�� ȣ����� �ʱ⿡ ���� ó������ ����( ���̺��� �������� �ʴ� ���� �־����� ���� )
        */
    }

    void Rollback()
    {
        // ��������� �ֻ�� �����͸� �о�´�
        int lastestDeleteNode = record.top();
        record.pop();

        /*
            2. ������ ����� ��� next, prev�� �������ִ�. 
             => ������ ��尡 �ѹ�� ��� next, prev�� ��尡 �޶��� ��찡 X 
        */
        Node* prev = table[lastestDeleteNode].prev;
        Node* next = table[lastestDeleteNode].next;

        // next�� nullptr�� �ƴ� ��� ���� ���� next��带 ���� 
        if (next != nullptr)
        {
            next->PrevLink(&table[lastestDeleteNode]);
        }
        // prev�� nullptr�� �ƴ� ��� ���� ���� prev��带 ���� 
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