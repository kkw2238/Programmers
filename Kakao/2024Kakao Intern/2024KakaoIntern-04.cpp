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
    ����� 1~n ������ ���� ���� ī�尡 �ϳ��� �ִ� ī�� ��ġ�� ���� coin���� �̿��� ������ �Ϸ��� �մϴ�. 
    ī�� ��ġ���� ī�带 �̴� ������ ������ ������, ������ ������ ���� �����մϴ�.
    
    ó���� ī�� ��ġ���� ī�� n/3���� �̾� ��� �����ϴ�. (n�� 6�� ����Դϴ�.) 
    ����� ī��� ��ȯ ������ ���� coin���� ������ �ֽ��ϴ�.

    �� ���尡 ������ �� ī�带 �� �� �̽��ϴ�. ī�� ��ġ�� ���� ī�尡 ���ٸ� ������ ����. 
    
    ���� ī��� ī�� �� ��� ���� �ϳ��� �Ҹ��� �����ų�, ������ �Ҹ����� �ʰ� ���� �� �ֽ��ϴ�.
    ī�忡 ���� ���� ���� n+1�� �ǵ��� ī�� �� ���� ���� ���� ����� ������ �� �ֽ��ϴ�. ���� ī�� �� ���� �� �� ���ٸ� ������ �����մϴ�.
    ���� ��� n = 12, coin = 4�̰� [3, 6, 7, 2, 1, 10, 5, 9, 8, 12, 11, 4] ������� ī�带 �̵��� ī�� ��ġ�� ���� �ֽ��ϴ�.
    
    ó���� 3, 6, 7, 2 ī�� 4��(= n/3)�� ���� 4��(= coin)�� ������ �����մϴ�. 
    ���� ����� �����ϱ� ���� ���� �� ī�� �� �忡 ���� ���� ���� 13(= n+1)�Դϴ�. 
    ������ ���� ������� �ִ� 5������� ������ �� �ֽ��ϴ�.
    
    1���忡�� ���� ī�� 1, 10�� ���� �� ���� �Ҹ��ؼ� ��� �����ϴ�. ī�� 3, 10�� ���� ���� ����� �����մϴ�. �̶� �տ� ���� ī��� 1, 2, 6, 7�̰� ������ 2�� �����ϴ�.
    2���忡�� ���� ī�� 5, 9�� ������ �Ҹ����� �ʰ� ��� �����ϴ�. ī�� 6, 7�� ���� ���� ����� �����մϴ�. �̶� �տ� ���� ī��� 1, 2�� ������ 2�� �����ϴ�.
    3���忡�� ���� ī�� 8, 12 �� ���� �� ���� �Ҹ��ؼ� ī�� 12�� �����ϴ�. ī�� 1, 12�� ���� ���� ����� �����մϴ�. �̶� �տ� ���� ī��� 2�̰� ������ 1�� �����ϴ�.
    4���忡�� ���� ī�� 11, 4 �� ���� �� ���� �Ҹ��ؼ� ī�� 11�� �����ϴ�. ī�� 2, 11�� ���� ���� ����� �����մϴ�. �̶� �տ� ���� ī��� ������ �����ϴ�.
    5���忡�� ī�� ��ġ�� ���� ī�尡 �����Ƿ� ������ �����մϴ�.
    ó���� ���� �������� ��Ÿ���� ���� coin�� ī�带 �̴� ������� ī�忡 ���� ���� ���� 1���� ���� �迭 cards�� �Ű������� �־��� ��, ���ӿ��� ���� ������ �ִ� ������ ���� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

    1. n + 1�� �Ǵ� ����� ���� ���ڸ��� 1���� ���� 
    2. �׷��� ������ ���� ��� / �Ⱦ��� ���� �Ǵ�
    3. 

    1. �ϴ� ���� ������ ����( �ִ� ���� Ž�� )
    2. 
*/