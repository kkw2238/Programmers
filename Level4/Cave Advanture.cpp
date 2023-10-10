/*
	https://school.programmers.co.kr/learn/courses/30/lessons/67260
*/

#include <queue>
#include <vector>

using namespace std;

struct Node {
    bool isLock = false, isWait = false;
    int parents, now;
    vector<int> children;

    void generate(vector<Node>& tree, int p)
    {
        parents = p;

        for (int i : children)
        {
            if (i == parents)
            {
                continue;
            }
            tree[i].generate(tree, now);
        }
    }
};

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    vector<Node> tree(n + 1);
    vector<int> quest(n + 1, -1);
    queue<int> q;

    q.push(0);

    int waitCount = 0;

    bool answer = true;
    for (vector<int>& p : path)
    {
        tree[p[0]].children.push_back(p[1]);
        tree[p[0]].now = p[0];
        tree[p[1]].children.push_back(p[0]);
        tree[p[1]].now = p[1];
    }

    for (vector<int>& o : order)
    {
        quest[o[0]] = o[1];
        tree[o[1]].isLock = true;
    }

    tree[0].generate(tree, 0);

    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        if (tree[index].isLock)
        {
            tree[index].isWait = true;
            ++waitCount;
            continue;
        }

        if (quest[index] != -1)
        {
            tree[quest[index]].isLock = false;
            if (tree[quest[index]].isWait)
            {
                tree[quest[index]].isWait = false;
                --waitCount;
                q.push(quest[index]);
            }
        }

        for (int i : tree[index].children)
        {
            if (i != tree[index].parents)
            {
                q.push(i);
            }
        }
    }

    return waitCount == 0;
}