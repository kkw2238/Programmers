#include <string>
#include <algorithm>

using namespace std;

const string INVALID = "invalid";
enum STRING_TYPE { ONE_ONE, ONE_TWO, TWO_ONE, TWO_TWO };

bool IsTypeOne(const string s)
{
    char pattern = 'a';

    if (islower(s[0]) || islower(s[s.length() - 1]))
    {
        return false;
    }

    for (int i = 0; i < s.size(); ++i)
    {
        if (islower(s[i]) && (i % 2 != 1))
        {
            return false;
        }
    }

    return true;
}

bool IsTypeTwo(const string s)
{
    char pattern = 'a';

    for (int i = 1; i < s.length() - 1; ++i)
    {
        if (islower(s[i]))
        {
            return false;
        }
    }

    return islower(s[0]) && islower(s[s.length() - 1]);
}

int GetType(const string& s, int index, int& offset)
{
    if (isupper(s[index - 2]) && isupper(s[index - 1]))
    {
        offset = index - 1;
        return ONE_ONE;
    }
    else if (isupper(s[index - 1]))
    {
        offset = index;
        return ONE_TWO;
    }
    else if (islower(s[index - 1]))
    {
        offset = index - 1;
        return TWO_ONE;
    }
    else
    {
        offset = index;
        return TWO_TWO;
    }
}

string solution(string sentence) {
    string answer = "";

    char memChar = *find_if(sentence.begin(), sentence.end(), [](const char c)
        {
            return islower(c);
        });
    int memIndex = 0;
    int offset = 0;
    bool enableFlag = true;

    for (int i = 0; i < sentence.length(); ++i)
    {
        bool result = true;

        if (islower(sentence[i]) && memChar != sentence[i])
        {
            memChar = sentence[i];

            switch (GetType(sentence, i, offset))
            {
            case ONE_ONE:
                --i;
                answer.pop_back();
            case ONE_TWO:
                result = IsTypeOne(sentence.substr(memIndex, offset));
                break;
            case TWO_ONE:
                --i;
                answer.pop_back();
            case TWO_TWO:
                result = IsTypeTwo(sentence.substr(memIndex, offset));
                break;
            }

            memIndex = offset;
            answer.push_back(' ');

            if (!result)
            {
                return INVALID;
            }
        }

        if (sentence[i] != memChar)
        {
            answer += sentence[i];
            enableFlag = true;
        }
        else if (enableFlag && sentence[i] == memChar)
        {
            enableFlag = false;
        }
        else if ((!enableFlag && sentence[i] == memChar) || sentence[i] == ' ')
        {
            return INVALID;
        }
    }

    if (!IsTypeOne(sentence.substr(memIndex)) && !IsTypeTwo(sentence.substr(memIndex)))
    {
        return INVALID;
    }

    return answer;
}

int main()
{
    solution("SpIpGpOpNpGJqOqA");
}