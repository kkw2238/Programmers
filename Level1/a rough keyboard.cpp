/*
	https://school.programmers.co.kr/learn/courses/30/lessons/160586
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> indices;

    for (const string& keyboard : keymap)
    {
        for (int i = 0; i < keyboard.size(); ++i)
        {
            char key = keyboard[i];

            if (indices.find(keyboard[i]) != indices.end())
            {
                if (indices[key] > (i + 1))
                {
                    indices[key] = i + 1;
                }
            }
            else
            {
                indices[key] = i + 1;
            }
        }
    }

    for (const string& target : targets)
    {
        int count = 0;

        for (int i = 0; i < target.size(); ++i)
        {
            char key = target[i];

            if (indices.contains(target[i]))
            {
                count += indices[key];
            }
            else
            {
                count = -1;
                break;
            }
        }

        answer.push_back(count);
    }

    return answer;
}