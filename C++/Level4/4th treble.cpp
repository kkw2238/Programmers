/*
	https://school.programmers.co.kr/learn/courses/30/lessons/1831
*/


int getTrebleCount(const long long& dest, long long treble, int starCount, int plusCount)
{
    if (plusCount > (starCount * 2) || treble > dest || (treble * 3) > dest)
    {
        return 0;
    }
    else if (dest == treble)
    {
        if (starCount * 2 == plusCount)
        {
            return 1;
        }
        return 0;
    }

    return getTrebleCount(dest, treble * 3, starCount + 1, plusCount)
        + getTrebleCount(dest, treble + 1, starCount, plusCount + 1);
}

#include <queue>

using namespace std;

struct Node {
    long long treble;
    int starCount;
    int plusCount;
};

int solution(int n) {
    int answer = 0;
    queue<Node> q;

    q.push({ 3, 1, 0 });

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        if (node.treble == (long long)n)
        {
            if (node.starCount * 2 == node.plusCount)
            {
                ++answer;
            }
            continue;
        }

        if (node.treble * 3 <= (long long)n)
        {
            q.push({ node.treble * 3, node.starCount + 1, node.plusCount });
        }
        if ((node.treble + 1) <= (long long)n && node.starCount * 2 > node.plusCount)
        {
            q.push({ node.treble + 1, node.starCount, node.plusCount + 1 });
        }
    }

    return answer;
}

int main()
{
    solution(2147483647);
}