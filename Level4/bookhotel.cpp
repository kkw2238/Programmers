/*
ȣ�ڿ��� ���� �� k�� ������, 
������ ���� 1������ k������ ��ȣ�� �����ϰ� �ֽ��ϴ�.
ó������ ��� ���� ��� ������ ��ī�Ǵ� ������ ���� ��Ģ�� ���� ������ ���� �����Ϸ��� �մϴ�.

�� ���� �� �� ��û�� ������� ���� �����մϴ�.
���� �����ϱ� ���ϴ� �� ��ȣ�� �����մϴ�.
���� ���ϴ� ���� ��� �ִٸ� ��� �����մϴ�.
���� ���ϴ� ���� �̹� �����Ǿ� ������ ���ϴ� �溸�� ��ȣ�� ũ�鼭 ����ִ� �� �� ���� ��ȣ�� ���� ���� �����մϴ�.

��ü �� ���� k�� ������ ���ϴ� �� ��ȣ�� ������� ����ִ� �迭 room_number�� �Ű������� �־��� ��, 
�� ������ �����Ǵ� �� ��ȣ�� ������� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

[���ѻ���]
k�� 1 �̻� 10^12 ������ �ڿ����Դϴ�.
room_number �迭�� ũ��� 1 �̻� 200, 000 �����Դϴ�.
room_number �迭 �� ���ҵ��� ���� 1 �̻� k ������ �ڿ����Դϴ�.
room_number �迭�� ��� ���� ���� �������� �� �ִ� ��츸 �Է����� �־����ϴ�.
���� ���, k = 5, room_number = [5, 5] �� ���� ���� ���� �������� ���ϴ� ���� �߻��ϹǷ� �̷� ���� �Է����� �־����� �ʽ��ϴ�.
*/


#include <vector>
using namespace std;

/*
  1,000,000,000,000
*/

#include <iostream>
#include <map>

long long Find_Vacancies(long long k, map<long long, long long>& booked_room)
{
	if (booked_room[k] == 0)
	{
		return k;
	}
	else
	{
		long long result = Find_Vacancies(booked_room[k], booked_room);
		booked_room[k] = result;
		return result;
	}
}

vector<long long> solution(long long k, vector<long long> room_numbers)
{
	map<long long, long long> booked_room;
	vector<long long> result;
	// 1. n-> n + 1��ũ 
	for (const long long room_number : room_numbers)
	{
		long long vacancies = 0;
		if (booked_room[room_number] == 0)
		{
			vacancies = room_number;
			booked_room[vacancies] = room_number + 1;
			result.push_back(room_number);
		}
		else
		{
			vacancies = Find_Vacancies(room_number, booked_room);
			booked_room[vacancies] = vacancies + 1;
			result.push_back(vacancies);
		}
	}

	return result;
}

int main()
{
	long long k = 10;
	vector<long long> room_number{ 1, 3, 2, 1, 3, 1 };

	solution(k, room_number);
}