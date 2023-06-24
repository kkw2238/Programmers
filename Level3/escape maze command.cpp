/*
	https://school.programmers.co.kr/learn/courses/30/lessons/150365?language=cpp
*/

#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Node {
    int x, y;
    string str;
};

class Compare {
public:
    const bool operator()(Node& a, Node& b)
    {
        return a.str > b.str;
    }
};

bool isAble(int x, int y, int r, int c, int k)
{
    int range = abs(r - x) + abs(c - y);
    return (range % 2 == k % 2) && range <= k;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    priority_queue<Node, vector<Node>, Compare> pq;

    if (!isAble(x, y, r, c, k))
    {
        return "impossible";
    }

    pq.push({ x, y, "" });

    while (!pq.empty())
    {
        Node top = pq.top();
        pq.pop();

        if (top.x == r && top.y == c && top.str.length() == k)
        {
            return top.str;
        }
        else if (isAble(top.x, top.y, r, c, k - top.str.length()))
        {
            if ((top.x - 1) > 0)
            {
                pq.push({ top.x , top.y - 1, top.str + "d" });
            }
            if ((top.x + 1) <= n)
            {
                pq.push({ top.x , top.y + 1, top.str + "u" });
            }
            if ((top.y - 1) > 0)
            {
                pq.push({ top.x - 1, top.y, top.str + "l" });
            }
            if ((top.y + 1) <= m)
            {
                pq.push({ top.x + 1, top.y, top.str + "r" });
            }
            
        }
    }

    return "impossible";
}