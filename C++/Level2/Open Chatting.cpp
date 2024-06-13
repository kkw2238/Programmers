/*
	https://programmers.co.kr/learn/courses/30/lessons/42888
*/

#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum { ENTER, LEAVE };
const string Notice[2]{ "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.", "´ÔÀÌ ³ª°¬½À´Ï´Ù." };

pair<string, string> GetUserNickName(const string& record)
{
    stringstream ss(record);
    pair<string, string> result;
    string tmp;

    ss >> tmp;
    ss >> result.first >> result.second;

    return result;
}

vector<string> solution(vector<string> records) {
    map<string, string> userNickname;
    vector<pair<string, string>> logs;
    vector<string> answer;

    for (string& record : records)
    {
        pair<string, string> userData = GetUserNickName(record);

        switch (record.front())
        {
        case 'E':
            logs.emplace_back(pair(userData.first, Notice[ENTER]));
        case 'C':
            userNickname[userData.first] = userData.second;
            break;
        case 'L':
            logs.emplace_back(pair(userData.first, Notice[LEAVE]));
            break;
        }
    }

    for (const pair<string, string>& log : logs)
    {
        answer.emplace_back(userNickname[log.first] + log.second);
    }

    return answer;
}

//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//
//class User {
//public:
//	User(string& str, map<string, string>& uidNnickName) {
//		MakeActType(str);
//		MakeUid(str);
//
//		if (mActType != 1) uidNnickName[mUid] = string(str.begin() + 1, str.end());
//	}
//
//	void MakeActType(string& record) {
//		const string RecordAction[3] = { "Enter", "Leave", "Change" };
//
//		string action = record.substr(0, distance(record.begin(), find(record.begin(), record.end(), ' ')));
//
//		for (int i = 0; i < 3; ++i) {
//			if (action.compare(RecordAction[i]) == 0) {
//				mActType = i;
//				break;
//			}
//		}
//
//		record.erase(record.begin(), record.begin() + action.length() + 1);
//	}
//	void MakeUid(string& record) {
//		string uid = record.substr(0, distance(record.begin(), find(record.begin(), record.end(), ' ')));
//		mUid = uid;
//
//		record.erase(record.begin(), record.begin() + mUid.length());
//	}
//
//	string GetRecord(map<string, string>& str) const {
//		const string RecordActionKorean[2] = { "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.", "´ÔÀÌ ³ª°¬½À´Ï´Ù." };
//
//		return str[mUid] + RecordActionKorean[mActType];
//	}
//
//	const bool IsNotChangeAct() const { return mActType != 2; }
//private:
//	string mUid;
//	int mActType;
//};
//
//
//vector<string> solution(vector<string> record) {
//	map<string, string> uidNnickName;
//	vector<User> users;
//	vector<string> answer;
//
//	for (size_t i = 0; i < record.size(); ++i)
//		users.emplace_back(record[i], uidNnickName);
//
//	for (User& user : users) {
//		if (user.IsNotChangeAct())
//			answer.push_back(user.GetRecord(uidNnickName));
//	}
//
//	return answer;
//}