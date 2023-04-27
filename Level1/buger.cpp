/*
	https://school.programmers.co.kr/learn/courses/30/lessons/133502
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string buger = "";

    for (int i : ingredient)
    {
        buger += (i + '0');

        if (buger.length() >= 4 && buger.substr(buger.length() - 4) == "1231")
        {
            ++answer;
            buger.erase(buger.end() - 4, buger.end());
        }
    }

    return answer;
}