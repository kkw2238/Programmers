/*
	https://school.programmers.co.kr/learn/courses/30/lessons/150369
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    while (n >= 0)
    {
        int pickupCount = cap;
        int deliveryCount = cap;

        answer += (n * 2);

        for (int i = n - 1; i >= 0; --i)
        {
            if (deliveryCount > 0)
            {
                deliveries[i] -= deliveryCount;
                deliveryCount = -deliveries[i];
            }
            if (pickupCount > 0)
            {
                pickups[i] -= pickupCount;
                pickupCount = -pickups[i];
            }

            if (pickupCount <= 0 && deliveryCount <= 0)
            {
                break;
            }
        }

        while (pickups[n - 1] <= 0 && deliveries[n - 1] <= 0)
        {
            --n;
        }
    }

    return answer;
}