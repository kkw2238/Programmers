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

int leftIndex = 100001;
int rightIndex = 0;
int maximum = 100001;

int findSide(vector<string>& gems, int left, int right, set<string>& typeOfgems)
{
    if (left > right)
    {
        return 100001;
    }
    set<string> typeOfInsideGems = set<string>(gems.begin() + left, gems.begin() + right);

    int range = right - left;
    int mid = (left + right) / 2;

    if (typeOfInsideGems.size() != typeOfgems.size() || range < typeOfgems.size())
    {
        return 100001;
    }

    vector<int> leftSide{ mid + 1   , left      , left + ((mid - left) / 2) };
    vector<int> rightSide{ right    , mid - 1   , mid + ((right - mid) / 2) };

    for (int i = 2; i >= 0; --i)
    {
        range = min(findSide(gems, leftSide[i], rightSide[i], typeOfgems), range);

        if ((range <= maximum) && (leftSide[i] < leftIndex))
        {
            maximum = range;
            leftIndex = leftSide[i];
            rightIndex = rightSide[i];
        }
    }
    
    return range;
}



//
//vector<int> solution(vector<string> gems) {
//    set<string> typeOfGems(gems.begin(), gems.end());
//
//    findSide(gems, 0, gems.size(), typeOfGems);
//
//    return vector<int>{leftIndex + 1, rightIndex + 1};
//}
//

#include <string>
#include <vector>
#include <map>

map<string, int> gemNumber;

int buy(vector<int>& backet, string& gemType)
{
    int gemIndex = gemNumber[gemType];
    int result = 0;

    if (backet[gemIndex] == 0)
    {
        result = -gemIndex;
    }

    ++backet[gemIndex];
    return result;
}

int refund(vector<int>& backet, string& gemType)
{
    int gemIndex = gemNumber[gemType];
    int result = 0;

    --backet[gemIndex];
    if (backet[gemIndex] == 0)
    {
        result = gemIndex;
    }
    return result;
}

int initialize(const vector<string>& gems)
{
    int count = 0;

    for (const string& gem : gems)
    {
        if (gemNumber[gem] == 0)
        {
            gemNumber[gem] = ++count;
        }
    }

    return count;
}

vector<int> solution(vector<string> gems) {
    
    vector<int> result = { 0, 0 };
    int count = initialize(gems);
    vector<int> backet(count + 1, 0);
    vector<bool> isFind(gems.size(), false);
    int memStartIndex = 0;
    int sum = (count + 1) * count / 2;
    int length = 100001;

    for (int memEndIndex = 0; memEndIndex < gems.size();)
    {
        if (isFind[memEndIndex] == false)
        {
            isFind[memEndIndex] = true;

            sum += buy(backet, gems[memEndIndex]);
        }

        if (sum > 0)
        {
            ++memEndIndex;
        }
        else
        {
            int memLength = memEndIndex - memStartIndex;
            if (memLength < length)
            {
                length = memLength;

                result[1] = memEndIndex + 1;
                result[0] = memStartIndex + 1;
            }

            sum += refund(backet, gems[memStartIndex]);
            ++memStartIndex;
        }
    }

    return result;
}

int main()
{
    vector<string> gems{ "A","B","B","B","B","B","B","C","B","A" };
    solution(gems);
}
