/*
    https://programmers.co.kr/learn/courses/30/lessons/87391?language=cpp
*/

#include <vector>

using namespace std;

/*
    �� ��ȣ�� �����ϴ� �������� dxĭ �̵��ϴ� ���� (query(0, dx))
    �� ��ȣ�� �����ϴ� �������� dxĭ �̵��ϴ� ���� (query(1, dx))
    �� ��ȣ�� �����ϴ� �������� dxĭ �̵��ϴ� ���� (query(2, dx))
    �� ��ȣ�� �����ϴ� �������� dxĭ �̵��ϴ� ���� (query(3, dx))

    1. ������ ����ϸ鼭 ���� �̵��Ÿ��� ���
    => ���������� 0,0�̰� <- ���� ���°�� ���������� �� �̵��ϴ� ���� ����ϰ�
        Ư�� ��� ��� ���� �޶��� �� ����
        <- <- <- -> -> -> 0,0 -> 0,3 0,6 -> 0,6

2. �����¿�� �ִ�� �̵��� �Ÿ��� ���
    => �ش� �Ÿ����� ª�� ��ġ���� ������ ��� ���� �پ ���� �̵��Ÿ� �Ǵ�
    => ex) <- <- <- -> -> -> 1,0 -> 0,0 -> 0,3 0,5 -> 0,6 -> 0,6

3. 2. ����� �켱������ ���� ó���ؾ��ϴ� ���� �޶���
    -> 4���� ���� ?

ex) 	0 ~ 255 / 256 ~ 512 ������ 4���� �����Ͽ� ���
        => 255, 255�� ���� �̵��Ÿ���ŭ �̵� ��Ų �� ���� ��ġ -255, 255�� ���ϴ� ��ġ�� �ִ��� �Ǵ�.
        => ���� ��� �ش� ������ /4�� �ѹ� �� ����
        => ���� ��� skip
        => ��� ����
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