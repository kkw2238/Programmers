#include <iostream>

using namespace std;

/*
 * Complete the 'maxNewWeapons' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER oldWeapons
 *  2. INTEGER golds
 *  3. INTEGER sellingPrice
 *  4. INTEGER repairCost
 */

int maxNewWeapons(int oldWeapons, int golds, int sellingPrice, int repairCost) {
	int result = 0;
	int l = 0, r = oldWeapons;
	int mid = (l + r) / 2;
	unsigned long long tmpGold = golds;

	while (l <= r)
	{
		mid = (l + r) / 2;
		int sellWeapons = oldWeapons - mid;

		if (sellWeapons < 0)
		{
			break;
		}
		
		tmpGold = golds + (unsigned long long)sellingPrice * sellWeapons;
	
		if (tmpGold < (unsigned long long)repairCost * mid)
		{
			r = mid - 1;
		}
		else
		{
			if (result < mid)
			{
				result = mid;
				l = mid + 1;
			}
		}
	}

	return result;
}