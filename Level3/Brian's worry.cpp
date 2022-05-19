
//const string INVALID = "invalid";
//enum STRING_TYPE { ONE_ONE, ONE_TWO, TWO_ONE, TWO_TWO };
//
//bool IsTypeOne(const string s)
//{
//    char pattern = 'a';
//
//    if (islower(s[0]) || islower(s[s.length() - 1]))
//    {
//        return false;
//    }
//
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (islower(s[i]) && (i % 2 != 1))
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//bool IsTypeTwo(const string s)
//{
//    char pattern = 'a';
//
//    for (int i = 1; i < s.length() - 1; ++i)
//    {
//        if (islower(s[i]))
//        {
//            return false;
//        }
//    }
//
//    return islower(s[0]) && islower(s[s.length() - 1]);
//}
//
//int GetType(const string& s, int index, int& offset)
//{
//    if (isupper(s[index - 2]) && isupper(s[index - 1]))
//    {
//        offset = index - 1;
//        return ONE_ONE;
//    }
//    else if (isupper(s[index - 1]))
//    {
//        offset = index;
//        return ONE_TWO;
//    }
//    else if (islower(s[index - 1]))
//    {
//        offset = index - 1;
//        return TWO_ONE;
//    }
//    else
//    {
//        offset = index;
//        return TWO_TWO;
//    }
//}
//
//string solution(string sentence) {
//    string answer = "";
//
//    char memChar = *find_if(sentence.begin(), sentence.end(), [](const char c)
//        {
//            return islower(c);
//        });
//    int memIndex = 0;
//    int offset = 0;
//    bool enableFlag = true;
//
//    for (int i = 0; i < sentence.length(); ++i)
//    {
//        bool result = true;
//
//        if (islower(sentence[i]) && memChar != sentence[i])
//        {
//            memChar = sentence[i];
//
//            switch (GetType(sentence, i, offset))
//            {
//            case ONE_ONE:
//                --i;
//                answer.pop_back();
//            case ONE_TWO:
//                result = IsTypeOne(sentence.substr(memIndex, offset));
//                break;
//            case TWO_ONE:
//                --i;
//                answer.pop_back();
//            case TWO_TWO:
//                result = IsTypeTwo(sentence.substr(memIndex, offset));
//                break;
//            }
//
//            memIndex = offset;
//            answer.push_back(' ');
//
//            if (!result)
//            {
//                return INVALID;
//            }
//        }
//
//        if (sentence[i] != memChar)
//        {
//            answer += sentence[i];
//            enableFlag = true;
//        }
//        else if (enableFlag && sentence[i] == memChar)
//        {
//            enableFlag = false;
//        }
//        else if ((!enableFlag && sentence[i] == memChar) || sentence[i] == ' ')
//        {
//            return INVALID;
//        }
//    }
//
//    if (!IsTypeOne(sentence.substr(memIndex)) && !IsTypeTwo(sentence.substr(memIndex)))
//    {
//        return INVALID;
//    }
//
//    return answer;
//}

/*
    1. 시작이 대문자인 경우 - 타입 1
        -> 체크 방법 
            다른 문자열이 나올 때 까지 확인 
    2. 시작이 소문자인 경우 - 타입 2
        

*/

#include <string>
#include <algorithm>
#include <map>

using namespace std;

