/*
	https://programmers.co.kr/learn/courses/30/lessons/1832
*/

#include <vector>

using namespace std;

enum { DOWN, RIGHT };
enum {FREE, CURFEW, STRAIGHT };

const int MOD = 20170805;
const vector<pair<int, int>> DIR{ pair(0, 1), pair(1, 0) };

pair<int, int> goal;

const pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b)
{
    return pair(a.first + b.first, a.second + b.second);
}

int DFS(const pair<int, int> position, const int beforeDir, const vector<vector<int>>& city_map)
{
    if (position == goal)
    {
        return 1;
    }

    if (position.first >= city_map.size() || position.second >= city_map[0].size())
    {
        return 0;
    }

    int result = 0;
    const int anotherDir = RIGHT - beforeDir;

    switch (city_map[position.first][position.second])
    {
    case CURFEW:
        return 0;
    case FREE:
        result += DFS(position + DIR[anotherDir], anotherDir, city_map);
    case STRAIGHT:
        result += DFS(position + DIR[beforeDir], beforeDir, city_map);
        break;
    }
    
    return result % MOD;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    goal = pair(m - 1, n - 1);
    return DFS(pair(0, 0), DOWN, city_map);
}

int main()
{
    solution(3, 3, { {0,0,0}, {0,0,0}, {0,0,0} });
}