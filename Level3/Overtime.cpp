/*
    https://programmers.co.kr/learn/courses/30/lessons/12927
*/

#include <vector>
#include <map>

using namespace std;

long long solution(int n, vector<int> works) {
    /*
    * works_count = ���� ��, �����ϰ� ���� ���� ������ �����ϴ� map
         => rend ���� ������ 0, 0 ����
    */

    map<int, int> works_count{ pair(0, 0) };

    long long answer = 0;
    // ���� ���� ��
    long long total_works = 0;

    for (const int work : works)
    {
        total_works += work;
        // ������ �ɷ��� ���� ������� ���� ���´�.
        ++works_count[work];
    }

    // ��� ����� �ɷ� ���� �ؾ��� �Ϻ��� ���� ��� 
    if (total_works <= n)
    {
        return 0;
    }
    /*
        �߱������� ���߷���
            => ���� ���� ���� ���� ���� ���� ���� �������Ѵ�.
            => ���� ���� ���� ���� ���� ���� �ټ��� ��� => �����ϰ� ���� ������.
    */
    while (n > 0) 
    {
        // *iter = �ؾ��� ������ ���� ���� ��
        auto iter = works_count.rbegin();

        pair<int, int> mostWorks = *iter++;
        // �������� �ؾ��� ������ ���� ���� ��
        pair<int, int> nextMostWorks = *iter;

        /* 
            needWork = ���� ���� ���� ���� �ִ� �ϵ��� ��ô���� 
                �������� ���� ���� �����ִ� �ϸ�ŭ ����µ� �ʿ��� �ð��� ��
        */
        int needWork = (mostWorks.first - nextMostWorks.first) * mostWorks.second;
        
        // ������ ��ô���� ���� ���� ���� �ӽ� ����
        int nowEmplyeeCount = mostWorks.second;
        // �������̸� ��� ���� ���ÿ� ����Ǵ� ���̹Ƿ� ���� ���� �����ִ� ���� ���� 0���� ����
        works_count[mostWorks.first] = 0;

        // ���ÿ� ó���� ���� ���� �ð����� ���� ��� => ó�� �Ұ� ����
        if (needWork > n)
        {
            // ó���� �Ұ��� ��� �����ϰ�
            int nextWork = mostWorks.first - n / mostWorks.second;
            works_count[nextWork] = nowEmplyeeCount - n % nowEmplyeeCount;

            if (n % nowEmplyeeCount > 0)
            {
                works_count[nextWork - 1] += n % nowEmplyeeCount;
            }
        }
        else // ���ÿ� ó���� ���� ���� �ð����� ���� ��� => ��� ó�� ����
        {
            works_count[nextMostWorks.first] += nowEmplyeeCount;
            nextMostWorks.second += nowEmplyeeCount;
        }

        // ���� ���� ���� ���� ������ 0�� ��� => ��� ó�� ������ ���
        if (works_count[mostWorks.first] == 0)
        {
            works_count.erase(mostWorks.first);
        }

        n -= needWork;
    }
    
    for (auto work_count : works_count)
    {
        answer += work_count.first * work_count.first * work_count.second;
    }

    return answer;
}

/*
    1. needWork = ( �� ���� �ð� - �ٷ� ������ �ð� ) * �α� ��

    2. ���� needWork > N�� ���
        => works_count[ nowWork - N / �α��� ] = �α��� - N % �α��� 
        => works_count[ nowWork - N / �α��� - 1 ] = N % �α���
        => erase - nowWork

    3. ���� needWork <= N�� ���
        => N - needWork�� ��� 

    
*/