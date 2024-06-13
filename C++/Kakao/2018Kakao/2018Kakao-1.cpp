/*
	{(2018년)KAKAO BLIND RECRUITMENT] 오픈채팅방
	https://programmers.co.kr/learn/courses/30/lessons/42888
*/
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class User {
public:
	User(string& str, map<string, string>& uidNnickName) {
		MakeActType(str);
		MakeUid(str);

		if (mActType != 1) uidNnickName[mUid] = string(str.begin() + 1, str.end());
	}

	void MakeActType(string& record) {
		const string RecordAction[3] = { "Enter", "Leave", "Change" };

		string action = record.substr(0, distance(record.begin(), find(record.begin(), record.end(), ' ')));

		for (int i = 0; i < 3; ++i) {
			if (action.compare(RecordAction[i]) == 0) {
				mActType = i;
				break;
			}

			record.erase(record.begin(), record.begin() + action.length() + 1);
		}
	}
		
	void MakeUid(string& record) {
		string uid = record.substr(0, distance(record.begin(), find(record.begin(), record.end(), ' ')));
		mUid = uid;

		record.erase(record.begin(), record.begin() + mUid.length());
	}

	string GetRecord(map<string, string>& str) const {
		const string RecordActionKorean[2] = { "님이 들어왔습니다.", "님이 나갔습니다." };

		return str[mUid] + RecordActionKorean[mActType];
	}

	const bool IsNotChangeAct() const { return mActType != 2; }
private:
	string mUid;
	int mActType;
};


vector<string> solution(vector<string> record) {
	map<string, string> uidNnickName;
	vector<User> users;
	vector<string> answer;

	for (size_t i = 0; i < record.size(); ++i)
		users.emplace_back(record[i], uidNnickName);

	for (User& user : users) {
		if (user.IsNotChangeAct())
			answer.push_back(user.GetRecord(uidNnickName));
	}

	return answer;
}