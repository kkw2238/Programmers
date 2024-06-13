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
	
	// 유클리드 호재법으로 최대 공약수를 구한다.
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
	// 두 수의 곱 / 최대 공약수 = 최소 공배수
	return (num1 * num2) / GCD;
}

int solution(vector<int> arr) 
{
	int answer = arr.front();
	for (int i = 1; i < arr.size(); ++i)
	{
		// 앞의 두 수에 대한 최소공배수, arr[i]사이의 최소 공배수 = i개의 수에 대한 최소 공배수 
		answer = FindLCM(answer, arr[i]);
	}

	return answer;
}