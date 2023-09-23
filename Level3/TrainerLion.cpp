/*
    https://school.programmers.co.kr/learn/courses/30/lessons/1838
*/

//
//int solution(int n, int m, vector<vector<int>> timetable) {
//    int answer = 0;
//    int offset[3] = { 1,1,2 };
//    
//    sort(timetable.begin(), timetable.end(), [](const vector<int>& a, const vector<int>& b) {
//        if (a[0] == b[0])
//        {
//            return a[1] < b[1];
//        }
//
//        return a[0] < b[0];
//        });
//
//    int maximumCustomer = 0;
//    int customer = 0;
//    int beg = 0;
//    int time = 0;
//
//    for (int i = 0; i < timetable.size(); ++i)
//    {
//        time = timetable[i][0];
//        ++customer;
//
//        while (beg < i && timetable[beg][1] < time)
//        {
//            ++beg;
//            --customer;
//        }
//
//        if (customer > maximumCustomer)
//        {
//            maximumCustomer = customer;
//        }
//    }
//
//    if (maximumCustomer == 1)
//    {
//        return 0;
//    }
//    if (maximumCustomer == 2)
//    {
//        return (n - 1) * 2;
//    }
//    if (maximumCustomer == 3)
//    {
//        return -1 + (n / 3) * 4 + offset[(n - 1) % 3];;
//    }
//    if (maximumCustomer == 4)
//    {
//        return n - 1;
//    }
//    if (maximumCustomer == 5)
//    {
//        return n / 2 + n % 2;
//    }
//    if (maximumCustomer > ((n * n) / 2))
//    {
//        return 1;
//    }
//    
//    vector<vector<int>> board(n, vector<int>(n, 1));
//
//
//
//
//    return answer;
//}

//int solution(int n, int m, vector<vector<int>> timetable) {
//    int answer = 0;
//    int maximum_customer = 0;
//    vector<int> timeAtcustomer(1322, 0);
//    
//    for (const vector<int>& time : timetable)
//    {
//        timeAtcustomer[time[0]]++;
//        timeAtcustomer[time[1] + 1]--;
//    }
//
//    int sumOfCustomer = 0;
//    for (int i = 0; i < timeAtcustomer.size(); ++i)
//    {
//        sumOfCustomer += timeAtcustomer[i];
//        maximum_customer = max(maximum_customer, sumOfCustomer);
//    }
//
//    if (maximum_customer == 1)
//    {
//        return 0;
//    }
//    else if (maximum_customer == 2)
//    {
//        return (n - 1) * 2;
//    }
//    else if (maximum_customer == 3)
//    {
//        return max(n, min(n + 2, (n - 3) * 2));
//    }
//    else if (maximum_customer == 4)
//    {
//        return n - 1;
//    }
//    else if (maximum_customer > (n * n + 1) / 2)
//    {
//        return 1;
//    }
//
//    return answer;
//}
//
//#include <iostream>
//
//vector<vector<int>> map;
//
//int dist(int x, int y, int x2, int y2)
//{
//    return max(x2, x) - min(x2, x) + max(y2, y) - min(y2, y);
//}
//
//int DFS(int w, int n, int x, int y, vector<vector<int>>& before)
//{
//    int result = 0;
//    if (!before.empty())
//    {
//        for (vector<int>& b : before)
//        {
//            result = max(result, dist(x, y, b[0], b[1]));
//        }
//
//        if (result <= 1 || n == 0)
//        {
//            return result;
//        }
//    }
//
//    for (int i = x + 1; i < w; ++i)
//    {
//        for (int j = y; j < w; ++j)
//        {
//            before.push_back({ i, j });
//            result = max(result, DFS(w, n - 1, i, j, before));
//            before.pop_back();
//        }
//    }
//
//    return result;
//}
//
//int main()
//{
//    vector<vector<int>> b;
//    for (int i = 2; i <= 10; ++i)
//    {
//        for (int d = 1; d <= (i * i + 1) / 2; ++d)
//        {
//            cout << i << " : " << d << " = " << DFS(i, d, -1, 0, b) << '\n';
//            if(!b.empty())
//                b.clear();
//        }
//    }
//    for (int i = 2; i <= 10; ++i)
//    {
//        cout << i << ' ' << (i * i + 1) / 2 << '\n';
//    }
//    //solution(3, 2, { {1200, 1210},{1210, 1260} });
//}

