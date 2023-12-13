/*
    https://school.programmers.co.kr/learn/courses/30/lessons/250135
*/

using namespace std;

int nesting(int h, int m, int s, bool& isMSkip, bool& isHSkip)
{
    int result = 0;

    if (m == h && s == m)
    {
        isMSkip = true;
        isHSkip = true;

        return 1;
    }

    if (!isMSkip && s >= m)
    {
        ++result;
        isMSkip = true;
    }
    if (!isHSkip && s >= h)
    {
        ++result;
        isHSkip = true;
    }

    return result;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int beginSec = h1 * 3600 + m1 * 60 + s1;
    int endSec = h2 * 3600 + m2 * 60 + s2;

    const int n = 60 * 60 * 12;
    const int offset[3]{ 1, 12, 720 };

    int answer = 0;

    int dh = (h1 * 3600 + m1 * 60 + s1) % n;
    int dm = (m1 * 720 + s1 * 12) % n;
    int ds = (s1 * 720) % n;

    bool isMSkip = ds > dm, isHSkip = ds > dh;

    answer += nesting(dh, dm, ds, isMSkip, isHSkip);

    for (int t = beginSec; t < endSec; ++t)
    {
        dh += offset[0];
        dm += offset[1];
        ds += offset[2];

        answer += nesting(dh, dm, ds, isMSkip, isHSkip);

        dh = dh % n;
        dm = dm % n;
        ds = ds % n;

        if (ds == 0)
        {
            isMSkip = ds == dm;
            isHSkip = ds == dh;
        }
    }

    return answer;
}