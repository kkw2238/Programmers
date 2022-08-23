#include <vector>

using namespace std;

int binarySearch(const vector<int>& sortedData, int target)
{
	int l = 0;
	int r = sortedData.size();

	// l >= r�� ���� Ž���� ������ ����̱⿡ l < r�� true�� ��츸 �Ǵ�
	while (l < r)
	{
		// �߰� �� ��
		int mid = (l + r) / 2;

		if (sortedData[mid] == target)
		{
			return mid;
		}

		// [mid] ���� target���� ū ��� => ���� ������ Ž��
		if (sortedData[mid] > target)
		{
			r = mid - 1;
		}
		// [mid] ���� target���� ���� ��� => ������ ������ Ž��
		else
		{
			l = mid + 1;
		}
	}

	return -1;
}