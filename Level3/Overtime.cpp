#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

long long solution(int n, vector<int> works) {
    map<int, int> works_count;
    long long answer = 0;
    long long total_works = 0;

    for (const int work : works)
    {
        total_works += work;
        ++works_count[work];
    }

    if (total_works <= n)
    {
        return 0;
    }

    while (n > 0) 
    {
        auto iter = works_count.rbegin();

        pair<int, int> nowWork = *iter;
        pair<int, int> nextWork = *(++iter);
        
        int needWork = (nowWork.first - nextWork.first) / nowWork.second;
        
        if (needWork >= n)
        {
            works_count[nowWork.first - (needWork / nowWork.second)];

        }
    }
    
    return answer;
}