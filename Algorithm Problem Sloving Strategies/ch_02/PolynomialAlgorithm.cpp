#include <vector>

using namespace std;

vector<vector<int>> ableEatFood 
{
	{ false, true, true, true, false, false},
	{ false, false, false, false, true, true},
	{ true, false, true, false, true, false},
	{ true, true, false, false, false, true}
};

const int FOOD_TYPE = 6;
const int NUMBER_OF_PEOPLE = 4;

// 모두 먹을 수 있는 음식 조합인지 판단해주는 함수
const bool isAbleEverybodyEat(const vector<int>& foods)
{
	vector<bool> eatFood(NUMBER_OF_PEOPLE, false);
	bool result = true;

	for (const int food : foods)
	{
		for (int person = 0; person < NUMBER_OF_PEOPLE; ++person)
		{
			if (ableEatFood[person][food] == true)
			{
				eatFood[person] = true;
			}
		}
	}

	for (bool b : eatFood)
	{
		result &= b;
	}

	return result;
}

int makeFoodPermutation(vector<int> foods, int index)
{
	// 음식 조합을 모두 확인한 경우
	if (index == FOOD_TYPE)
	{
		// 모두 먹을 수 있는 경우
		if (isAbleEverybodyEat(foods)) 
		{
			// 해당 음식 조합 사이즈를 반환
			return foods.size();
		}
		// 누군가 먹지 못하는 음식 조합인 경우
		else
		{
			// 최대값 반환
			return INT_MAX;
		}
	}

	// 조합에 현재 음식이 들어가지 않은 경우 확인
	int removeFoodsResult = makeFoodPermutation(foods, index + 1);
	foods.push_back(index);

	// 조합에 현재 음식이 들어간 경우 확인
	int addFoodsResult = makeFoodPermutation(foods, index + 1);

	// 둘 중 작은 값을 반환
	return min(addFoodsResult, removeFoodsResult);
}