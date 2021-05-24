/*
	https://programmers.co.kr/learn/courses/30/lessons/17687
*/

#include <string>
#include <vector>

using namespace std;

const int Max_N = 16;
const char Line_Up[Max_N]{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

string MakeNumberToString(int number, int member, int t)
{
    string result;

    for (int i = 1; result.size() >= t * member; ++i)
    {
        int memNum = i;
        string tmpString = "";

        while (memNum > 0)
        {
            tmpString = Line_Up[memNum % number] + tmpString;
            memNum /= number;
        }

        result.append(tmpString);
    }

    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string numbersToString = MakeNumberToString(n, m, t);

    for (int i = 0; i < t; ++i)
    {
        answer.push_back(numbersToString[m * i + p - 1]);
    }

    return answer;
}

// 예전 코드
//#include <string>
//#include <array>
//
//using namespace std;
//
//const int Max_N = 16;
//const array<char, Max_N> Line_Up = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//
//string Make_Number(int number, const int n) {
//	string result = "";
//
//	while (number / n != 0) {
//		result.insert(result.begin(), Line_Up[number % n]);
//		number /= n;
//	}
//
//	result.insert(result.begin(), Line_Up[number % n]);
//	return result;
//}
//
//string solution(int n, int t, int m, int p) {
//	string answer = "", tmpanswer = "";
//	for (int i = 0; i < t * m; ++i) {
//		tmpanswer.append(Make_Number(i, n));
//		if (tmpanswer.length() > t* m)
//			break;
//	}
//	for (int i = 0; i < t; ++i) {
//		answer += tmpanswer[i * m + p - 1];
//	}
//
//	return answer;
//}
