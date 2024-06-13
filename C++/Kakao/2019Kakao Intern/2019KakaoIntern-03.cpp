#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const bool IsCoincide(string& a, string& b) {
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] != '*' && a[i] != b[i])
			return false;
	}

	return true;
}

vector<string> UserID_Coincide_Banned(vector<string>& user_id, string banned_id) {
	vector<string> result;
	if (user_id.empty())
		return result;

	for (int i = 0; i < user_id.size(); ++i) {
		if (IsCoincide(banned_id, user_id[i]))
			result.push_back(user_id[i]);
	}

	return result;
}

map<int, vector<string>> Distribute_UserID_By_Length(vector<string>& user_id) {
	map<int, vector<string>> distribitedID;

	for (string& s : user_id) {
		distribitedID[s.length()].push_back(s);
	}

	return distribitedID;
}

int GetFactorial(int n) {
	int result = 1;
	while (n > 0) {
		result *= n;
		--n;
	}
	return result;
}

int GetCombinationCount(map<string, vector<vector<string>>>& coincides_Strings) {
	int result = 1;
	for (pair<string, vector<vector<string>>> elm : coincides_Strings) {
		int n = elm.second[0].size();
		int r = elm.second.size();

		for (vector<string> v : elm.second) {

		}

		result *= GetFactorial(n) / (GetFactorial(r) * GetFactorial(n - r));
	}

	return result;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	map<int, vector<string>> distribitedID = Distribute_UserID_By_Length(user_id);
	map<string, vector<vector<string>>> coincides_Strings;

	for (string ban : banned_id) {
		coincides_Strings[ban].push_back(UserID_Coincide_Banned(distribitedID[ban.length()], ban));
	}

	return GetCombinationCount(coincides_Strings);
}

int main() {
	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "fr*d*", "*rodo", "*****", "******", "******" };
	cout << solution(user_id, banned_id);
}
