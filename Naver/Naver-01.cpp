#include <string>
#include <vector>

using namespace std;

enum { RECEIVE, DELETE, SAVE, ERROR };

int Bunrue(const string& record) {
	switch (record.at(0))
	{
	case 'R': return RECEIVE;
	case 'D': return DELETE;
	case 'S': return SAVE;
	default: return ERROR;
	}
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<string> tmpVector;

	const int StartPos = 8;

	for (string& s : record) {
		switch (Bunrue(s)) {
		case RECEIVE:
			tmpVector.emplace_back(s.begin() + StartPos, s.end());
			break;
		case DELETE:
			if (tmpVector.size() > 0) tmpVector.erase(tmpVector.end() - 1);
			break;

		case SAVE:
			if (tmpVector.size() > 0) answer.insert(answer.end(), tmpVector.begin(), tmpVector.end());
			tmpVector.clear();
			break;
		}
	}

	return answer;
}