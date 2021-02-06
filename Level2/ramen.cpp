/*
	https://programmers.co.kr/learn/courses/30/lessons/42629
*/
/*
	��� ���忡���� �Ϸ翡 �а��縦 1�澿 ����մϴ�.
	���� �а��縦 ���޹޴� ������ �������� ������ k�� ���Ŀ��� �а��縦 ���޹��� �� �ֱ� ������ �ؿ� ���忡�� �а��縦 �����ؾ� �մϴ�.

	�ؿ� ���忡���� ���� �а��縦 ������ �� �ִ� ��¥�� ������ �˷��־���, ��� ���忡���� ��ۺ� ���̱� ���� �ּ����� Ƚ���� �а��縦 ���޹ް� �ͽ��ϴ�.

	���� ���忡 �����ִ� �а��� ���� stock, �а��� ���� ����(dates)�� �ش� ������ ���� ������ �а��� ����(supplies),
	���� �������κ��� ���޹��� �� �ִ� ���� k�� �־��� ��,
	�а��簡 �������� �ʰ� ������ ��ϱ� ���ؼ� �ּ��� �� �� �ؿ� �������κ��� �а��縦 ���޹޾ƾ� �ϴ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

	dates[i]���� i��° ���� �������� ���������, supplies[i]���� dates[i] ��¥�� ���� ������ �а��� ������ ��� �ֽ��ϴ�.

	���ѻ���
		stock�� �ִ� �а���� ����(0�� ����)���� ���˴ϴ�.
		stock�� k�� 2 �̻� 100,000 �����Դϴ�.
		dates�� �� ���Ҵ� 1 �̻� k �����Դϴ�.
		supplies�� �� ���Ҵ� 1 �̻� 1,000 �����Դϴ�.
		dates�� supplies�� ���̴� 1 �̻� 20,000 �����Դϴ�.
		k�� °���� �а��簡 ����� ���޵Ǳ� ������ k-1�Ͽ� ����� ���������� Ȯ���ϸ� �˴ϴ�.
		dates�� ����ִ� ��¥�� �������� ���ĵǾ� �ֽ��ϴ�.
		dates�� ����ִ� ��¥�� ���޵Ǵ� �а���� �۾� ���� �� ������ ���޵Ǵ� ���� �������� �մϴ�.
			���� ��� 9��°�� �а��簡 �ٴڳ�����, 10��°�� ���޹����� 10��°���� ������ ��� �� �ֽ��ϴ�.
			�а��簡 �ٴڳ��� ���� �־����� �ʽ��ϴ�.
*/

#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	priority_queue<int, vector<int>, less<int>> pq;
	int nowStock = stock, answer = 0, i = 0;

	while (nowStock < k) {
		for (i; i < dates.size(); ++i) {
			if (nowStock - dates[i] < 0) break;
			pq.push(supplies[i]);
		}

		nowStock += pq.top();
		pq.pop();
		++answer;
	}
	return answer;
}

#include <iostream>
int main() {
	int stock = 4;
	vector<int> dates = { 4,10,15 };
	vector<int> supplies = { 20,5,10 };
	int k = 30;

	cout << solution(stock, dates, supplies, k);
}