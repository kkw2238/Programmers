/*
	https://school.programmers.co.kr/learn/courses/30/lessons/92343?language=cpp
*/

//#include <string>
//#include <vector>
//#include <map>
//#include <bitset>
//#include <algorithm>
//
//using namespace std;
//
//struct node {
//    int parent = -1;
//    vector<int> children;
//};
//
//void linkDFS(int now, int before, vector<node>& tree, map<int, vector<int>>& linked)
//{
//    tree[now].parent = before;
//
//    for (int i : linked[now])
//    {
//        if (i != before)
//        {
//            tree[now].children.push_back(i);
//            linkDFS(i, now, tree, linked);
//        }
//    }
//}
//
//int getCount(vector<int>& perpumation, vector<node>& tree, vector<int>& info)
//{
//    int counts[2]{ 1, 0 };
//    bool visited[18]{ false };
//
//    visited[0] = true;
//
//    for (int i : perpumation)
//    {
//        if (!visited[tree[i].parent])
//        {
//            break;
//        }
//
//        visited[i] = true;
//        ++counts[info[i]];
//
//        if (counts[1] >= counts[0])
//        {
//            return counts[0];
//        }
//    }
//
//    return counts[0];
//}
//
//int solution(vector<int> info, vector<vector<int>> edges) {
//    int answer = 1;
//    vector<node> tree(info.size());
//    vector<int> permutation[2];
//    map<int, vector<int>> linked;
//
//    for (vector<int>& edge : edges)
//    {
//        linked[edge[0]].push_back(edge[1]);
//        linked[edge[1]].push_back(edge[0]);
//
//        if (edge[0] == 0)
//        {
//            tree[0].children.push_back(edge[1]);
//        }
//        else if (edge[1] == 0)
//        {
//            tree[0].children.push_back(edge[0]);
//        }
//    }
//
//    for (int i : linked[0])
//    {
//        linkDFS(i, 0, tree, linked);
//    }
//
//    for (int j = 0; j < 2; ++j)
//    {
//        permutation[j].push_back(tree[0].children[j]);
//        for (int i = 1; i <= info.size() - 1; ++i)
//        {
//            if (i != j)
//            {
//                permutation[j].push_back(i);
//            }
//        }
//    }
//
//    int index = 0;
//
//    do {
//        if (tree[permutation[index][0]].parent != 0)
//        {
//            ++index;
//            continue;
//        }
//        answer = max(getCount(permutation[index], tree, info), answer);
//    } while (index < 2 && next_permutation(permutation[index].begin(), permutation[index].end()));
//    
//    return answer;
//}


//int getCount(bitset<18>& bits, vector<node>& tree, vector<int>& info)
//{
//    bool visited[18] { false };
//    int counts[2] { 0, 0 };
//
//    for (int i = 0; i < tree.size(); ++i)
//    {
//        if (bits[i] && !visited[i])
//        {
//            visited[i] = true;
//            ++counts[info[i]];
//
//            int tmp = tree[i].parent;
//            
//            while (tmp != -1 && !visited[tmp])
//            {
//                visited[tmp] = true;
//                if (!bits[tmp])
//                {
//                    return -1;
//                }
//                
//                ++counts[info[tmp]];
//                tmp = tree[tmp].parent;
//            }
//        }
//    }
//
//    return counts[0] > counts[1] ? counts[0] : -1;
//}


//int solution(vector<int> info, vector<vector<int>> edges) {
//    int answer = 0;
//    vector<node> tree(info.size());
//    map<int, vector<int>> linked;
//
//    for (vector<int>& edge : edges)
//    {
//        linked[edge[0]].push_back(edge[1]);
//        linked[edge[1]].push_back(edge[0]);
//
//        if (edge[0] == 0)
//        {
//            tree[0].children.push_back(edge[1]);
//        }
//        else if (edge[1] == 0)
//        {
//            tree[0].children.push_back(edge[0]);
//        }
//    }
//
//    for (int i : linked[0])
//    {
//        linkDFS(i, 0, tree, linked);
//    }
//
//    int maximum = pow(2, info.size()) - 1;
//    for (int num = 1; num <= maximum; num += 2)
//    {
//        bitset<18> bits(num);
//
//        answer = max(getCount(bits, tree, info), answer);
//    }
//
//    return answer;
//}

#include <vector>
#include <queue>
#include <map>

using namespace std;

struct node {
    int parent = -1;
    vector<int> children;
};

vector<node> tree;
int maximum = 1;

void linkDFS(int now, int before, vector<node>& tree, map<int, vector<int>>& linked)
{
    tree[now].parent = before;

    for (int i : linked[now])
    {
        if (i != before)
        {
            tree[now].children.push_back(i);
            linkDFS(i, now, tree, linked);
        }
    }
}

void DFS(int now, int sheep, int wolves, queue<int> next, const vector<int>& info)
{
    sheep += info[now] ^ 1;
    wolves += info[now];

    maximum = max(maximum, sheep);

    if (sheep > wolves)
    {
        for (int i : tree[now].children)
        {
            next.push(i);
        }
        for (int i = 0; i < next.size(); ++i)
        {
            int nextIndex = next.front();
            next.pop();

            DFS(nextIndex, sheep, wolves, next, info);
            next.push(nextIndex);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    tree = vector<node>(info.size());
    map<int, vector<int>> linked;

    for (vector<int>& edge : edges)
    {
        linked[edge[0]].push_back(edge[1]);
        linked[edge[1]].push_back(edge[0]);

        if (edge[0] == 0)
        {
            tree[0].children.push_back(edge[1]);
        }
        else if (edge[1] == 0)
        {
            tree[0].children.push_back(edge[0]);
        }
    }

    for (int i : linked[0])
    {
        linkDFS(i, 0, tree, linked);
    }

    DFS(0, 0, 0, queue<int>(), info);

    return maximum;
}

int main()
{
    solution({ 0,0,1,1,1,0,1,0,1,0,1,1 }, { {0, 1},{1, 2},{1, 4},{0, 8},{8, 7},{9, 10}, {9, 11}, {4, 3},{6, 5},{4, 6},{8, 9} });
}