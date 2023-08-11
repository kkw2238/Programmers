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

#include <iostream>

int main()
{
    vector<int> food_times;

    for (int k = 1; k <= 2000000; ++k)
    {
        for (int i = 1; i <= 2000; ++i)
        {
            food_times.push_back(0);
            for (int j = 1; j <= 1000; ++j)
            {
                food_times[i - 1] = j;

                solution({ 7, 8, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2 }, 35);
            }
        }
    }
}