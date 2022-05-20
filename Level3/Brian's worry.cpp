
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
    if (sentence[0] == ' ' || sentence.length() <= 2 || isupper(sentence[startIndex]))
    {
        return false;
    }

    int alphaIndex = getAlphaIndex(sentence[startIndex]);

    if (usedAlpha[alphaIndex])
    {
        return false;
    }

    int lastestIndex = startIndex - 2;
    const char target = sentence[startIndex];

    for (int i = startIndex; i < sentence.length(); ++i)
    {
        if (i - lastestIndex == 2)
        {
            if (sentence[i] != target)
            {
                return false;
            }
            else
            {
                lastestIndex = i;
            }
        }
        else if (islower(sentence[i]))
        {
            return false;;
        }
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
    
    if (isupper(sentence[startiIndex]) || charCount != 2)
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
    int alphaIndex = getAlphaIndex(sentence[startiIndex]);

    if (isupper(sentence[startiIndex]) || charCount != 2 || usedAlpha[alphaIndex])
    {
        if (islower(subStr[1]))
        {
            usedAlpha[getAlphaIndex(subStr[1])] = false;
        }
        return false;
    }

    usedAlpha[alphaIndex] = true;
    return true;
}

string solution(string sentence) {
    const int ALPHA_COUNT = 'z' - 'a' + 1;
    vector<bool> usedAlpha(ALPHA_COUNT, false);
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
        
        string subStr = sentence.substr(beginPos, endPos - beginPos + 1);
        int subStartIndex = i - beginPos;
        int subEndIndex = endPos - beginPos;

        if (isTypeTwo(subStr, subStartIndex, subEndIndex, usedAlpha) || isTypeBoth(subStr, subStartIndex, subEndIndex, usedAlpha))
        {
            subEndIndex = lastIndex - i + 1;
            if (!tmpUpper.empty())
            {
                result += tmpUpper.substr(0, tmpUpper.length());
                sentence.insert(sentence.begin() + result.length(), ' ');
            }
        }
        else if (i > 0 && isTypeOne(subStr, subStartIndex, subEndIndex, usedAlpha))
        {  
            if (tmpUpper.length() > 1)
            {
                result += tmpUpper.substr(0, tmpUpper.length() - 1);
                sentence.insert(sentence.begin() + result.length(), ' ');
            }
            
            subStartIndex = 0;
            subEndIndex = subStr.length();
        }
        else
        {
            return INVAILD;
        }
        if (!result.empty() && result.back() != ' ')
        {
            result += " ";
        }

        result += subStr.substr(subStartIndex, subEndIndex) + " ";

        if (sentence.length() <= result.length() - 1)
        {
            sentence.push_back(' ');
        }
        else
        {
            sentence.insert(sentence.begin() + result.length() -1, ' ');
        }

        i = result.length() - 1;
        tmpUpper = "";
    }

    result += tmpUpper;
    if (result.empty())
    {
        return INVAILD;
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

    return result;
}

#include <iostream>
#include <vector>

