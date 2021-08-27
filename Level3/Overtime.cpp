/*
    https://programmers.co.kr/learn/courses/30/lessons/12927
*/

#include <vector>
#include <map>

using namespace std;

long long solution(int n, vector<int> works) {
    /*
    * works_count = 남은 일, 동일하게 남은 일의 개수를 저장하는 map
         => rend 오류 방지용 0, 0 삽입
    */

    map<int, int> works_count{ pair(0, 0) };

    long long answer = 0;
    // 남은 총합 일
    long long total_works = 0;

    for (const int work : works)
    {
        total_works += work;
        // 동일한 능률을 가진 사원들을 묶어 놓는다.
        ++works_count[work];
    }

    // 모든 사원의 능률 합이 해야할 일보다 많을 경우 
    if (total_works <= n)
    {
        return 0;
    }
    /*
        야근지수를 낮추려면
            => 남은 일의 양이 제일 많은 것을 없애 나가야한다.
            => 남은 일의 양이 제일 많은 것이 다수일 경우 => 균일하게 없애 나간다.
    */
    while (n > 0) 
    {
        // *iter = 해야할 업무가 제일 많은 일
        auto iter = works_count.rbegin();

        pair<int, int> mostWorks = *iter++;
        // 다음으로 해야할 업무가 제일 많은 일
        pair<int, int> nextMostWorks = *iter;

        /* 
            needWork = 현재 제일 많이 남아 있는 일들의 진척도를 
                다음으로 제일 많이 남아있는 일만큼 남기는데 필요한 시간의 양
        */
        int needWork = (mostWorks.first - nextMostWorks.first) * mostWorks.second;
        
        // 동일한 진척도를 가진 일의 수를 임시 저장
        int nowEmplyeeCount = mostWorks.second;
        // 가급적이면 모든 일이 동시에 진행되는 것이므로 제일 많이 남아있는 일의 수를 0으로 변경
        works_count[mostWorks.first] = 0;

        // 동시에 처리할 일의 양이 시간보다 많은 경우 => 처리 불가 상태
        if (needWork > n)
        {
            // 처리가 불가한 경우 균일하게
            int nextWork = mostWorks.first - n / mostWorks.second;
            works_count[nextWork] = nowEmplyeeCount - n % nowEmplyeeCount;

            if (n % nowEmplyeeCount > 0)
            {
                works_count[nextWork - 1] += n % nowEmplyeeCount;
            }
        }
        else // 동시에 처리할 일의 양이 시간보다 적은 경우 => 모두 처리 가능
        {
            works_count[nextMostWorks.first] += nowEmplyeeCount;
            nextMostWorks.second += nowEmplyeeCount;
        }

        // 제일 많이 남은 일의 갯수가 0인 경우 => 모두 처리 상태인 경우
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
    1. needWork = ( 맨 뒤의 시간 - 바로 직전의 시간 ) * 인구 수

    2. 만약 needWork > N일 경우
        => works_count[ nowWork - N / 인구수 ] = 인구수 - N % 인구수 
        => works_count[ nowWork - N / 인구수 - 1 ] = N % 인구수
        => erase - nowWork

    3. 만약 needWork <= N일 경우
        => N - needWork로 계산 

    
*/