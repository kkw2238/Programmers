/*
	https://school.programmers.co.kr/learn/courses/30/lessons/134240
*/

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string right = "";

    for (int i = 1; i < food.size(); ++i)
    {
        answer += string(food[i] / 2, to_string(i)[0]);
        right = string(food[i] / 2, to_string(i)[0]) + right;
    }

    return answer + "0" + right;
}