//void DFS(int index, int maxCustomer, set<int>& lockerRoom, int minDist)
//{
//    minDist = min(minDist, getNearDistance(index, lockerRoom));
//
//    if (minDist <= nearestDist)
//    {
//        return;
//    }
//
//    if (lockerRoom.size() == maxCustomer)
//    {
//        nearestDist = max(nearestDist, minDist);
//        if (nearestDist == minDist)
//        {
//            tmp = lockerRoom;
//        }
//        return;
//    }
//
//    int reamin = maxCustomer - lockerRoom.size();
//    for (int i = index + 1; i < (width * width) - reamin; ++i)
//    {
//        lockerRoom.insert(i);
//        DFS(i, maxCustomer, lockerRoom, minDist);
//        lockerRoom.erase(i);
//    }
//}

//int solution(int n, int m, vector<vector<int>> timetable) {
//    width = n;
//
//    sort(timetable.begin(), timetable.end(), [](const vector<int>& a, const vector<int>& b) {
//        if (a[0] == b[0])
//        {
//            return a[1] < b[1];
//        }
//
//        return a[0] < b[0];
//        });
//
//    int maximumCustomer = 0;
//    int customer = 0;
//    int beg = 0;
//    int time = 0;
//
//    for (int i = 0; i < timetable.size(); ++i)
//    {
//        time = timetable[i][0];
//        ++customer;
//
//        while (beg < i && timetable[beg][1] < time)
//        {
//            ++beg;
//            --customer;
//        }
//
//        if (customer > maximumCustomer)
//        {
//            maximumCustomer = customer;
//        }
//    }
//
//    if (maximumCustomer > (n * n) / 2)
//    {
//        return 1;
//    }
//
//    set<int> lockerRoom;
//    for (int i = 0; i <= (n * n - maximumCustomer); ++i)
//    {
//        lockerRoom.insert(i);
//        DFS(i, maximumCustomer, lockerRoom, 200);
//        lockerRoom.erase(i);
//    }
//
//    if (nearestDist == 200)
//    {
//        return 0;
//    }
//    return nearestDist;
//}
//



/*
* 
* 
    
int tmpFunc(int n, int dist)
{
    int maximum = 0;
    set<int> index;
    for (int begin = 0; begin < n; ++begin)
    {
        index.insert(begin);
        for (int offset = begin + 1; offset < n * n; ++offset)
        {

            index.insert(offset);
            if (getNearDistance(offset, index) != dist)
            {
                index.erase(offset);
            }
        }

        maximum = max((int)index.size(), maximum);
        if (index.size() == maximum)
        {
            tmp = index;
        }
        index.erase(begin);
    }

    return maximum;
}
*/

//int main()
//{
//
//    //for (int w = 2; w <= 10; ++w)
//    //{
//    //    width = w;
//    //    for (int dist = 2; dist < 2 + (w - 2) * 2; ++dist)
//    //    {
//    //        cout << "width : " << w << " dist : " << dist << " result : " << tmpFunc(w, dist) << '\n';
//    //        Draw();
//    //    }
//    //    cout << '\n';
//    //}
//
//
//    for (int w = 8; w <= 8; ++w)
//    {
//        width = w;
//
//        for (int i = 2; i < (w * w) / 2; ++i)
//        {
//
//                mc = 0;
//                set<int> si = set<int>();
//                for (int beg = 0; beg < w; ++beg)
//                {
//                    si.insert(beg);
//                    DFS(beg, si, i);
//                    si.erase(beg);
//                }
//            
//
//            cout << "width : " << width << " dist : " << i << " maxCustomer : " << mc << '\n';
//        }
//
//        for (int maximum = 1; maximum <= 64; ++maximum)
//        {
//            nearestDist = 0;
//            set<int> si;
//
//            for (int i = 0; i <= (w * w) - maximum; ++i)
//            {
//                si.insert(i);
//                DFS(i, maximum, si, 200);
//                si.erase(i);
//            
//            }
//
//            cout << "width : " << width << " maximum : " << maximum << " nearest : " << nearestDist << '\n';
//            //Draw();
//
//            cout << "\n\n";
//            tmp = set<int>();
//        }
//    }
//}

#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;


int width;

vector<int> totalCount;

#include <iostream>

set<int> tmp;

