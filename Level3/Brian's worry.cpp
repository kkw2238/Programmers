#include <string>

using namespace std;

const string INVALID = "invalid";

bool IsTypeOne(const string& s)
{
    // �� �� �� �� �� �� ��
    char pattern = 'a';

    if (islower(s[0]) || islower(s[s.length() - 1]))
    {
        return false;
    }

    for (int i = 0; i < s.size(); ++i)
    {
        if (islower(s[i]) && !(i % 2 == 0))
        {
            return false;
        }
    }

    return true;
}

bool IsTypeTwo(const string& s)
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

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(string sentence) {
    string answer = "";

    for (int i = 0; i < sentence.length(); ++i)
    {

    }

    return answer;
}

/*
    Ÿ�� 1 + Ÿ�� 1 => �߰��� �빮�� 2���� 

    Ÿ�� 1 + Ÿ�� 2 => �빮�� + �ٸ� �ҹ���
    
    Ÿ�� 2 + Ÿ�� 2 => �߰��� �ҹ��� 2����
    
    Ÿ�� 2 + Ÿ�� 1 => �ҹ��� + �빮�� 
*/