/*
	https://programmers.co.kr/learn/courses/30/lessons/1832
*/

#include <vector>

using namespace std;

enum { DOWN, RIGHT };
enum { FREE, CURFEW, STRAIGHT };

const int MOD = 20170805;
const vector<pair<int, int>> DIR{ pair(0, 1), pair(1, 0) };

const pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b)
{
    return pair(a.first + b.first, a.second + b.second);
}

int solution(int m, int n, vector<vector<int>> city_map) {
    // map[..][..][0] = 아래 방향으로 진행할 때의 경우의 수 map[..][..][1] = 오른쪽 방향으로 진행할때의 경우의 수
    int map[500][500][2] = { 0 }; // <= 전역변수로 설정할 경우 실패로 뜸
    
    // 골인 지점은 ..[0] ..[1] 둘 중 한곳에 1 삽입 => 상관 X
    map[m - 1][n - 1][RIGHT] = 1;

    for (int y = m - 1; y >= 0; --y)
    {
        for (int x = n - 1; x >= 0; --x)
        {
            pair position(y, x);

            // 진입 금지인 경우 
            if (city_map[y][x] == CURFEW)
            {
                continue;
            }

            for (int dir = 0; dir < 2; ++dir)
            {
                // 오른쪽, 하단의 위치
                position = pair(y, x) + DIR[dir];

                // 맵 이탈 여부
                if (position.first >= m || position.second >= n)
                {
                    continue;
                }

                // position에 존재하는 표지판에 따라 다른 결과 도출
                switch (city_map[position.first][position.second])
                {
                    // Free인 경우 position에서 우측 / 하단에 대한 모든 경우의 수를 가져온다.
                case FREE:
                    map[y][x][dir] += map[position.first][position.second][1 - dir];
                case STRAIGHT:
                    // Straight( 직진 )인 경우 position에서 현재 진행방향( dir )에 대한 정보만 읽어온다.
                    map[y][x][dir] += map[position.first][position.second][dir];
                    map[y][x][dir] %= MOD;
                    break;
                default:
                    break;
                }
            }
        }
    }

    return (map[0][0][DOWN] + map[0][0][RIGHT]) % MOD;
}