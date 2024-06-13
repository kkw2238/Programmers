/*
    https://programmers.co.kr/learn/courses/30/lessons/86971
*/

#include <vector>
#include <algorithm>

using namespace std;

enum { To, From };

struct Node {
    vector<int> linkedNodeIndex;
    int childcount = 0;
};

int RegenerateTree(vector<Node>& node, int index, int beforeIndex)
{
    if (node[index].linkedNodeIndex.size() == 1)
    {
        return 1;
    }

    for (int nextIndex : node[index].linkedNodeIndex)
    {
        if (nextIndex != beforeIndex) 
        {
            node[index].childcount += RegenerateTree(node, nextIndex, index);
        }
    }

    return node[index].childcount;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<Node> tree(n);

    for (vector<int>& wire : wires)
    {
        tree[wire[To] - 1].linkedNodeIndex.push_back(wire[From] - 1);
        tree[wire[From] - 1].linkedNodeIndex.push_back(wire[To] - 1);
    }

    int total = RegenerateTree(tree, 0, -1);
    if (total != n)
    {
        return total;
    }

    for (int i = 1; i < n; ++i)
    {
        int gap = tree[0].childcount - tree[i].childcount * 2;
        answer = min(gap < 0 ? -gap : gap, tree[i].childcount);
    }

    return answer;
}