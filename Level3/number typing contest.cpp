/*
	https://school.programmers.co.kr/learn/courses/30/lessons/136797
*/

//#include <string>
//#include <queue>
//
//using namespace std;
//
//int distan[10][10];
//
//class node {
//public:
//    int lpos, rpos, index, count;
//};
//
//class Compare {
//public:
//    const bool operator()(const node& l, const node& r) const {
//        return l.count > r.count;
//    }
//};
//
//int dist(int now, int next)
//{
//    int dist = 0;
//
//    if (next == 10)
//    {
//        next += 1;
//    }
//    if (now == 10)
//    {
//        now += 1;
//    }
//
//    int xOffset = abs((next - 1) % 3 - (now - 1) % 3);
//    int yOffset = abs((next - 1) / 3 - (now - 1) / 3);
//
//    if (xOffset > 0 && yOffset > 0)
//    {
//        int near = min(xOffset, yOffset);
//        dist += near * 3;
//
//        xOffset -= near;
//        yOffset -= near;
//    }
//
//    return dist + (xOffset + yOffset) * 2;
//}
//
//
//int solution(string numbers) {
//    int answer = 2147483647;
//    priority_queue<node, vector<node>, Compare> qn;
//    qn.push({ 4, 6, 0, 0 });
//
//    for (int i = 1; i <= 10; ++i)
//    {
//        distan[i % 10][i % 10] = 1;
//        for (int j = i + 1; j <= 10; ++j)
//        {
//            int count = dist(i, j);
//            distan[i % 10][j % 10] = count;
//            distan[j % 10][i % 10] = count;
//        }
//    }
//
//    while (!qn.empty())
//    {
//        node n = qn.top();
//        qn.pop();
//
//        if (n.index == numbers.size())
//        {
//            return n.count;            
//        }
//        else if (n.count >= answer)
//        {
//            continue;
//        }
//
//        int next = numbers[n.index] - '0';
//        if (n.lpos == next || n.rpos == next)
//        {
//            ++n.count;
//            ++n.index;
//            qn.push(n);
//        }
//        else
//        {
//            qn.push({ next, n.rpos, n.index + 1, n.count + distan[n.lpos][next] });
//            qn.push({ n.lpos, next, n.index + 1, n.count + distan[n.rpos][next] });
//        }
//    }
//
//    return answer;
//}

#include <string>

using namespace std;

int distan[10][10];
int ct[100001][10][10];

int dist(int now, int next)
{
    int dist = 0;

    next == 10 ? next + 1 : next;
    now == 10 ? now + 1 : now;

    int xOffset = abs((next - 1) % 3 - (now - 1) % 3);
    int yOffset = abs((next - 1) / 3 - (now - 1) / 3);

    if (xOffset > 0 && yOffset > 0)
    {
        int near = min(xOffset, yOffset);
        dist += near * 3;

        xOffset -= near;
        yOffset -= near;
    }

    return dist + (xOffset + yOffset) * 2;
}

int solution(string numbers) {
    const int maximum = 1000000;
    int answer = maximum;
    for (int i = 1; i <= 10; ++i)
    {
        distan[i % 10][i % 10] = 1;
        for (int j = i + 1; j <= 10; ++j)
        {
            int count = dist(i, j);
            distan[i % 10][j % 10] = count;
            distan[j % 10][i % 10] = count;
        }
    }

    for (int i = 0; i <= numbers.size(); ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                ct[i][j][k] = maximum;
            }
        }
    }

    ct[0][numbers[0] - '0'][6] = distan[numbers[0] - '0'][4];
    ct[0][4][numbers[0] - '0'] = distan[numbers[0] - '0'][6];
    
    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        int next = numbers[i + 1] - '0';
        int now = numbers[i] - '0';

        for (int j = 0; j < 10; ++j)
        {
            if (ct[i][j][now] != maximum)
            {
                if (j != next)
                {
                    int rHandDist = distan[now][next];
                    ct[i + 1][j][next] = min(ct[i + 1][j][next], ct[i][j][now] + rHandDist);
                }
                if (now != next)
                {
                    int lHandDist = distan[j][next];
                    ct[i + 1][next][now] = min(ct[i + 1][next][now], ct[i][j][now] + lHandDist);
                }
            }
            if(ct[i][now][j] != maximum)
            {
                if (now != next)
                {
                    int rHandDist = distan[j][next];
                    ct[i + 1][now][next] = min(ct[i + 1][now][next], ct[i][now][j] + rHandDist);
                }
                if (j != next)
                {
                    int lHandDist = distan[now][next];
                    ct[i + 1][next][j] = min(ct[i + 1][next][j], ct[i][now][j] + lHandDist);
                }
            }   
        }
    }

    int lastNum = numbers.back() - '0';

    for (int j = 0; j < 10; ++j)
    {
        answer = min(answer, ct[numbers.size() - 1][j][lastNum]);
        answer = min(answer, ct[numbers.size() - 1][lastNum][j]);
    }
    return answer;
}