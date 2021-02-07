/* https://programmers.co.kr/learn/courses/30/lessons/72412 */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

const string FIELD_ALL = "-";

class Container {
public:
    Container() {};
    void Initialize(const vector<vector<string>>& fields, int index) {
        if (index == fields.size())
        {
            myTier = index;
            return;
        }

        for ( string field : fields[index])
        {
            careers.insert(pair<string, Container>(field, Container()));
            careers[field].Initialize(fields, index + 1);
        }

        myTier = index;
    }

    void Insert(string career) {
        int index = career.find(" ");

        if (index > -1) {
            string now = career.substr(0, index);
            career.replace(career.begin(), career.begin() + index + string(" ").length(), "");

            careers[now].Insert(career);
            careers[FIELD_ALL].Insert(career);
        }
        else {
            scores.push_back(stoi(career));
        } 
    }

    int Find(vector<string> query) {
        if (query.size() - 1 > myTier) {
            return careers[query[myTier]].Find(query);
        }
        else {
            if (query[myTier] == "-") {
                return scores.size();
            }
            else {
                if (!isSorted) {
                    sort(scores.begin(), scores.end());
                    isSorted = true;
                }
                return distance(lower_bound(scores.begin(), scores.end(), stoi(query[myTier])), scores.end());
            }
        }
    }

    map<string, Container> careers;
    vector<int> scores;
    int myTier = 0;
    bool isSorted = false;
};

vector<string> Split(string s, string c) {
    Container myContainer;

    vector<string> result;
    int index = s.find(c);
    
    while (index > -1) {
        result.push_back(s.substr(0, index));
        s.replace(s.begin(), s.begin() + index + c.length(), "");
        index = s.find(c);
    }

    result.push_back(s);

    if (result.size() > 2) {
        vector<string> split_blank = Split(result[result.size() - 1], " ");
        result.erase(result.end() - 1);
        result.insert(result.end(), split_blank.begin(), split_blank.end());
    }
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    const vector<vector<string>> FIELDES = {
        {"cpp", "java", "python", FIELD_ALL},
        {"backend", "frontend", FIELD_ALL},
        {"junior", "senior", FIELD_ALL},
        {"chicken", "pizza", FIELD_ALL}
    };

    vector<int> result;
    Container myCareers;
    myCareers.Initialize(FIELDES, 0);
    
    for (string inf : info) {
        myCareers.Insert(inf);
    }

    for (string que : query) {
        result.push_back(myCareers.Find(Split(que, " and ")));
    }

    return result;
}

int main() {
    vector<string> info = {
        "java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50"
    };

    vector<string> query = {
        "java and backend and junior and pizza 100",
        "python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250",
        "- and backend and senior and - 150",
        "- and - and - and chicken 100",
        "- and - and - and - 150"
    };

    solution(info, query);
}