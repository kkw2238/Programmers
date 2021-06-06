/*
	https://programmers.co.kr/learn/courses/30/lessons/42583
*/

#include <vector>
#include <queue>

#define IsFullBridge(x, y) x < y
#define IsEnoughWeight(x, y) x <= y
#define IsCompleted(x, y) x - y <= 0

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<pair<int, int>> trucksOnBrigde;
	int elapsedTime = 1;
	int truckCounts = 1;
	int trucksOnBrigdeTotalWeight = truck_weights.front();
	
	trucksOnBrigde.push(pair(bridge_length, truck_weights.front()));

	while (truck_weights.size() > truckCounts || !trucksOnBrigde.empty())
	{
		if (!trucksOnBrigde.empty() && IsCompleted(trucksOnBrigde.front().first, elapsedTime))
		{
			trucksOnBrigdeTotalWeight -= trucksOnBrigde.front().second;
			trucksOnBrigde.pop();
		}

		if (truckCounts < truck_weights.size() 
			&& IsFullBridge(trucksOnBrigde.size(), bridge_length) 
			&& IsEnoughWeight((truck_weights[truckCounts] + trucksOnBrigdeTotalWeight), weight))
		{
			trucksOnBrigdeTotalWeight += truck_weights[truckCounts];
			trucksOnBrigde.push(pair(elapsedTime++ + bridge_length, truck_weights[truckCounts++]));
		}
		else if(!trucksOnBrigde.empty())
		{
			elapsedTime += (trucksOnBrigde.front().first - elapsedTime);
		}
	}

	return elapsedTime + 1;
}

/* 예전 코드
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<pair<int, int>> truckWeightsNElpasedTimes;
	int time = 1, nowWeight = 0;

	while (truck_weights.size() != 0 || truckWeightsNElpasedTimes.size() != 0) {
		if (truck_weights.size() > 0) {
			if (nowWeight + truck_weights.front() <= weight) {
				truckWeightsNElpasedTimes.push(pair<int, int>(truck_weights.front(), time));

				nowWeight += truck_weights.front();
				truck_weights.erase(truck_weights.begin());
			}
		}

		++time;
		pair<int, int> weightntime = truckWeightsNElpasedTimes.front();
		if (time - weightntime.second >= bridge_length) {
			truckWeightsNElpasedTimes.pop();
			nowWeight -= weightntime.first;
		}
	}

	return time;
}
*/