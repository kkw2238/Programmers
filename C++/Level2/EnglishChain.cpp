/*
	https://programmers.co.kr/learn/courses/30/lessons/12981
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> alreadyWords;
    string beforeString = words.front();

    alreadyWords.insert(beforeString);

    for (int i = 1; i < words.size(); ++i)
    {
        if ((alreadyWords.find(words[i]) != alreadyWords.end())
            || (beforeString.back() != words[i].front()))
        {
            return vector{ i % n + 1, i / n + 1 };
        }

        if (beforeString.back() == words[i].front())
        {
            beforeString = words[i];
            alreadyWords.insert(words[i]);
        }
    }

    return vector{ 0, 0 };
}

// ���� �ڵ�
//#include <string>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//vector<int> solution(int n, vector<string> words) {
//	vector<int> answer;
//	set<string> chain;
//
//	int count = 1;
//
//	string* beforeWord = nullptr;
//
//	for (string& s : words) {
//		if (beforeWord != nullptr) {
//			if (*(*beforeWord).rbegin() != s[0] || chain.find(s) != chain.end())
//				break;
//		}
//		chain.insert(s);
//		beforeWord = &s;
//		++count;
//	}
//
//	if (count > words.size())
//		return vector<int>(2, 0);
//
//	answer = { count % n == 0 ? n : count % n, (count - 1 + n) / n };
//	return answer;
//}
