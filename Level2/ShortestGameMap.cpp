#include <vector>
#include <queue>
using namespace std;

struct FindingNode
{
    int x;
    int y;
    int moveCount;
};

const int MAXIMUM_FOOTCOUNT = 10000;
vector<vector<int>> footPrints;
vector<vector<int>> tmpFootPrints;

// [y][x]�� ����

bool IsEnableMove(const vector<vector<int>>& maps, int x, int y, int moveCount)
{
    // �� ������ ��� ���
    if ((x < 0 || y < 0) || (x >= maps[0].size() || y >= maps.size()))
    {
        return false;
    }

    // �̵��ϰ��� �ϴ� ��ġ�� �̹� ������ ���� ���
    if (moveCount >= footPrints[y][x])
    {
        return false;
    }

    return maps[y][x] != 0;
}


#include <iostream>

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    queue<FindingNode> findNode;

    // �� �� �� ��
    const int X_MOVE[4] = { 0, 0, -1, 1 };
    const int Y_MOVE[4] = { -1, 1, 0, 0 };

    footPrints = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), MAXIMUM_FOOTCOUNT));
    tmpFootPrints = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), MAXIMUM_FOOTCOUNT));
    findNode.push(FindingNode{ .moveCount = 1 });

    while(!findNode.empty())
    { 
        FindingNode node = findNode.front();
        findNode.pop();

        if (node.moveCount > tmpFootPrints[node.y][node.x])
        {
            continue;
        }

        footPrints[node.y][node.x] = node.moveCount;

        for (int i = 0; i < 4; ++i) 
        {
            if (IsEnableMove(maps, node.x + X_MOVE[i], node.y + Y_MOVE[i], node.moveCount + 1))
            {
                if (tmpFootPrints[node.y + Y_MOVE[i]][node.x + X_MOVE[i]] > node.moveCount + 1) 
                {
                    findNode.push({ node.x + X_MOVE[i], node.y + Y_MOVE[i], node.moveCount + 1 });
                    tmpFootPrints[node.y + Y_MOVE[i]][node.x + X_MOVE[i]] = node.moveCount + 1;
                }
            }
        }
    }

    answer = footPrints[footPrints.size() - 1][footPrints[0].size() - 1];

    if (answer == MAXIMUM_FOOTCOUNT)
    {
        return -1;
    }

    return answer;
}


int main()
{
    vector<vector<int>> maps{ 
        { 1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}
    };
    cout << solution(maps);
}