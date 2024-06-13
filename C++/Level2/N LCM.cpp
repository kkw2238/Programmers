/*
	https://programmers.co.kr/learn/courses/30/lessons/12953
*/

#include <vector>
#include <algorithm>

using namespace std;

int FindGCD(int num1, int num2)
{
	int min_Num = min(num1, num2);
	int max_Num = max(num1, num2);
	
	// ��Ŭ���� ȣ������� �ִ� ������� ���Ѵ�.
	while (max_Num % min_Num != 0)
	{
		max_Num = max_Num % min_Num;
		swap(max_Num, min_Num);
	}

	return min_Num;
}

int FindLCM(int num1, int num2) 
{
	int GCD = FindGCD(num1, num2);
	// �� ���� �� / �ִ� ����� = �ּ� �����
	return (num1 * num2) / GCD;
}

int solution(vector<int> arr) 
{
	int answer = arr.front();
	for (int i = 1; i < arr.size(); ++i)
	{
		// ���� �� ���� ���� �ּҰ����, arr[i]������ �ּ� ����� = i���� ���� ���� �ּ� ����� 
		answer = FindLCM(answer, arr[i]);
	}

	return answer;
}