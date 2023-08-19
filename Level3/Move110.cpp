/*
    https://programmers.co.kr/learn/courses/30/lessons/77886
*/

#include <string>
#include <vector>

using namespace std;
//
//string MOVE_STRING = "110";
//const string REPLACE_STRING = "111";
//
//string Move110(string& s)
//{
//    int offset = 0;
//    
//    while (offset != -1)
//    {
//        string tmpString = s;
//
//        offset = s.find(MOVE_STRING.c_str(), offset);
//        
//        if (offset != string::npos)
//        {
//            int replace_index = 0;
//            replace_index = s.substr(0, offset).find(REPLACE_STRING.c_str());
//            
//            if (replace_index != string::npos)
//            {
//                s.erase(offset, MOVE_STRING.length());
//                s.insert(replace_index, MOVE_STRING.c_str());
//
//                offset = replace_index + MOVE_STRING.length();
//            }
//            else
//            {
//                offset += MOVE_STRING.length();
//            }
//        }
//    }
//
//    return s;
//}
const string remakeBase(const string& num, int index)
{
    return num.substr(0, index) + "110" + num.substr(index + 1);
}

string Move110(string number)
{
    int countOf110 = 0;
    string base = "";

    for (int i = 0; i < number.size(); ++i)
    {
        base += number[i];

        if (base.ends_with("110"))
        {
            ++countOf110;
            base.erase(base.end() - 3, base.end());
        }
    }

    if (base.empty())
    {
        base += "110";
        --countOf110;
    }

    for (int i = 0; i < base.length(); ++i)
    {
        if (countOf110 <= 0)
        {
            break;
        }
        string remakedString = remakeBase(base, i);
        if (remakedString < base)
        {
            base = remakedString;
            --countOf110;
        }
    }

    if (base > number)
    {
        return number;
    }
    return base;
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
    if ("110" < "1101")
    {
        int a = 0;
        ++a;
    }
    solution({ "1110","100111100","0111111010" });
}