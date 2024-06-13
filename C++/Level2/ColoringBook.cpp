#include <vector>

using namespace std;

struct Point {
    enum {LEFT, RIGHT, UP, DOWN};
    Point(int newX, int newY) {
        x = newX;
        y = newY;
    }

    int x = 0;
    int y = 0;

    Point move(int type) {
        Point p( 0, 0 );

        switch (type)
        {
        case LEFT:
            p.x = x - 1;
            p.y = y;
            break;
        case RIGHT:
            p.x = x + 1;
            p.y = y;
            break;
        case UP:
            p.x = x;
            p.y = y - 1;
            break;
        case DOWN:
            p.x = x;
            p.y = y + 1;
            break;
        }

        return p;
    }
};

const int BLACK = 0;

int DFS(Point pos, const vector<vector<int>>& picture, vector<vector<bool>>& path, int& size, const int color) {
    if (pos.x >= picture.size() || pos.x < 0) return size;
    else if (pos.y >= picture[0].size() || pos.y < 0) return size;

    if (picture[pos.x][pos.y] == BLACK) {
        path[pos.x][pos.y] = true;
        return 0;
    }

    if (path[pos.x][pos.y] || picture[pos.x][pos.y] != color) return size;

    ++size;
    path[pos.x][pos.y] = true;

    for (int i = 0; i < 4; ++i) {
        DFS(pos.move(i), picture, path, size, color);
    }
   
    return size;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<bool>> path(m, vector<bool>(n));
    vector<int> answer(2);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int size = 0;
            size = DFS(Point( i, j ), picture, path, size, picture[i][j]);
            if (size > 0)
                ++number_of_area;
            max_size_of_one_area = size > max_size_of_one_area ? size : max_size_of_one_area;
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

void main()
{
    int m = 6;
    int n = 4;

    vector<vector<int>> picture = { 
        {1, 1, 1, 0},
        {1, 2, 2, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 3},
        {0, 0, 0, 3} 
    };

    solution(m, n, picture);
}