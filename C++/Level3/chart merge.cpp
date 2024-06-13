/*
	https://school.programmers.co.kr/learn/courses/30/lessons/150366
*/

#include <string>
#include <vector>

using namespace std;

struct Node {
    Node* parent = this;
    vector<Node*> children;
    string str = "";
};

vector<vector<Node>> board(51, vector<Node>(51));

Node* select(int r1, int c1)
{
    return board[r1][c1].parent;
}

void merge(int r1, int c1, int r2, int c2)
{
    Node* cell1 = select(r1, c1);
    Node* cell2 = select(r2, c2);

    if (cell1 == cell2)
    {
        return;
    }

    for (Node* child : cell2->children)
    {
        child->parent = cell1;
        cell1->children.push_back(child);
    }

    cell1->children.push_back(cell2);
    cell2->parent = cell1;
    cell2->children.clear();

    if (cell1->str.empty())
    {
        cell1->str = cell2->str;
    }
    cell2->str = "";
}

void unmerge(int r1, int c1)
{
    Node* cell = select(r1, c1);
    string str = cell->str;
    cell->str = "";

    for (Node* child : cell->children)
    {
        child->parent = child;
    }
    cell->children.clear();
    cell = select(r1, c1);
    cell->str = str;
}

void update(int r1, int c1, string& replace)
{
    Node* cell = select(r1, c1);
    cell->str = replace;
}

void update(string& target, string& replace)
{
    for (int i = 1; i <= 50; ++i)
    {
        for (int j = 1; j <= 50; ++j)
        {
            Node* cell = select(i, j);
            if (cell->str == target)
            {
                cell->str = replace;
            }
        }
    }
}

vector<string> split(string& str)
{
    vector<string> result;
    str += " ";
    int before = 0;
    int index = str.find(' ');

    while (index != string::npos)
    {
        result.push_back(str.substr(before, index - before));
        
        before = index + 1;
        index = str.find(' ', index + 1);
    }

    return result;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    for (int i = 1; i <= 50; ++i)
    {
        for (int j = 1; j <= 50; ++j)
        {
            board[i][j].parent = &board[i][j];
            board[i][j].children.clear();
        }
    }

    for (string& command : commands)
    {
        vector<string> strings = split(command);
        if (strings[0] == "UPDATE")
        {
            if (strings.size() == 3)
            {
                update(strings[1], strings[2]);
            }
            else
            {
                update(stoi(strings[1]), stoi(strings[2]), strings[3]);
            }
        }
        else if (strings[0] == "MERGE")
        {
            merge(stoi(strings[1]), stoi(strings[2]), stoi(strings[3]), stoi(strings[4]));
        }
        else if (strings[0] == "UNMERGE")
        {
            unmerge(stoi(strings[1]), stoi(strings[2]));
        }
        else if (strings[0] == "PRINT")
        {
            string str = select(stoi(strings[1]), stoi(strings[2]))->str;
            if (str.empty())
            {
                str = "EMPTY";
            }
            answer.push_back(str);
        }
    }

    return answer;
}