//bool isCorrectCase1(string& sentence, int index, bool once)
//{
//    const char findChar = sentence[index];
//    int lastIndex = sentence.find_last_of(sentence[index]);
//
//    if (lastIndex == string::npos || lastIndex == index)
//    {
//        return false;
//    }
//
//    for (int i = index; i < lastIndex; ++i)
//    {
//        if (islower(sentence[i]) && sentence[i] != findChar)
//        {
//
//        }
//    }
//
//    string subString = sentence.substr(index, lastIndex);
//    if (islower(sentence[index + 1]))
//    {
//        ++index;
//        return isCorrectCase2(subString, index);
//    }
//    else if (islower(sentence[index + 2]))
//    {
//        index += 2;
//        return isCorrectCase1(subString, index);
//    }
//    else
//    {
//        return false;
//    }
//}
//
//bool isCorrectCase2(string& sentence, int index, bool isFirst)
//{
//    int lastIndex = sentence.find_last_of(sentence[index]);
//    
//    if (lastIndex == string::npos || lastIndex == index)
//    {
//        return false;
//    }
//
//    string subString = sentence.substr(index, lastIndex);
//
//    for (int i = 0; i < subString.size(); ++i)
//    {
//        if (islower(subString[i]) && subString[i] != subString[0])
//        {
//            if (isFirst && isCorrectCase1(subString, i, !isFirst))
//            {
//                isFirst = false;
//            }
//            else
//            {
//                return false;
//            }
//        }
//    }
//
//    return true;
//}
//bool isCorrectCase2(const string& sentence, map<char, string>& subSentence, bool isFirst);
//
//bool isCorrectCase1(const string& sentence, map<char, string>& subSentence, bool isFirst)
//{
//    bool isCorrect = true;
//    char target = sentence[0];
//
//    for (int i = 1; i < sentence.length(); ++i)
//    {
//        if (isupper(sentence[i]))
//        {
//            continue;
//        }
//
//        if (sentence[i] != target && isFirst)
//        {
//            char nextTarget = sentence[i];
//            isCorrect &= isCorrectCase2(subSentence[nextTarget], subSentence, false);
//            isFirst = false;
//
//            continue;
//        }
//        else if (sentence[i] == target && i % 2 == 1)
//        {
//            return false;
//        }
//    }
//
//    return isCorrect;
//}
//
//
//bool isCorrectCase2(const string& sentence, map<char, string>& subSentence, bool isFirst)
//{
//    bool isCorrect = true;
//    char target = sentence[0];
//
//    for (int i = 1; i < sentence.length() - 1; ++i)
//    {
//        if (isupper(sentence[i]))
//        {
//            continue;
//        }
//
//        if (sentence[i] != target && isFirst)
//        {
//            char nextTarget = sentence[i];
//            isCorrect &= isCorrectCase1(subSentence[nextTarget], subSentence, false);
//            isFirst = false;
//            
//            continue;
//        }
//
//        return false;
//    }
//
//    return isCorrect;
//}
//
//string solution(string sentence) {
//    map<char, string> subSentence;
//
//    for (int i = 0; i < sentence.length(); ++i)
//    {
//        char c = sentence[i];
//        if (islower(c) && subSentence[c] == "")
//        {
//            int find_lastIndex = sentence.find_last_of(c);
//
//            if (find_lastIndex == i)
//            {
//                return "invaild";
//            }
//
//            int startPos = max(0, i - 1);
//            int endPos = min((int)sentence.length(), find_lastIndex + 1);
//            subSentence[c] = sentence.substr(startPos, endPos - startPos + 1);
//        }
//    }
//
//    bool isCorrect = true;
//    int index = 0;
//
//    for (int i = 0; i < sentence.length(); ++i)
//    {
//        int offset = 1;
//
//        if (isupper(sentence[i]) || sentence[i] == ' ')
//        {
//            continue;
//        }
//
//        if (!isCorrect)
//        {
//            return "invaild";
//        }
//
//        char c = sentence[i];
//        int charCount = count(subSentence[c].begin(), subSentence[c].end(), c);
//
//        if (charCount == 2)
//        {
//            isCorrect &= isCorrectCase2(subSentence[c], subSentence, true);
//        }
//        else
//        {
//            isCorrect &= isCorrectCase1(subSentence[c], subSentence, true);
//            ++offset;
//        }
//
//        if (isCorrect)
//        {
//            index += subSentence[c].length() + offset;
//            sentence.insert(sentence.begin() + index, ' ');
//            i = index;
//        }
//    }
//    
//    sentence.erase(remove_if(sentence.begin(), sentence.end(), islower), sentence.end());
//    return sentence;
//}

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const string INVAILD = "invalid";

const int getAlphaIndex(char c)
{
    return c - 'a' + 1;
}

bool isTypeOne(string& sentence, int startIndex, int endIndex, vector<bool>& usedAlpha)
{
    if (sentence[0] == ' ')
    {
        return false;
    }

    int lastestIndex = startIndex;

    for (int i = startIndex; i < sentence.length(); ++i)
    {
        if (sentence[i] == sentence[startIndex] && i != lastestIndex)
        {
            if (i - lastestIndex != 2)
            {
                return false;
            }
            lastestIndex = i;
        }
        if (islower(sentence[i]) && sentence[i] != sentence[startIndex])
        {
            return false;
        }
    }

    int alphaIndex = getAlphaIndex(sentence[startIndex]);

    if (usedAlpha[alphaIndex])
    {
        return false;
    }

    if (isupper(sentence[sentence.length() - 1]))
    {
        usedAlpha[alphaIndex] = true;
        return true;
    }

    return false;
}

bool isTypeTwo(string& sentence, int startiIndex, int endIndex, vector<bool>& usedAlpha)
{
    int charCount = count(sentence.begin(), sentence.end(), sentence[startiIndex]);
    
    if (charCount != 2)
    {
        return false;
    }

    for (int i = startiIndex; i < endIndex; ++i)
    {
        if (islower(sentence[i]) && sentence[i] != sentence[startiIndex])
        {
            return false;
        }
    }

    int alphaIndex = getAlphaIndex(sentence[startiIndex]);
    if (usedAlpha[alphaIndex])
    {
        return false;
    }

    usedAlpha[alphaIndex] = true;
    return true;
}

