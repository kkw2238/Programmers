#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct leaf {
	int beginTime;
	int endTime;

	bool AbleMerge(const int otherBeginTime, const int otherEndTime)
	{
		return !(otherEndTime < beginTime || otherBeginTime > endTime);
	}

	void Merge(const int otherBeginTime, const int otherEndTime)
	{
		beginTime = min(otherBeginTime, beginTime);
		endTime = max(otherEndTime, endTime);
	}
};

int solutuin(vector<vector<int>> customer)
{
	int result = 0;

	sort(customer.begin(), customer.end(), [](const vector<int>& a, const vector<int>& b) {
		if (a[0] == b[0])
		{
			return a[0] > b[0];
		}
		return a[0] < b[0];
	});

	leaf memLeaf{ -1 , -1 };
	for (const vector<int>& bookTime : customer)
	{
		if (memLeaf.beginTime == -1 || memLeaf.endTime == -1)
		{
			memLeaf.beginTime = bookTime[0];
			memLeaf.endTime = bookTime[1];
		}
		else
		{
			if (memLeaf.AbleMerge(bookTime[0], bookTime[1]))
			{
				memLeaf.Merge(bookTime[0], bookTime[1]);
			}
			else
			{
				result += memLeaf.endTime - memLeaf.beginTime;

				memLeaf.beginTime = bookTime[0];
				memLeaf.endTime = bookTime[1];
			}
		}

	}

	result += memLeaf.endTime - memLeaf.beginTime;
	return result;
}
