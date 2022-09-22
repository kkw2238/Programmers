/*
    https://school.programmers.co.kr/learn/courses/30/lessons/1838
*/
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 0;
    int offset[3] = { 1,1,2 };
    
    sort(timetable.begin(), timetable.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }

        return a[0] < b[0];
        });

    int maximumCustomer = 0;
    int customer = 0;
    int beg = 0;
    int time = 0;

    for (int i = 0; i < timetable.size(); ++i)
    {
        time = timetable[i][0];
        ++customer;

        while (beg < i && timetable[beg][1] < time)
        {
            ++beg;
            --customer;
        }

        if (customer > maximumCustomer)
        {
            maximumCustomer = customer;
        }
    }

    switch (maximumCustomer)
    {
    case 1:
        return 0;
    case 2:
        return (n - 1) * 2;
    case 3:
        return -1 + (n / 3) * 4 + offset[(n - 1) % 3];
    case 4:
        return n - 1;
    case 5:
        return n / 2 + n % 2;
    default:
        break;
    }

    else if (maximumCustomer == 5)
    {
        
    }

    return answer;
}

int main()
{
    solution(3, 2, { {1200, 1210},{1200, 1260} });
}