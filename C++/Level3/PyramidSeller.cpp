#include <string>
#include <vector>
#include <map>

using namespace std;

const int PRICE = 100;

struct PyramidMember
{
    int Income(int income)
    {
        int devined = income / 10;
        amount += (income - devined);
        return devined;
    }
    string referral;
    int amount;
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    map<string, PyramidMember> members;

    for (int i = 0; i < enroll.size(); ++i)
    {
        members[enroll[i]] = PyramidMember{ referral[i], 0 };
    }

    for (int i = 0; i < seller.size(); ++i)
    {
        string nowReferral = members[seller[i]].referral;
        int income = members[seller[i]].Income(amount[i] * PRICE);

        while (nowReferral.compare("-") != 0)
        {
            income = members[nowReferral].Income(income);
            nowReferral = members[nowReferral].referral;
        }
    }

    for (int i = 0; i < answer.size(); ++i)
    {
        answer[i] = members[enroll[i]].amount;
    }

    return answer;
}

int main()
{
    vector<string> enroll{ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    vector<string> referral{ "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    vector<string> seller{ "young", "john", "tod", "emily", "mary" };
    vector<int> amount{ 12, 4, 2, 5, 10 };

    solution(enroll, referral, seller, amount);
}