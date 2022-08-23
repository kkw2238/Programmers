/*
	https://programmers.co.kr/learn/courses/30/lessons/1844
*/

#include <vector>
#include <queue>

using namespace std;

const int MAXIMUM_MOVECOUNT = 10000;
int map_Width = 0;
int map_Height = 0;

struct Node {
    int x;
    int y;
    int moveCount;
    
    Node(int newX, int newY, int newMoveCount) :
        x(newX), y(newY), moveCount(newMoveCount)
    {   }

    // moveCount ���� ������������ ����
    const bool operator<(const Node& other) const
    {
        return moveCount > other.moveCount;
    }
};

// �� ���� ���ο� �ִ��� �Ǻ� 
const bool InWidth(const int xPos)
{
    return xPos >= 0 && xPos < map_Width;
}

// �� ���� ���ο� �ִ��� �Ǻ�
const bool InHeight(const int yPos)
{
    return yPos >= 0 && yPos < map_Height;
}

int solution(vector<vector<int>> maps)
{
    map_Width = maps[0].size();
    map_Height = maps.size();

    priority_queue<Node> queue;
    vector<vector<int>> footPrint(map_Height, vector<int>(map_Width, MAXIMUM_MOVECOUNT));
    const int X_OFFSET[4]{ -1, 0, 0, 1 };
    const int Y_OFFSET[4]{ 0, 1, -1, 0 };

    // ���� ��ġ, ���� �� ����
    queue.emplace(0, 0, 1);
    
    // BFS 
    while (!queue.empty())
    {
        Node nowNode = queue.top();
        queue.pop();

        if (nowNode.moveCount > footPrint[nowNode.y][nowNode.x])
        {
            continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            const int xPos = nowNode.x + X_OFFSET[i];
            const int yPos = nowNode.y + Y_OFFSET[i];
            const int nextMoveCount = nowNode.moveCount + 1;

            // �� ���ο� �ְ� && ������ �� ������ && �ش� ��ġ ���� �� ���� ���� ��� �̵�
            if (InWidth(xPos) && InHeight(yPos) && maps[yPos][xPos] != 0 && footPrint[yPos][xPos] > nextMoveCount)
            {
                // �����븦 �����.
                footPrint[yPos][xPos] = nextMoveCount;
                queue.emplace(nowNode.x + X_OFFSET[i], nowNode.y + Y_OFFSET[i], nextMoveCount);
            }
        }
    }
    
    // �������� ���� ���
    if (footPrint[map_Height - 1][map_Width - 1] == MAXIMUM_MOVECOUNT)
    {
        return -1;
    }

    // ������ ���
    return footPrint[map_Height - 1][map_Width - 1];
}

//#include <vector>
//#include <queue>
//using namespace std;
//
//struct FindingNode
//{
//    int x;
//    int y;
//    int moveCount;
//};
//
//const int MAXIMUM_FOOTCOUNT = 10000;
//vector<vector<int>> footPrints;
//vector<vector<int>> tmpFootPrints;
//
//// [y][x]�� ����
//
//bool IsEnableMove(const vector<vector<int>>& maps, int x, int y, int moveCount)
//{
//    // �� ������ ��� ���
//    if ((x < 0 || y < 0) || (x >= maps[0].size() || y >= maps.size()))
//    {
//        return false;
//    }
//
//    // �̵��ϰ��� �ϴ� ��ġ�� �̹� ������ ���� ���
//    if (moveCount >= footPrints[y][x])
//    {
//        return false;
//    }
//
//    return maps[y][x] != 0;
//}
//
//
//#include <iostream>
//
//int solution(vector<vector<int>> maps)
//{
//    int answer = 0;
//
//    queue<FindingNode> findNode;
//
//    // �� �� �� ��
//    const int X_MOVE[4] = { 0, 0, -1, 1 };
//    const int Y_MOVE[4] = { -1, 1, 0, 0 };
//
//    footPrints = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), MAXIMUM_FOOTCOUNT));
//    tmpFootPrints = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), MAXIMUM_FOOTCOUNT));
//    findNode.push(FindingNode{ .moveCount = 1 });
//
//    while(!findNode.empty())
//    { 
//        FindingNode node = findNode.front();
//        findNode.pop();
//
//        if (node.moveCount > tmpFootPrints[node.y][node.x])
//        {
//            continue;
//        }
//
//        footPrints[node.y][node.x] = node.moveCount;
//
//        for (int i = 0; i < 4; ++i) 
//        {
//            if (IsEnableMove(maps, node.x + X_MOVE[i], node.y + Y_MOVE[i], node.moveCount + 1))
//            {
//                if (tmpFootPrints[node.y + Y_MOVE[i]][node.x + X_MOVE[i]] > node.moveCount + 1) 
//                {
//                    findNode.push({ node.x + X_MOVE[i], node.y + Y_MOVE[i], node.moveCount + 1 });
//                    tmpFootPrints[node.y + Y_MOVE[i]][node.x + X_MOVE[i]] = node.moveCount + 1;
//                }
//            }
//        }
//    }
//
//    answer = footPrints[footPrints.size() - 1][footPrints[0].size() - 1];
//
//    if (answer == MAXIMUM_FOOTCOUNT)
//    {
//        return -1;
//    }
//
//    return answer;
//}