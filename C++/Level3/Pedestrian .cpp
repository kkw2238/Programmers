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
    // map[..][..][0] = �Ʒ� �������� ������ ���� ����� �� map[..][..][1] = ������ �������� �����Ҷ��� ����� ��
    int map[500][500][2] = { 0 }; // <= ���������� ������ ��� ���з� ��
    
    // ���� ������ ..[0] ..[1] �� �� �Ѱ��� 1 ���� => ��� X
    map[m - 1][n - 1][RIGHT] = 1;

    for (int y = m - 1; y >= 0; --y)
    {
        for (int x = n - 1; x >= 0; --x)
        {
            pair position(y, x);

            // ���� ������ ��� 
            if (city_map[y][x] == CURFEW)
            {
                continue;
            }

            for (int dir = 0; dir < 2; ++dir)
            {
                // ������, �ϴ��� ��ġ
                position = pair(y, x) + DIR[dir];

                // �� ��Ż ����
                if (position.first >= m || position.second >= n)
                {
                    continue;
                }

                // position�� �����ϴ� ǥ���ǿ� ���� �ٸ� ��� ����
                switch (city_map[position.first][position.second])
                {
                    // Free�� ��� position���� ���� / �ϴܿ� ���� ��� ����� ���� �����´�.
                case FREE:
                    map[y][x][dir] += map[position.first][position.second][1 - dir];
                case STRAIGHT:
                    // Straight( ���� )�� ��� position���� ���� �������( dir )�� ���� ������ �о�´�.
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