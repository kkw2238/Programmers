#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> rightToppingCount;
    map<int, int> leftToppingCount;

    for (int toppingTypee : topping)
    {
        ++rightToppingCount[toppingTypee];
    }

    for (int i = 0; i < topping.size(); ++i)
    {
        int nowTopping = topping[i];

        ++leftToppingCount[nowTopping];
        --rightToppingCount[nowTopping];

        if (rightToppingCount[nowTopping] == 0)
        {
            rightToppingCount.erase(nowTopping);
        }
        
        if (rightToppingCount.size() == leftToppingCount.size())
        {
            ++answer;
        }
    }

    return answer;
}