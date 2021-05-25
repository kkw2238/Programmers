/*
	https://programmers.co.kr/learn/courses/30/lessons/12909
*/

#include <string>

using namespace std;

bool solution(string s)
{
    int leftCount = 0; 
    int rightCount = 0;

    for (const char c : s)
    {
        switch (c)
        {
        case '(':
            ++leftCount;
            break;

        case ')':
            ++rightCount;
            break;
        }

        if (rightCount > leftCount)
        {
            return false;
        }
    }

    return true;
}

// 예전 코드
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//bool solution(string s)
//{
//	int left = 0, right = 0;
//
//	for (char c : s) {
//		(c == '(') ? ++left : ++right;
//		if (right > left) return false;
//	}
//
//	return left == right;
//}