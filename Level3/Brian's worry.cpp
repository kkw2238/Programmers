
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
    1. ������ �빮���� ��� - Ÿ�� 1
        -> üũ ��� 
            �ٸ� ���ڿ��� ���� �� ���� Ȯ�� 
    2. ������ �ҹ����� ��� - Ÿ�� 2
        

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
#include <iostream>
#include <stack>

bool isTypeOne(string& sentence, int startIndex, int endIndex)
{
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

    return isupper(sentence[sentence.length() - 1]);
}

bool isTypeTwo(string& sentence, int startiIndex, int endIndex)
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

    return true;
}

bool isTypeBoth(string& sentence, int startiIndex, int endIndex)
{
    string subStr = sentence.substr(startiIndex + 1, endIndex - startiIndex - 2);
    if (!isTypeOne(subStr, startiIndex + 1, endIndex - startiIndex - 2))
    {
        return false;
    }

    int charCount = count(sentence.begin(), sentence.end(), sentence[startiIndex]);

    if (charCount != 2)
    {
        return false;
    }

    return true;
}

string solution(string sentence) {
    int offset = 0;
    string result = "";

    for (int i = 0; i < sentence.length(); ++i)
    {
        if (isupper(sentence[i]) || sentence[i] == ' ')
        {
            result += " ";
            continue;
        }
        
        //int lowerIndex = distance(sentence.begin(), find_if(sentence.begin() + offset, sentence.end(), islower));
        int lastIndex = sentence.find_last_of(sentence[i]);
        int beginPos = max(i - 1, 0);
        int endPos = min((int)sentence.length(), lastIndex + 1);
        int length = endPos - beginPos + 1;
        string subStr = sentence.substr(beginPos, length);

        if (i > 0 && isTypeOne(subStr, i - beginPos, endPos - beginPos))
        {
            offset += subStr.length() + 2;
            result += string(subStr.length() + 1, '1');
            i = offset;
        }
        else if (isTypeTwo(subStr, i - beginPos, endPos - beginPos))
        {
            offset += subStr.length() - 1;
            result += string(subStr.length() - 1, '2');
            sentence.insert(sentence.begin() + offset + 1, ' ');
            i = offset;
        }
        else if (isTypeBoth(subStr, i - beginPos, endPos - beginPos))
        {
            offset += subStr.length();
            result += string(subStr.length() - 1, '3');
            sentence.insert(sentence.begin() + offset - 1, ' ');
            i = offset;
        }  
        else
        {
            return sentence;
        }
    }

    return result;
}

int main()
{
    vector<string> q{
        "aaXa",
        "AxAxAxAoBoBoB",
        "aIaAM",
        "baHELLOabWORLD",
        "aHbEbLbLbOacWdOdRdLdDc",
        "bAaOb",
        "aVBBBBBaCDbSbDbQ"
    };
    vector<string> a{
        "invalid",
        "invalid",
        "I AM",
        "invalid",
        "HELLO WORLD",
        "AO",
        " "
    };

    cout << solution("bAaOb") << '\n';

    for (int i = 0; i < q.size(); ++i)
    {
        cout << "Q : " << q[i] << '\n';
        cout << "A : " << solution(q[i]) << '\n';
        cout << "Correct : " << a[i] << "\n\n";
    }
}