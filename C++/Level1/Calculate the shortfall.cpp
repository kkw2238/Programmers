/*
	https://programmers.co.kr/learn/courses/30/lessons/82612?language=cpp
*/

long long solution(int price, int money, int count)
{
	long long needMoney = count * ((long long)price + (long long)price * count) / 2;
	long long finallyMoney = money - needMoney;
	
	if (finallyMoney < 0)
	{
		return -finallyMoney;
	}

    return 0;
}