/*
    https://school.programmers.co.kr/learn/courses/30/lessons/76503
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct node {
    vector<int> next;
    int parent;
    bool isLeaf = false;
};

vector<node> tree;
vector<int> leaves;

void generateTree(int index, int before)
{
    tree[index].parent = before;

    for (int i : tree[index].next)
    {
        if (i != before)
        {
            generateTree(i, index);
        }
    }

    if (tree[index].next.size() == 1 && index != 0)
    {
        tree[index].isLeaf = true;
    }
}

long long scount = 0;
void DFS(vector<long long>& a, long long index)
{
    long long result = 0;
    if (tree[index].isLeaf)
    {
        return;
    }
    
    for (int i : tree[index].next)
    {
        if (i == tree[index].parent)
        {
            continue;
        }
        DFS(a, i);
        a[index] += a[i];
        scount += abs(a[i]);
        a[i] = 0;
    }

    return;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -2;
    tree = vector<node>(a.size());

    long long sumOfa = 0;
    vector<long long> ll;
    for (int i : a)
    {
        ll.push_back(static_cast<long long>(i));
        sumOfa += static_cast<long long>(i);
    }

    if (sumOfa != 0)
    {
        return -1;
    }

    for (vector<int>& edge : edges)
    {
        tree[edge[0]].next.push_back(edge[1]);
        tree[edge[1]].next.push_back(edge[0]);
    }

    for (int i : tree[0].next)
    {
        generateTree(i, 0);
    }

    DFS(ll, 0);
    return scount;
}

int main()
{
    solution({ -2, 8, -5, -5, -3, 0, 5, 2 }, { {0, 1}, {0, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7} });
}