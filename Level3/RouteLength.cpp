#include <string>
#include <map>
#include <set>
using namespace std;

using Point = pair<int, int>;

bool Move(Point& human, const Point dir) {
    human.first += dir.first;
    if (human.first > 5 || human.first < -5) {
        human.first -= dir.first;
        return false;
    }

    human.second += dir.second;
    if(human.second > 5 || human.second < -5) {
        human.second -= dir.second;
        return false;
    }

    return true;
}

#include <iostream>

char opposite(const int n) {
    const char opposites[4] = { 'U', 'R', 'D', 'L' };
    return opposites[(n + 2) % 4];
}

int solution(string dirs) {
    map<Point, set<char>> usedRoad;
    map<char, int> index = { pair<char, int>{'U', 0}, pair<char, int>{'R', 1}, pair<char, int>{'D', 2}, pair<char, int>{'L', 3} };
    const Point MOVE[4] = { Point{0, 1}, Point{1, 0}, Point{0, -1},  Point{-1, 0} };
    Point pos = { 0, 0 };

    int answer = 0;

    for (char c : dirs) {
        usedRoad[pos].insert(c);
        if (Move(pos, MOVE[index[c]])) usedRoad[pos].insert(opposite(index[c]));
        else usedRoad[pos].erase(c);
    }

    for (const pair<Point, set<char>>& p : usedRoad)
        answer += p.second.size();

    return answer / 2;
}



int main() {
    string dirs = "LULLLLLLU";
    cout << solution(dirs);
}