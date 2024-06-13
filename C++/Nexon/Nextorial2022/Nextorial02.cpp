#include <iostream>
#include <vector>

using namespace std;

int getStatToDelete(vector<int> stats) {
	const long long MAXIMUM = 1000000001;
	vector<long long> sum_Reverse = vector<long long>(stats.size() + 2, MAXIMUM);
	vector<long long> sum_Front = vector<long long>(stats.size() + 2, MAXIMUM);

	sum_Reverse[0] = 0;
	sum_Reverse[sum_Reverse.size() - 1] = 0;
	sum_Front[0] = 0;
	sum_Front[sum_Front.size() - 1] = 0;

	int result = stats.size() + 1;

	for (int i = 1; i <= stats.size(); ++i)
	{
		int reverse_index = stats.size() - i + 1;

		sum_Front[i] = sum_Front[i - 1] + (i % 2 == 0) ? -stats[i - 1] : stats[i - 1];
		sum_Reverse[reverse_index] = sum_Reverse[reverse_index + 1] + (reverse_index % 2 == 0) ? -stats[reverse_index - 1] : stats[reverse_index - 1];
		
		if (sum_Front[i - 1] == sum_Reverse[i + 1] && sum_Front[i - 1] != MAXIMUM)
		{
			result = min(result, i);
		}
		if (sum_Front[reverse_index - 1] == sum_Reverse[reverse_index + 1] && sum_Front[reverse_index - 1] != MAXIMUM)
		{
			result = min(result, reverse_index);
		}
	}

	if (result == stats.size() + 1)
	{
		return -1;
	}
	return result;
}