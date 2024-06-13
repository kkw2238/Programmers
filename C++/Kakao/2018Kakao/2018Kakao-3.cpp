
#include <vector>
#include <algorithm>

using namespace std;

const int REMAINFOOD = -2;

const long long GetNotExistFoodsCount(const vector<int> food_times) {
	return count_if(food_times.cbegin(), food_times.cend(), [](const int a) { return a <= 0; });
}

const bool IsNotExistFood(const size_t remainFoodCount) {
	return remainFoodCount == 0;
}

const int Decrease(int a) {
	return max(0, a - 1);
}

const int DecreaseFoodTimes(vector<int>& food_times) {
	transform(food_times.begin(), food_times.end(), food_times.begin(), Decrease);
	return REMAINFOOD;
}

const int FindFoodIndex(const vector<int>& food_times, long long& k) {
	int count = 0;
	auto iter = find_if(food_times.begin(), food_times.end(), [&count, &k](const int a) {
		if (a > 0) ++count;
		return count >= static_cast<int>(k + 1);
		});

	return distance(food_times.begin(), iter);
}

int AteFood(vector<int>& food_times, long long& k) {
	long long notexistFoodsCount = GetNotExistFoodsCount(food_times);
	size_t remainFoodsCount = food_times.size() - notexistFoodsCount;

	if (IsNotExistFood(remainFoodsCount)) return -1;
	if (remainFoodsCount <= k) {
		k -= remainFoodsCount;
		return DecreaseFoodTimes(food_times);
	}
	else
		return FindFoodIndex(food_times, k);

	return REMAINFOOD;
}

int solution(vector<int> food_times, long long k) {
	int answer = REMAINFOOD, elapsed_time = 0;

	while (answer == REMAINFOOD)
		answer = AteFood(food_times, k);

	return answer + 1;
}