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

int main()
{
    solution(3, { 1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11, 12 });
}
/*
    당신은 1~n 사이의 수가 적힌 카드가 하나씩 있는 카드 뭉치와 동전 coin개를 이용한 게임을 하려고 합니다. 
    카드 뭉치에서 카드를 뽑는 순서가 정해져 있으며, 게임은 다음과 같이 진행합니다.
    
    처음에 카드 뭉치에서 카드 n/3장을 뽑아 모두 가집니다. (n은 6의 배수입니다.) 
    당신은 카드와 교환 가능한 동전 coin개를 가지고 있습니다.

    각 라운드가 시작할 때 카드를 두 장 뽑습니다. 카드 뭉치에 남은 카드가 없다면 게임을 종료. 
    
    뽑은 카드는 카드 한 장당 동전 하나를 소모해 가지거나, 동전을 소모하지 않고 버릴 수 있습니다.
    카드에 적힌 수의 합이 n+1이 되도록 카드 두 장을 내고 다음 라운드로 진행할 수 있습니다. 만약 카드 두 장을 낼 수 없다면 게임을 종료합니다.
    예를 들어 n = 12, coin = 4이고 [3, 6, 7, 2, 1, 10, 5, 9, 8, 12, 11, 4] 순서대로 카드를 뽑도록 카드 뭉치가 섞여 있습니다.
    
    처음에 3, 6, 7, 2 카드 4장(= n/3)과 동전 4개(= coin)를 가지고 시작합니다. 
    다음 라운드로 진행하기 위해 내야 할 카드 두 장에 적힌 수의 합은 13(= n+1)입니다. 
    다음과 같은 방법으로 최대 5라운드까지 도달할 수 있습니다.
    
    1라운드에서 뽑은 카드 1, 10을 동전 두 개를 소모해서 모두 가집니다. 카드 3, 10을 내고 다음 라운드로 진행합니다. 이때 손에 남은 카드는 1, 2, 6, 7이고 동전이 2개 남습니다.
    2라운드에서 뽑은 카드 5, 9를 동전을 소모하지 않고 모두 버립니다. 카드 6, 7을 내고 다음 라운드로 진행합니다. 이때 손에 남은 카드는 1, 2고 동전이 2개 남습니다.
    3라운드에서 뽑은 카드 8, 12 중 동전 한 개를 소모해서 카드 12를 가집니다. 카드 1, 12을 내고 다음 라운드로 진행합니다. 이때 손에 남은 카드는 2이고 동전이 1개 남습니다.
    4라운드에서 뽑은 카드 11, 4 중 동전 한 개를 소모해서 카드 11을 가집니다. 카드 2, 11을 내고 다음 라운드로 진행합니다. 이때 손에 남은 카드와 동전은 없습니다.
    5라운드에서 카드 뭉치에 남은 카드가 없으므로 게임을 종료합니다.
    처음에 가진 동전수를 나타내는 정수 coin과 카드를 뽑는 순서대로 카드에 적힌 수를 담은 1차원 정수 배열 cards가 매개변수로 주어질 때, 게임에서 도달 가능한 최대 라운드의 수를 return 하도록 solution 함수를 완성해 주세요.

    1. n + 1이 되는 경우의 수는 숫자마다 1번씩 존재 
    2. 그러면 동전을 쓰는 경우 / 안쓰는 경우로 판단
    3. 

    1. 일단 라운드 끝까지 진행( 최대 라운드 탐색 )
    2. 
*/