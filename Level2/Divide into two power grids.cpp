#include <vector>

using namespace std;

struct Node
{
    vector<Node> children;
    bool isParent = false;
    int childCount = 0;
    int parentIndex = -1;
};

int ReGenerationChildCount(Node* nowNode)
{
    for (Node& child : nowNode->children)
    {
        nowNode->childCount += ReGenerationChildCount(&child);
    }

    nowNode->childCount += nowNode->children.size();
    return nowNode->childCount;
}

int solution(int n, vector<vector<int>> wires) {
    vector<Node> tree(n);
    Node* root = nullptr;

    root = &tree[wires[0][0] - 1];
    root->isParent = true;

    for (vector<int>& wire : wires)
    {
        if (tree[wire[0]].isParent == false && tree[wire[1]].isParent == true)
        {
            swap(wire[0], wire[1]);
        }
        tree[wire[0]].children.push_back(tree[wire[1]]);
        tree[wire[1]].parentIndex = wire[0];
        tree[wire[0]].isParent = true;
    }

    int total = ReGenerationChildCount(root);

    return total;
}

int main()
{
    solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}} );
}