int main()
{

    solution("AxAxAxABcBcBcB");
    vector<string> strs = { 
        "aHELLOa"                                                        ,
        "AAAAxAbAx"                                                      ,
        "aHbEbLbLbOa"                                                    ,
        "HaEaLaLaObWORLDb"                                               ,
        "SpIpGpOpNpGJqOqA"                                               ,
        "A"                                                              ,
        "HELLOWORLD"                                                     ,
        "aHbEbLbLbOacWdOdRdLdDc"                                         ,
        "HaEaLaLObWORLDb"                                                ,
        "AAA"                                                            ,
        "aHELLOWORLDa"                                                   ,
        "AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR"               ,
        "aIaAM"                                                          ,
        "bAaOb"                                                          ,
        "a"                                                              ,
        "Aa"                                                             ,
        "aA"                                                             ,
        "HaEaLaLaOWaOaRaLaD"                                             ,
        "abHELLObaWORLD"                                                 ,
        "aHELLOa bWORLDb"                                                ,
        "TxTxTxbAb"                                                      ,
        "bTxTxTaTxTbkABaCDk"                                             ,
        "baHELLOabWORLD"                                                 ,
        "A B"                                                            ,
        "AxAxAxABcBcBcB"                                                 ,
        "oBBoA"                                                          ,
        "AxAxAxA"                                                        ,
        "HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoAAAAxAxAxAA",
        "aBcAadDeEdvAvlElmEEEEm"                                         ,
        "AcAcABaBaB"                                                     ,
        "aGbWbFbDakGnWnLk"                                               ,
        "XcXbXcX"                                                        ,
        "aCaCa"                                                          ,
        "AxAxAxAoBoBoB"                                                  ,
        "xAaAbAaAx"                                                      ,
        "AsCsWsQsQsEEEEEEEEeEeEe"                                        ,
        "ABCaDaEFGbH"                                                    ,
        "aAaBBBcAeAeAc"                                                  ,
        "ABCbDaEaFbHI"                                                   ,
        "AacacaA"                                                        ,
        "AaBcBcBcBcB"                                                    ,
        "aAAA"                                                           ,
        "AAAa"                                                           ,
        "aAbBBbAa"                                                       ,
        "aAbBBbAa"                                                       ,
        "aAAbBbAAa"                                                      ,
        "aAcAbAbAcAcAcAa"                                                ,
        "acAcAcAa"                                                       ,
        "aAcAcAca"                                                       ,
        "AdAeAeAdA"                                                      ,
        "dAAeAd"                                                         ,
        "dAeAAd"                                                         ,
        "cAbBbAc"                                                        ,
        "AbbA"                                                           ,
        "aAaaBa"                                                         ,
        "aAacBc"                                                         ,
        "AB"                                                             ,
        "AcBc"                                                           ,
        "aAaB"                                                           ,
        "aAbAbAbAacBdBdBdBc"                                             ,
        "AbAbAbABdBdBdB"                                                 ,
        "AbAbAbAcBBBBc"                                                  ,
        "aAbAbAbAaBdBdBdB"                                               ,
        "aAbAbAbAacBBBBc"                                                ,
        "aAAAAaBdBdBdB"                                                  ,
        "aAAAAacBBBBc"                                                   ,
        "aAAAAaBdBdBdB"                                                  ,
        "aAAAAacBdBdBdBc"                                                ,
        "aAAAAaBdBdBdB"                                                  ,
        "AbAbAbAcBdBdBdBc"                                               ,
        "aAAAAaBdBdBdB"                                                  ,
        "IaMMbMb"                                                        ,
        "AaAaAabBBb"                                                     ,
        "AaAaAcA"                                                        ,
        "aAabBb"                                                         ,
        "bBbcHdEdEc"                                                     ,
        "AaAA"                                                           ,
        "JaOOOaA"                                                        ,
        "aJaOOOcAc"                                                      ,
        "IaAMa"                                                          ,
        "aIaAM"                                                          ,
        "SpIpGpOpNpGJqOOOqA"                                             ,
        "AxAxAxAoBoBoB"                                                  ,
        "HaEaLaLaOWbObRbLbD"                                             ,
        "AxAxAxABoBoB"                                                   ,
        "aBa"                                                            ,
        "baHELLOabWORLD"                                                 ,
        "aAbAba"                                                         ,
        "bAaOb"                                                          ,
        "AAAaBaBBBbB"                                                    
    };

    vector<string> ans =
    {
        "HELLO",
        "A A A A AA",
        "HELLO",
        "HELLO WORLD",
        "SIGONG J O A",
        "A",
        "H E L L O W O R L D",
        "HELLO WORLD",
        "HELL O WORLD",
        "A A A",
        "HELLOWORLD",
        "A A A B A BBBB C BBBB C BB GG G G G RRRRRR",
        "I A M",
        "AO",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "AAAA BBBB",
        "BB A",
        "AAAA",
        "HELLO WORLD SIGONG J O A GWFD GWL BB A A A AAAA A",
        "BA DE A E EEEE",
        "A A A B B B",
        "GWFD GWL",
        "X XX X",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "A B C D E F GH",
        "A B B B AAA",
        "A B C DEF H I",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "invalid",
        "A AAA A",
        "invalid",
        "invalid",
        "ABA",
        "invalid",
        "invalid",
        "A B",
        "A B",
        "A B",
        "A B",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "AAAA BBBB",
        "IM M M",
        "invalid",
        "A A AA",
        "A B",
        "B HEE",
        "AA A",
        "J OOO A",
        "J O O O A",
        "I AM",
        "I A M",
        "SIGONG J OOO A",
        "invalid",
        "HELLO WORLD",
        "AAAA B B B",
        "B",
        "invalid",
        "invalid",
        "AO",
        "A A A B B B BB",
    };

    for (int i = 0; i < strs.size(); ++i)
    {
        string myAns = solution(strs[i]);
        if(myAns != ans[i])
            cout << "Q : " << strs[i] << "\t\t" << "A : " << myAns << "\t\t" << "E : " << ans[i] << '\n';
    }

   
   
}

