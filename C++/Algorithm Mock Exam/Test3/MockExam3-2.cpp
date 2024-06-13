#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int count = 0;

    if (ingredient[0] == 1)
    {
        count = 1;
    }

    for (int i = 1; i < ingredient.size(); ++i)
    {
        if (count > 0 && ingredient[i - 1] == ((ingredient[i] + 1) % 3 + 1))
        {
            ++count;
        }
        else if (ingredient[i] == 1)
        {
            count = 1;
        }
        else
        {
            count = 0;
        }

        if (count == 4)
        {
            ingredient.erase(ingredient.begin() + i - 3, ingredient.begin() + i + 1);
            i = max(i - 7, -1);
            ++answer;
            count = 0;
        }
    }

    return answer;
}