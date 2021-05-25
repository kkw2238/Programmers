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
        // A : 1 ~ Z : 26까지 초기 값 저장
        dictionary.emplace(pair(str + c, ++dictionaryIndex));
    }

    for (int i = 0; i < msg.length(); ++i)
    {
        // 전 단계까지 완성된 문자열에 현재 위치의 문자를 추가 => before 'K' - after "KA" 
        str.push_back(msg[i]);

        // 추가된 문자열이 사전에 없을 경우
        if (dictionary.find(str) == dictionary.end())
        {
            // 이전단계까지의 문자열에 대한 사전 index를 결과에 추가
            result.emplace_back(dictionary[str.substr(0, str.length() - 1)]);
            // 현재 문자열을 사전에 새롭게 추가
            dictionary.emplace(pair(str, ++dictionaryIndex));
            // 현재 문자를 str에 저장
            str = msg[i];
        }
    }

    // 마지막 문자가 사전에 저장되어 있는 경우 str이 ""가 아니기에 저장
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

// 예전 코드
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