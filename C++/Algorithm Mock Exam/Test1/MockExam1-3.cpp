#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    stack<int> subContainer;

    int boxIndex = 0;
    int orderIndex = 0;

    while(true)
    {
        if (orderIndex == order.size())
        {
            break;
        }

        if (!subContainer.empty() && subContainer.top() == order[orderIndex])
        {
            subContainer.pop();
            ++orderIndex;
            continue;
        }

        if (boxIndex < order.size())
        {
            if (boxIndex != order[orderIndex])
            {
                subContainer.push(boxIndex++);
            }
            else
            {
                ++orderIndex;
            }
        }
        else
        {
            break;
        }

    }

    return orderIndex;
}