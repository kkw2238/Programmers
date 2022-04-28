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

// ��� ���� �� �ִ� ���� �������� �Ǵ����ִ� �Լ�
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
	// ���� ������ ��� Ȯ���� ���
	if (index == FOOD_TYPE)
	{
		// ��� ���� �� �ִ� ���
		if (isAbleEverybodyEat(foods)) 
		{
			// �ش� ���� ���� ����� ��ȯ
			return foods.size();
		}
		// ������ ���� ���ϴ� ���� ������ ���
		else
		{
			// �ִ밪 ��ȯ
			return INT_MAX;
		}
	}

	// ���տ� ���� ������ ���� ���� ��� Ȯ��
	int removeFoodsResult = makeFoodPermutation(foods, index + 1);
	foods.push_back(index);

	// ���տ� ���� ������ �� ��� Ȯ��
	int addFoodsResult = makeFoodPermutation(foods, index + 1);

	// �� �� ���� ���� ��ȯ
	return min(addFoodsResult, removeFoodsResult);
}