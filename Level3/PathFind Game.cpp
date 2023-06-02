/*
	https://school.programmers.co.kr/learn/courses/30/lessons/42892
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int index;
    int x;
};

void preorder(Node* nowNode, vector<int>& container)
{
    container.push_back(nowNode->index);

    if (nowNode->left != nullptr)
    {
        preorder(nowNode->left, container);
    }
    if (nowNode->right != nullptr)
    {
        preorder(nowNode->right, container);
    }
}

void postorder(Node* nowNode, vector<int>& container)
{
    if (nowNode->left != nullptr)
    {
        postorder(nowNode->left, container);
    }
    if (nowNode->right != nullptr)
    {
        postorder(nowNode->right, container);
    }

    container.push_back(nowNode->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>());
    Node root;

    for (int i = 0; i < nodeinfo.size(); ++i)
    {
        nodeinfo[i].push_back(i + 1);
    }

    sort(nodeinfo.begin(), nodeinfo.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });

    root.index = nodeinfo[0][2];
    root.x = nodeinfo[0][0];

    for (int i = 1; i < nodeinfo.size(); ++i)
    {
        Node* now = &root;
        while (true)
        {
            if (nodeinfo[i][0] > now->x)
            {
                if (now->right == nullptr)
                {
                    Node* newNode = new Node{ nullptr, nullptr, nodeinfo[i][2], nodeinfo[i][0] };
                    now->right = newNode;
                    break;
                }
                else
                {
                    now = now->right; 
                }
            }
            else if(nodeinfo[i][0] < now->x)
            {
                if (now->left == nullptr)
                {
                    Node* newNode = new Node{ nullptr, nullptr, nodeinfo[i][2], nodeinfo[i][0] };
                    now->left = newNode;
                    break;
                }
                else
                {
                    now = now->left;
                }
            }
        }
    }

    preorder(&root, answer[0]);
    postorder(&root, answer[1]);

    return answer;
}