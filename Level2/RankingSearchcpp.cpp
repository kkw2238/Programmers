/* 
    https://programmers.co.kr/learn/courses/30/lessons/72412 
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const char ALL = '-';
const int SCROE_INDEX = 4;

class Trie
{
public:
    void Initialize(const vector<string>& info, int index)
    {
        // 각 항목의 첫 문자열은 모두 다르기에 char로 판단
        const char front = info[index].front();

        if (index != SCROE_INDEX)
        {
            /* 
                후 탐색 속도를 높히기 위해 front와 '-'에 각각 삽입
                 => ex 
                    [java][backend][junior][pizza]
                    [-][backend][junior][pizza]
                    [-][-][junior][pizza]
                    [-][-][-][pizzq]
                    ... 등등 총 16가지로 분할
            */
            nextTier[front].Initialize(info, index + 1);
            nextTier[ALL].Initialize(info, index + 1);
        }
        else
        {
            scores.push_back(stoi(info[index]));
        }
    }

    int GetCount(const vector<string>& query, int index)
    {
        const char front = query[index].front();

        if (index != SCROE_INDEX)
        {
            return nextTier[front].GetCount(query, index + 1);
        }
        else
        {
            return GetOverScoreCount(stoi(query[index]));
        }
        
        return 0;
    }

    const int GetOverScoreCount(int n)
    {
        // 해당 항목을 처음으로 참조할 경우 정렬 -> 참조 안할 경우 정렬을 할 필요가 X
        if (!sorted)
        {
            sort(scores.begin(), scores.end());
            // 중복 정렬을 막기 위해 이미 정렬을 했다는 flag를 설정한다.
            sorted = true;
        }

        return distance(lower_bound(scores.begin(), scores.end(), n), scores.end());
    }

public:
    vector<int> scores;
    map<char, Trie> nextTier;
    bool sorted = false;
};

vector<string> Split(string& info, const string& demi)
{
    vector<string> result;

    while (!info.empty())
    {
        // demi를 기준으로 분해
        int index = info.find(demi);

        if (index == string::npos)
        {
            break;
        }

        // 0 ~ demi를 발견한 구간까지 분리 후 삽입
        result.emplace_back(info.substr(0, index));

        info = info.substr(index + demi.length());
    }

    // 분리가 덜된 경우 예외 처리
    if (int index = info.find(" "); index != string::npos)
    {
        result.emplace_back(info.substr(0, index));
        info = info.substr(index + 1);
    }

    result.emplace_back(info);
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    Trie trie;

    for (string& s : info)
    {
        // info를 분해 후 Trie에 삽입
        trie.Initialize(Split(s, " "), 0);
    }

    for (string& q : query)
    {
        // query를 분해 후 탐색
        answer.emplace_back(trie.GetCount(Split(q, " and "), 0));
    }

    return answer;
}