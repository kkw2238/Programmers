
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    vector<int> maxmimumSticker = sticker;
    vector<int> exceptLastSticker = sticker;

    for (int i = sticker.size() - 1; i >= 0; --i)
    {
        for (int j = 2; j < 4; ++j)
        {
            if ((i - j) < 0)
            {
                break;
            }

            if ((i - j) > 0)
            {
                maxmimumSticker[i - j] = max(maxmimumSticker[i - j], maxmimumSticker[i] + sticker[i - j]);
            }
            if (i < (sticker.size() - 1))
            {
                exceptLastSticker[i - j] = max(exceptLastSticker[i - j], exceptLastSticker[i] + sticker[i - j]);
            }
        }
    }
    
    int result = 0;

    for (int i = 0; i < sticker.size(); ++i)
    {
        result = max({ result, maxmimumSticker[i], exceptLastSticker[i] });
    }

    return result;
}

int main()
{
    int n = solution({ 14, 6 });
    n = n;
}