void Draw()
{
    vector<int> vi(width * width, 0);

    for (int n : tmp)
    {
        if(n != width * width)
            vi[n] = 1;
    }
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cout << vi[i * width + j];
        }
        cout << '\n';
    }
}


int distan(int index, int other)
{
    int yoff = index / width - other / width;
    int xoff = index % width - other % width;

    return abs(yoff) + abs(xoff);
}

int getNearDistance(int index, set<int>& lockerRoom)
{
    int d = 200;

    for (int i : lockerRoom)
    {
        if (i != index)
        {
            d = min(d, distan(index, i));
        }
    }

    return d;
}

void DFS(int index, set<int>& lockerRoom, int targetDist)
{
    if (index == width * width)
    {
        totalCount[index] = max(totalCount[index], (int)lockerRoom.size() - 1);

        if (totalCount[index] == (int)lockerRoom.size() - 1)
        {
            tmp = lockerRoom;
        }
        return;
    }
    int minDist = getNearDistance(index, lockerRoom);

    if ((lockerRoom.size() > 1 && minDist != targetDist) || (totalCount[index] > (lockerRoom.size() - 1)))
    {
        return;
    }

    totalCount[index] = max(totalCount[index], (int)lockerRoom.size() - 1);

    for (int i = index + 1; i <= (width * width); ++i)
    {
        lockerRoom.insert(i);
        DFS(i, lockerRoom, targetDist);
        lockerRoom.erase(i);
    }
}

int solution(int n, int m, vector<vector<int>> timetable) {
    width = n;
    int answer = 0;
    sort(timetable.begin(), timetable.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }

        return a[0] < b[0];
        });

    int maximumCustomer = 0;
    for (int i = 0; i < timetable.size(); ++i)
    {
        int customer = 1;
        for (int j = i + 1; j < timetable.size(); ++j)
        {
            if (timetable[j][0] >= timetable[i][0] && timetable[j][0] <= timetable[i][1])
            {
                ++customer;
            }
            else
            {
                break;
            }
        }
        maximumCustomer = max(maximumCustomer, customer);
    }

    if (maximumCustomer <= 1 || n == 1)
    {
        return 0;
    }

    set<int> lockerRoom;
    for (int dist = 2; dist <= n * 2; ++dist)
    {
        int maxTotalCount = 0;
        for (int b = 0; b < n; ++b)
        {
            totalCount = vector<int>(101, 0);
            lockerRoom.insert(b);
            DFS(b, lockerRoom, dist);
            lockerRoom.erase(b);
            maxTotalCount = max(totalCount[n * n], maxTotalCount);
        }

        if (maxTotalCount >= maximumCustomer)
        {
            answer = max(answer, dist);
        }
        else
        {
            break;
        }
    }

    return answer;
}

int main()
{
    int n = 3;
    width = 8;
    set<int> lockerRoom;

    for (width = 2; width <= 10; ++width)
    {
        cout << "width : " << width << '\n';
        for (int dist = 1; dist <= width * 2 - 2; ++dist)
        {
            totalCount = vector<int>(101, 0);
            for (int b = 0; b < width; ++b)
            {
                lockerRoom.insert(b);
                DFS(b, lockerRoom, dist);
                lockerRoom.erase(b);
            }

            cout << "dist : " << dist << " totalCount : " << totalCount[width * width] << '\n';
        }
        cout << '\n';
    }

    for (width = 1; width <= 10; ++width)
    {
        cout << "width : " << width << '\n';

        for (int maxCustomer = 2; maxCustomer < width * width; ++maxCustomer)
        {
            int answer = 0;
            for (int dist = 1; dist <= width * 2; ++dist)
            {
                int maxTotalCount = 0;
                totalCount = vector<int>(101, 0);
                for (int b = 0; b < n; ++b)
                {
                    lockerRoom.insert(b);
                    DFS(b, lockerRoom, dist);
                    lockerRoom.erase(b);
                    maxTotalCount = max(totalCount[width * width], maxTotalCount);
                }

                if (maxTotalCount >= maxCustomer)
                {
                    answer = max(answer, dist);
                }
                else
                {
                    break;
                }
            }

            cout << "maxCustomer : " << maxCustomer << " dist : " << answer <<  '\n';
        }
        cout << '\n';
    }
    solution(4, 5, { {1140, 1200}, {1150, 1200}, {1100, 1200}, {1210, 1300}, {1220, 1280} });
    Draw();
}