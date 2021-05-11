#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> kindofGem(gems.begin(), gems.end());
    int length = kindofGem.size();
    while (true) 
    {
        for (int i = 0; i <= gems.size() - length; ++i)
        {
            set<string> shoppingGems(gems.begin() + i, gems.begin() + i + length);
            if (shoppingGems.size() == kindofGem.size())
            {
                return vector<int>{i + 1, i + length};
            }
        }
        ++length;
    }

    return vector<int>{ 1, static_cast<int>(gems.size()) };
}

int main()
{
    vector<string> gems{ "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
    solution(gems);
}
