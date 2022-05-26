//#include <string>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//vector<int> solution(vector<string> gems) {
//    set<string> kindofGem(gems.begin(), gems.end());
//    int length = kindofGem.size();
//    while (true) 
//    {
//        for (int i = 0; i <= gems.size() - length; ++i)
//        {
//            set<string> shoppingGems(gems.begin() + i, gems.begin() + i + length);
//            if (shoppingGems.size() == kindofGem.size())
//            {
//                return vector<int>{i + 1, i + length};
//            }
//        }
//        ++length;
//    }
//
//    return vector<int>{ 1, static_cast<int>(gems.size()) };
//}

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int leftIndex = 0;
int rightIndex = 0;
int maximum = 100001;

int findSide(vector<string>& gems, int left, int right, set<string>& typeOfgems)
{
    set<string> typeOfInsideGems = set<string>(gems.begin() + left, gems.begin() + right);

    int range = right - left;
    int mid = (left + right) / 2;

    if (typeOfInsideGems.size() != typeOfgems.size() || range < typeOfgems.size())
    {
        return 100001;
    }

    vector<int> leftSide{ mid + 1, left, left + ((mid - left) / 2), left };
    vector<int> rightSide{ right, mid - 1, right, mid + ((right - mid) / 2) };

    for (int i = 3; i >= 0; --i)
    {
        range = min(findSide(gems, leftSide[i], rightSide[i], typeOfgems), range);

        if (range < maximum)
        {
            maximum = range;
            leftIndex = leftSide[i];
            rightIndex = rightSide[i];
        }
    }
    
    return range;
}


vector<int> solution(vector<string> gems) {
    set<string> typeOfGems(gems.begin(), gems.end());

    findSide(gems, 0, gems.size(), typeOfGems);

    return vector<int>{leftIndex + 1, rightIndex + 1};
}



int main()
{
    vector<string> gems{ "XYZ", "XYZ", "XYZ" };
    solution(gems);
}
