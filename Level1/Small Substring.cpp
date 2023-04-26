/*
	https://school.programmers.co.kr/learn/courses/30/lessons/147355
*/

#include <string>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int pLeng = p.size();
    long long pNum = stoll(p);

    for (int i = 0; i <= (t.length() - pLeng); ++i)
    {
        if (pNum >= stoll(t.substr(i, pLeng)))
        {
            ++answer;
        }
    }

    return answer;
}