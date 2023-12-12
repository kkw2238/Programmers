/*
    https://school.programmers.co.kr/learn/courses/30/lessons/250135
*/

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int beginSec = h1 * 3600 + m1 * 60 + s1;
    int endSec = h2 * 3600 + m2 * 60 + s2;
    const int n = 60 * 60 * 12;

    int answer = 0;
    int dh = h1 * 3600 + m1 * 60 + s1;
    int dm = m1 * 720 + s1 * 12;
    int ds = s1 * 720;

    bool isMSkip = ds > dm, isHSkip = ds > dh;

    for (int t = beginSec; t <= endSec; ++t)
    {
        if (dm == dh)
        {
            ++answer;

            isMSkip = true;
            isHSkip = true;
        }

        if (dm != dh && !isMSkip && ds > dm )
        {
            ++answer;
            isMSkip = true;
        }
        if (dm != dh && !isHSkip && ds > dh)
        {
            ++answer;
            isHSkip = true;
        }

        dh = (dh + 1) % n;
        dm = (dm + 24) % n;
        ds = (ds + 720) % n;

        if (ds == 0)
        {
            isMSkip = false;
            isHSkip = false;
        }
    }

    return answer;
}

int main()
{
    solution(11, 58, 59, 11, 59, 0);
}