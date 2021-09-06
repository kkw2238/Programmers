/*
	https://programmers.co.kr/learn/courses/30/lessons/84512
*/

#include <string>

using namespace std;

int solution(string word) {
    int answer = 0;
    int chilldrenCount[5] = { 781, 156, 31, 6, 1 };
    
    for (int i = 0; i < word.length(); ++i)
    {
        switch (word[i])
        {
        case 'U':
            answer += chilldrenCount[i];
        case 'O':
            answer += chilldrenCount[i];
        case 'I':
            answer += chilldrenCount[i];
        case 'E':
            answer += chilldrenCount[i];
        }
        ++answer;
    }

    return answer;
}