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
        // �� �׸��� ù ���ڿ��� ��� �ٸ��⿡ char�� �Ǵ�
        const char front = info[index].front();

        if (index != SCROE_INDEX)
        {
            /* 
                �� Ž�� �ӵ��� ������ ���� front�� '-'�� ���� ����
                 => ex 
                    [java][backend][junior][pizza]
                    [-][backend][junior][pizza]
                    [-][-][junior][pizza]
                    [-][-][-][pizzq]
                    ... ��� �� 16������ ����
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
        // �ش� �׸��� ó������ ������ ��� ���� -> ���� ���� ��� ������ �� �ʿ䰡 X
        if (!sorted)
        {
            sort(scores.begin(), scores.end());
            // �ߺ� ������ ���� ���� �̹� ������ �ߴٴ� flag�� �����Ѵ�.
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
        // demi�� �������� ����
        int index = info.find(demi);

        if (index == string::npos)
        {
            break;
        }

        // 0 ~ demi�� �߰��� �������� �и� �� ����
        result.emplace_back(info.substr(0, index));

        info = info.substr(index + demi.length());
    }

    // �и��� ���� ��� ���� ó��
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
        // info�� ���� �� Trie�� ����
        trie.Initialize(Split(s, " "), 0);
    }

    for (string& q : query)
    {
        // query�� ���� �� Ž��
        answer.emplace_back(trie.GetCount(Split(q, " and "), 0));
    }

    return answer;
}