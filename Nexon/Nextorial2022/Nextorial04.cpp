#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool compare(set<int> a, set<int> b)
{
	return a == b;
}

int findMaxGroupCount(vector<int> arr) {
	vector<int> sortedArray = arr;
	sort(sortedArray.begin(), sortedArray.end());
	set<int> datas;
	set<int> sortedDatas;
	int result = 1;
	for (int i = 0; i < arr.size(); ++i)
	{
		if(datas.empty())
		{
			if (arr[i] == sortedArray[i])
			{
				++result;
			}
			else
			{
				datas.insert(arr[i]);
				sortedDatas.insert(sortedArray[i]);
			}
		}
		else
		{
			if (datas == sortedDatas)
			{
				++result;
				datas.clear();
				sortedDatas.clear();
			}	
			else
			{
				datas.insert(arr[i]);
				sortedDatas.insert(sortedArray[i]);
			}
		}
	}

	return result;
}
