/*	
	https://programmers.co.kr/learn/courses/30/lessons/12916
*/

#include <string>

#define IS_P(x) x == 'P' || x == 'p'
#define IS_Y(x) x == 'Y' || x == 'y'

using namespace std;

bool solution(string s)
{
    int countofP = 0, countofY = 0;

    for (const char c : s) 
    {
        if (IS_P(c))
        {
            ++countofP;
        }
        else if (IS_Y(c))
        {
            ++countofY;
        }
    }

    return countofP == countofY;
}