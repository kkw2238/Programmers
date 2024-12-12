/*
	https://school.programmers.co.kr/learn/courses/30/lessons/340211
*/

#include <vector>
#include <set>
#include <queue>

using namespace std;

struct Robot {
    int nowX, nowY;
    int destX, destY;
    queue<vector<int>> dests;
    bool isActive = true;

    void setDests(queue<vector<int>>& dest) {
        setPos(dest.front());
        setDest(dest.front());
        dest.pop();

        dests = dest;
    }

    void move() {
        if (nowX != destX) {
            nowX += getDir(nowX, destX);
        }
        else if (nowY != destY) {
            nowY += getDir(nowY, destY);
        }

        if (isGoal()) {
            if (dests.empty()) {
                isActive = false;
            }
            else {
                setDest(dests.front());
                dests.pop();
            }
        }
    }

    void setPos(vector<int>& pos) {
        nowX = pos[0];
        nowY = pos[1];
    }

    void setDest(vector<int>& next) {
        destX = next[0];
        destY = next[1];
    }

    vector<int> getPos() const {
        return {nowX, nowY};
    }

private: 
    bool isGoal() const {
        return (nowX == destX) && (nowY == destY);
    }

    int getDir(int now, int dest) {
        if (now > dest) {
            return -1;
        }
        else {
            return 1;
        }
    }
};

#include <iostream>

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    set<vector<int>> nowRobotPos;
    set<vector<int>> collisionPos;
    vector<Robot> robots(routes.size());

    for (int i = 0; i < routes.size(); ++i) {
        queue<vector<int>> dests;

        for (int n : routes[i]) {
            dests.push(points[n - 1]);
        }

        robots[i].setDests(dests);
    }

    bool run = true;
    while (run) {
        run = false;

        nowRobotPos.clear();
        collisionPos.clear();

        for (Robot& robots : robots) {
            run |= robots.isActive;

            if (!robots.isActive) {
                continue;
            }
            robots.move();
            auto result = nowRobotPos.insert(robots.getPos());
            if (!result.second) {
                collisionPos.insert(robots.getPos());
            }
        }

        cout << collisionPos.size() << '\n';
        answer += collisionPos.size();
    }

    return answer;
}