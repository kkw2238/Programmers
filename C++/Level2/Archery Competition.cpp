/*
	https://programmers.co.kr/learn/courses/30/lessons/92342
*/

#include <string>
#include <vector>
#include <bitset>

using namespace std;

/*
    1. 0 ~ 10�� ���̿��� �̱�� ����� ���� ��� ���� 
        => �� 1024���� ����� �� 
    2. �̱�µ� �ʿ��� ���� > n �� ��� fail
    2 - 1. �̱�µ� �ʿ��� ���� <= n �� ��� �ش� ���¸� ���
*/

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(info.size());
    bitset<10> remember_try = 0;
    int maximum_score = 0;

    for (int i = 0; i < 1024; ++i)
    {
        bitset<10> bs(i);
        int shoot_try = 0;
        int difference_score = 0; 

        for (int l = 0; l < bs.size(); ++l)
        {
            if (bs[l] == 1)
            {
                shoot_try += (info[l] + 1);
                difference_score += (10 - l);
            }
            else if(info[l] > 0)
            {
                difference_score -= (10 - l);
            }

            if (shoot_try > n)
            {
                break;
            }
        }

        if(shoot_try <= n && difference_score >= maximum_score)
        {
            maximum_score = difference_score;
            remember_try = bs;
        }
    }

    for (int i = remember_try.size() - 1; i >= 0; --i)
    {
        if (remember_try[i] == 0)
        {
            continue;
        }

        answer[i] = info[i] + 1;
        n -= (info[i] + 1);
    }

    answer[10] += n;

    return maximum_score == 0 ? vector{ -1 } : answer;
}