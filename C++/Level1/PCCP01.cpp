
/*
    https://school.programmers.co.kr/learn/courses/30/lessons/250137?language=cpp
*/

#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxHealth = health;
    int nowTime = 0;

    for (vector<int>& attack : attacks)
    {
        int elapsedTime = attack[0] - nowTime - 1;

        health = min(maxHealth, health + bandage[1] * elapsedTime + bandage[2] * (elapsedTime / bandage[0]));
        health -= attack[1];
        nowTime = attack[0];

        if (health <= 0)
        {
            return -1;
        }
    }

    return health;
}