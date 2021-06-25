/*
    https://programmers.co.kr/learn/courses/30/lessons/12973
*/

#include <string>

using namespace std;

int solution(string s)
{
    for (int i = 0; i < (int)(s.length()) - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            i = -1;
        }
    }

    return s.empty();
}

int main()
{
    solution("baabaa");
}

//#include <string>
//#include <stack>
//using namespace std;
//
//int solution(string s)
//{
//	stack<char> sList;
//	sList.push(s[0]);
//
//	for (int i = 1; i < s.size(); ++i) {
//		if (!sList.empty() && sList.top() == s[i]) {
//			sList.pop();
//		}
//		else {
//			sList.push(s[i]);
//		}
//	}
//
//	return sList.empty() ? 1 : 0;
//}