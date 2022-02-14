/*
    https://programmers.co.kr/learn/courses/30/lessons/87391?language=cpp
*/

#include <vector>

using namespace std;

/*
    열 번호가 감소하는 방향으로 dx칸 이동하는 쿼리 (query(0, dx))
    열 번호가 증가하는 방향으로 dx칸 이동하는 쿼리 (query(1, dx))
    행 번호가 감소하는 방향으로 dx칸 이동하는 쿼리 (query(2, dx))
    행 번호가 증가하는 방향으로 dx칸 이동하는 쿼리 (query(3, dx))

    1. 쿼리를 계산하면서 최종 이동거리를 계산
    => 시작지점이 0,0이고 <- 부터 나온경우 오른쪽으로 더 이동하는 경우와 비슷하게
        특정 경우 결과 값이 달라질 수 있음
        <- <- <- -> -> -> 0,0 -> 0,3 0,6 -> 0,6

2. 상하좌우로 최대로 이동한 거리를 기억
    => 해당 거리보다 짧은 위치에서 시작할 경우 벽에 붙어서 최종 이동거리 판단
    => ex) <- <- <- -> -> -> 1,0 -> 0,0 -> 0,3 0,5 -> 0,6 -> 0,6

3. 2. 방법은 우선순위에 따라 처리해야하는 것이 달라짐
    -> 4개씩 분할 ?

ex) 	0 ~ 255 / 256 ~ 512 나눠서 4개씩 분할하여 계산
        => 255, 255를 최종 이동거리만큼 이동 시킨 후 최종 위치 -255, 255에 원하는 위치가 있는지 판단.
        => 있을 경우 해당 영역을 /4로 한번 더 분할
        => 없을 경우 skip
        => 계속 분할
*/

enum { LEFT, RIGHT, UP, DOWN};

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;

    for (vector<int>& query : queries)
    {
        switch (query[0])
        {
        case LEFT:
            break;
        case RIGHT:
            break;
        case UP:
            break;
        case DOWN:
            break;
        }
    }

    return answer;
}