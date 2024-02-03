/*
	https://school.programmers.co.kr/learn/courses/30/lessons/258707
*/

#include <vector>
#include <map>

using namespace std;

int insert(map<int, int>& remainCard, int n, int card)
{
    if (remainCard.find(n + 1 - card) == remainCard.end())
    {
        ++remainCard[card];
        return 0;
    }

    remainCard.erase(n + 1 - card);
    return 1;
}

int distribute(map<int, int>& remainCard, vector<int>& cards, int n)
{
    int pairCount = 0;

    for (int i = 0; i < n / 3; ++i)
    {
        pairCount += insert(remainCard, n, cards[i]);
    }

    return pairCount;
}

int play(int n, int coin, int pairCount, vector<int>& cards, map<int, int>& remainCard)
{
    map<int, int> pocket;
    int round = 1, additional = 0;

    for (int i = cards.size() / 3; i < cards.size(); i += 2)
    {
        for (int j = i; j <= i + 1; ++j)
        {
            if (remainCard.find(n + 1 - cards[j]) == remainCard.end())
            {
                additional += insert(pocket, n, cards[j]);
            }
            else if (coin > 0)
            {
                --coin;
                remainCard.erase(n + 1 - cards[j]);
                ++pairCount;
            }
        }

        if (pairCount == 0)
        {
            if (coin >= 2 && additional > 0)
            {
                coin -= 2;
                ++pairCount;
                --additional;
            }
            else
            {
                break;
            }
        }

        ++round;
        --pairCount;
    }

    return round;
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    map<int, int> remainCard;

    int pairCount = distribute(remainCard, cards, cards.size());
    answer = play(cards.size(), coin, pairCount, cards, remainCard);

    return answer;
}