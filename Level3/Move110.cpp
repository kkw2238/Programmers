/*
    https://programmers.co.kr/learn/courses/30/lessons/77886
*/

#include <string>
#include <vector>

using namespace std;

string Move110(string number)
{
    int countOf110 = 0;
    string base = "";

    for (int i = 0; i < number.size(); ++i)
    {
        base += number[i];

        if (base.length() >= 3 && base.substr(base.length() - 3) == "110")
        {
            ++countOf110;
            base.erase(base.end() - 3, base.end());
        }
    }

    if (countOf110 > 0)
    {
        string tmpBase = base + "110";
        int index = base.find("111");

        if (index == string::npos)
        {
            index = base.length();
            for (int i = base.length() - 1; i >= 0; --i)
            {
                if (base[i] == '0')
                {
                    continue;
                }
                string nextString = base.substr(0, i) + "110" + base.substr(i);

                if (tmpBase > nextString)
                {
                    tmpBase = nextString;
                    index = i;
                }
            }
        }

        string insertStr = "";
        for (int i = 0; i < countOf110; ++i)
        {
            insertStr.append("110");
        }

        base = base.substr(0, index) + insertStr + base.substr(index);
    }
    else
    {
        base = number;
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

//
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//map<string, string> dictionary;
//
//const string remakeBase(const string& num, int index)
//{
//    return num.substr(0, index) + "110" + num.substr(index);
//}
//
//string Move110(string number)
//{
//    int countOf110 = 0;
//    string base = "";
//
//    for (int i = 0; i < number.size(); ++i)
//    {
//        base += number[i];
//
//        if (base.length() >= 3 && base.substr(base.length() - 3) == "110")
//        {
//            ++countOf110;
//            base.erase(base.end() - 3, base.end());
//        }
//    }
//
//    if (base.empty())
//    {
//        base += "110";
//        --countOf110;
//    }
//
//    for (int j = 0; j < countOf110; ++j)
//    {
//        string memBase = base;
//        string tmpString = "110" + base;
//        if (dictionary[base] == "")
//        {
//            for (int i = 1; i <= base.length(); ++i)
//            {
//                string remakedString = remakeBase(base, i);
//                if (remakedString < tmpString)
//                {
//                    tmpString = remakedString;
//                }
//            }
//
//            dictionary[base] = tmpString;
//        }
//        tmpString = dictionary[base];
//
//        if (tmpString > number)
//        {
//            return number;
//        }
//        base = tmpString;
//    }
//
//    return base;
//}