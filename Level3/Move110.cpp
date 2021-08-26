/*
    https://programmers.co.kr/learn/courses/30/lessons/77886
*/

#include <string>
#include <vector>

using namespace std;

string MOVE_STRING = "110";
const string REPLACE_STRING = "111";

string Move110(string& s)
{
    int offset = 0;
    
    while (offset != -1)
    {
        string tmpString = s;

        offset = s.find(MOVE_STRING.c_str(), offset);
        
        if (offset != string::npos)
        {
            int replace_index = 0;
            replace_index = s.substr(0, offset).find(REPLACE_STRING.c_str());
            
            if (replace_index != string::npos)
            {
                s.erase(offset, MOVE_STRING.length());
                s.insert(replace_index, MOVE_STRING.c_str());

                offset = replace_index + MOVE_STRING.length();
            }
            else
            {
                offset += MOVE_STRING.length();
            }
        }
    }

    return s;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (string& number : s)
    {
        answer.push_back(Move110(number));
    }

    return answer;
}

int main()
{
    solution({ "1110","100111100","0111111010" });
}