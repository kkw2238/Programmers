/*
	https://programmers.co.kr/learn/courses/30/lessons/12901
*/

#include <string>

using namespace std;

const int DAY_COUNT = 7;
const int MONTH_COUNT = 12;

string solution(int a, int b) {
    const string DAYS[DAY_COUNT] = { "THU", "FRI","SAT", "SUN","MON","TUE","WED" };
    const int DAYS_IN_MONTH[MONTH_COUNT] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int totalDays = 0;
    
    for (int i = 0; i < a - 1; ++i)
    {
        totalDays += DAYS_IN_MONTH[i];
    }
    totalDays += b;

    return DAYS[totalDays / DAY_COUNT];
}