#include <vector>

using namespace std;

vector<vector<int>> visitedAspect[2];

const int DIR_X[8]{ -1, 0, 0, 1, -1, -1, 1, 1 };
const int DIR_Y[8]{ 0, 1, -1, 0, -1, 1, -1, 1 };

int width = 0;
int height = 0;

const bool isInsideImage(int x, int y)
{
	return (x >= 0 && x < width) && (y >= 0 && y < height);
}

void FindAspect(const vector<vector<int>>& image, int x, int y, const int visitedIndex, const int findRange)
{
	if (!isInsideImage(x, y) || visitedAspect[visitedIndex][y][x] == 1)
	{
		return;
	}

	visitedAspect[visitedIndex][y][x] = 1;

	for (int i = 0; i < findRange; ++i)
	{
		FindAspect(image, x + DIR_X[i], y + DIR_Y[i], visitedIndex, findRange);
	}
}

vector<int> solution(vector<vector<int>> image)
{
	vector<int> answer(0, 2);

	visitedAspect[0] = vector<vector<int>>(image[0].size(), vector<int>(image.size(), 0));
	visitedAspect[1] = vector<vector<int>>(image[0].size(), vector<int>(image.size(), 0));

	width = image[0].size();
	height = image.size();

	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			if (visitedAspect[0][y][x] == 0)
			{
				FindAspect(image, x, y, 0, 4);
				++answer[0];
			}
			if (visitedAspect[1][y][x] == 0)
			{
				FindAspect(image, x, y, 1, 8);
				++answer[1];
			}
		}
	}

	return answer;
}