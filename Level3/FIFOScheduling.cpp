/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12920
*/
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(int n, vector<int> cores) {
    int time = 0;
    map<int, vector<int>> coreProcessTime;

    for (int i = 0; i < cores.size(); ++i)
    {
        coreProcessTime[cores[i]].push_back(i + 1);
    }

    int tmpN = n;
    int left = 0;
    int right = 50000;
    
    while (right > left)
    {
        tmpN = n;
        int mid = (left + right) / 2;

        for (auto core : coreProcessTime)
        {
            tmpN -= (tmpN / core.first) * core.second.size();
        }

        if (tmpN < 0)
        {
            return 1;
        }
        else if(tmpN > 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
//
//int main()
//{
//    solution(6, { 1, 2, 3 });
//}


#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    n -= cores.size();

    return 0;
}