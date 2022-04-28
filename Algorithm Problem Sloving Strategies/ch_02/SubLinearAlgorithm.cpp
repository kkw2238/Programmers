#include <vector>

using namespace std;

int binarySearch(const vector<int>& sortedData, int target)
{
	int l = 0;
	int r = sortedData.size();

	// l >= r인 경우는 탐색에 실패한 경우이기에 l < r이 true인 경우만 판단
	while (l < r)
	{
		// 중간 값 비교
		int mid = (l + r) / 2;

		if (sortedData[mid] == target)
		{
			return mid;
		}

		// [mid] 값이 target보다 큰 경우 => 왼쪽 영역을 탐색
		if (sortedData[mid] > target)
		{
			r = mid - 1;
		}
		// [mid] 값이 target보다 작은 경우 => 오른쪽 영역을 탐색
		else
		{
			l = mid + 1;
		}
	}

	return -1;
}