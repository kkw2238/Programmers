/*
	https://school.programmers.co.kr/learn/courses/30/lessons/42891
*/

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long memFoodCount = food_times.size();
    long long totalTime = 0;
    map<long long, long long> foods;

    for (int food_time : food_times)
    {
        ++foods[food_time];
        totalTime += (long long)food_time;
    }

    if (totalTime <= k)
    {
        return -1;
    }

    long long memBeforeFood = 0;
    for (auto food : foods)
    {
        long long ateFood = memFoodCount * (food.first - memBeforeFood);
        if (ateFood >= k)
        {
            break;
        }
        k -= ateFood;
        memBeforeFood = food.first;
        memFoodCount -= food.second;
    }

    int index = k % memFoodCount + 1;
    
    for (int i = 0; i < food_times.size(); ++i)
    {
        if (food_times[i] > memBeforeFood)
        {
            --index;
        }
        if (index == 0)
        {
            return i + 1;
        }
    }
}