/*
	https://school.programmers.co.kr/learn/courses/30/lessons/148653?language=cpp
*/
#include <utility>

using namespace std;

const int COUNTS[11] = { 0, 1, 2, 3, 4, 5, 5, 4, 3, 2, 0 };

int findMinimum(int storey, int count)
{
    int index = storey % 10;
    if (storey < 10)
    {
        return count + COUNTS[index];
    }

    int add10 = 100;
    int standard = 0;

    if (index > 5)
    {
        add10 = findMinimum((storey + 10) / 10, count + COUNTS[index] - 1);
    }
    else if(index != 0)
    {
        add10 = findMinimum((storey + 10) / 10, count + 10 - index);
    }

    standard = findMinimum(storey / 10, count + COUNTS[index]);
    return min(add10, standard);
}

int solution(int storey) {
    return findMinimum(storey, 0);
}