/*
    https://programmers.co.kr/learn/courses/30/lessons/12946
*/

#include <vector>

using namespace std;

vector<vector<int>> moveLog;

void move(int to, int from)
{
    moveLog.push_back({ to, from });
}

void hanoi(int count, int from, int to)
{
    if (count == 0)
    {
        return;
    }

    int dest = 6 - to - from;

    hanoi(count - 1, from, dest);
    move(from, to);
    hanoi(count - 1, dest, to);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3);
    return moveLog;
}

/*
    a b c
    a -> b�� n - 1�� �̵� 
    a -> c�� 1�� �̵� 
    b -> a�� n - 1�� �̵�

*/