bool isTypeBoth(string& sentence, int startiIndex, int endIndex, vector<bool>& usedAlpha)
{
    string subStr = sentence.substr(startiIndex + 1, endIndex - startiIndex - 2);
    
    if (!isTypeOne(subStr, 1, endIndex - startiIndex - 2, usedAlpha))
    {
        return false;
    }

    int charCount = count(sentence.begin(), sentence.end(), sentence[startiIndex]);

    if (charCount != 2)
    {
        return false;
    }

    int alphaIndex = getAlphaIndex(sentence[startiIndex]);
    if (usedAlpha[alphaIndex])
    {
        return false;
    }

    usedAlpha[alphaIndex] = true;
    return true;
}

#include <iostream>

string solution(string sentence) {
    const int ALPHA_COUNT = 'z' - 'a' + 1;
    vector<bool> usedAlpha(ALPHA_COUNT, false);
    int offset = 0;
    int count = 0;
    string result = "";
    string tmpUpper = "";

    for (int i = 0; i < sentence.length(); ++i)
    {
        if (isupper(sentence[i]))
        {
            tmpUpper += string(1, sentence[i]);
            continue;
        }
        else if (sentence[i] == ' ')
        {
            continue;
        }
       
        int lastIndex = sentence.find_last_of(sentence[i]);

        if (lastIndex - i == 1)
        {
            return INVAILD;
        }

        int beginPos = max(i - 1, 0);
        int endPos = min((int)sentence.length(), lastIndex + 1);
        int length = endPos - beginPos + 1;
        
        string subStr = sentence.substr(beginPos, length);
        int subStartIndex = i - beginPos;
        int subEndIndex = endPos - beginPos;

        if (i > 0 && isTypeOne(subStr, subStartIndex, subEndIndex, usedAlpha))
        {  
            if (!tmpUpper.empty())
            {
                result += tmpUpper.substr(0, tmpUpper.length() - 1);
                offset += tmpUpper.length() - 1;
                sentence.insert(sentence.begin() + offset, ' ');
                ++offset;
            }

            offset = i + subStr.length();
            result += " " + subStr + " ";
            ++count;
        }
        else if (isTypeTwo(subStr, subStartIndex, subEndIndex, usedAlpha) || isTypeBoth(subStr, subStartIndex, subEndIndex, usedAlpha))
        {
            int distance = lastIndex - beginPos;
            if (!tmpUpper.empty())
            {
                result += tmpUpper.substr(0, tmpUpper.length());
                offset += tmpUpper.length();
                sentence.insert(sentence.begin() + offset, ' ');
                ++offset;
            }

            offset += distance + 1;
            result += " " + subStr.substr(i - beginPos, distance) + " ";
            ++count;
        }
        else
        {
            return INVAILD;
        }

        sentence.insert(sentence.begin() + offset, ' ');
        i = offset;
        tmpUpper = "";
    }

    if (count == 0)
    {
        return INVAILD;
    }

    result += tmpUpper;

    if (result[0] == ' ')
    {
        result.erase(0, 1);
    }
    if (result[result.size() - 1] == ' ')
    {
        result.pop_back();
    }

    for (int i = 0; i < result.length();)
    {
        if (islower(result[i]))
        {
            result.erase(i, 1);
        }
        else
        {
            ++i;
        }
    }

    while (result.find("  ") != string::npos)
    {
        int pos = result.find("  ");
        result.replace(result.begin() + pos, result.begin() + pos + 2, " ");
    }

    if (result.empty())
    {
        return INVAILD;
    }
    return result;
}


int main()
{
    cout << solution("AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR") << '\n';
    cout << solution("HaEaLaLaObWORLDb") << '\n';
    cout << solution("SpIpGpOpNpGJqOqA") << '\n';
    cout << solution("AxAxAxAoBoBoB") << '\n';
    cout << solution("aIaAM") << '\n';
    cout << solution("aaA") << '\n';
    cout << solution("Aaa") << '\n';
    cout << solution("HaEaLaLaOWaOaRaLaD") << '\n';
    cout << solution("aHELLOWORLDa") << '\n';
    cout << solution("HaEaLaLObWORLDb") << '\n';
    cout << solution("HaEaLaLaObWORLDb") << '\n';
    cout << solution("aHbEbLbLbOacWdOdRdLdDc") << '\n';
    cout << solution("abAba") << '\n';
    cout << solution("HELLO WORLD") << '\n';
    cout << solution("xAaAbAaAx") << '\n';
    cout << solution("AbAaAbAaCa") << '\n';
    cout << solution("AbAaAbAaC") << '\n';
    cout << solution("aaXa") << '\n';

}