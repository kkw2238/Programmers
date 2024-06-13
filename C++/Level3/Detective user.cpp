/*
    https://programmers.co.kr/learn/courses/30/lessons/64064
*/

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<vector<string>> combinations_Detected_Users;

// �ҷ� ����� ����� �����ϴ� �Լ�
void Combination(set<string> existedID, vector<vector<string>>& detectedUser, const int index)
{
    // ������ index���� �� ��� 
    if (index == detectedUser.size())
    {
        // ���� ���տ� ����
        combinations_Detected_Users.emplace(existedID.begin(), existedID.end());

        return;
    }

    for (int i = 0; i < detectedUser[index].size(); ++i)
    {
        // �̹� ��ܿ� �� ���̵� ���� �Ǵ�
        if (existedID.find(detectedUser[index][i]) != existedID.end())
        {
            continue;
        }

        set<string> newExistedID = existedID;

        newExistedID.insert(detectedUser[index][i]);
        Combination(newExistedID, detectedUser, index + 1);
    }
}

const bool Equal(const string& a, const string& b, vector<string>& detected_users)
{
    // length�� �ٸ� ��� ��ȯ
    if (a.length() != b.length())
    {
        return false;
    }

    for (int i = 0; i < a.length(); ++i)
    {
        // b( banned id )�� �ش� ���ڰ� * �� ��� 
        if (b[i] == '*' || (a[i] == b[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    detected_users.emplace_back(a);
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string>> all_Detected_User;

    for (int i = 0; i < banned_id.size(); ++i)
    {
        vector<string> detected_users;

        count_if(user_id.begin(), user_id.end(), [&](const string& id) {
            return Equal(id, banned_id[i], detected_users);
        });

        all_Detected_User.emplace_back(detected_users);
    }

    Combination(set<string>(), all_Detected_User, 0);
    
    return combinations_Detected_Users.size();
}