/*
    https://programmers.co.kr/learn/courses/30/lessons/17684
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> LZW(const string& msg)
{
    vector<int> result;
    map<string, int> dictionary;
    string str = "";
    int dictionaryIndex = 0;

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        // A : 1 ~ Z : 26���� �ʱ� �� ����
        dictionary.emplace(pair(str + c, ++dictionaryIndex));
    }

    for (int i = 0; i < msg.length(); ++i)
    {
        // �� �ܰ���� �ϼ��� ���ڿ��� ���� ��ġ�� ���ڸ� �߰� => before 'K' - after "KA" 
        str.push_back(msg[i]);

        // �߰��� ���ڿ��� ������ ���� ���
        if (dictionary.find(str) == dictionary.end())
        {
            // �����ܰ������ ���ڿ��� ���� ���� index�� ����� �߰�
            result.emplace_back(dictionary[str.substr(0, str.length() - 1)]);
            // ���� ���ڿ��� ������ ���Ӱ� �߰�
            dictionary.emplace(pair(str, ++dictionaryIndex));
            // ���� ���ڸ� str�� ����
            str = msg[i];
        }
    }

    // ������ ���ڰ� ������ ����Ǿ� �ִ� ��� str�� ""�� �ƴϱ⿡ ����
    if (str.compare("") != 0)
    {
        result.emplace_back(dictionary[str]);
    }

    return result;
}

vector<int> solution(string msg) 
{
    return LZW(msg);
}

// ���� �ڵ�
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//vector<int> solution(string msg) {
//	const int ALPHABET_LENGTH = 26;
//	int addDic = 1, offset = 1;
//	vector<int> answer;
//	map<string, int> dictionary;
//
//	for (char c : msg) dictionary[string{ c }] = c - 'A' + 1;
//
//	for (int i = 0; i < msg.length();) {
//		string wc = msg.substr(i, offset);
//
//		if (dictionary.find(wc) == dictionary.end()) {
//			dictionary[wc] = ALPHABET_LENGTH + addDic;
//			++addDic;
//
//			answer.push_back(dictionary[msg.substr(i, offset - 1)]);
//			i += (offset - 1);
//			offset = 1;
//		}
//		else if (offset + i == msg.length()) {
//			answer.push_back(dictionary[wc.substr(0, offset)]);
//			break;
//		}
//		else ++offset;
//	}
//
//	return answer;
//}