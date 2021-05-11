/*
호텔에는 방이 총 k개 있으며, 
각각의 방은 1번부터 k번까지 번호로 구분하고 있습니다.
처음에는 모든 방이 비어 있으며 스카피는 다음과 같은 규칙에 따라 고객에게 방을 배정하려고 합니다.

한 번에 한 명씩 신청한 순서대로 방을 배정합니다.
고객은 투숙하기 원하는 방 번호를 제출합니다.
고객이 원하는 방이 비어 있다면 즉시 배정합니다.
고객이 원하는 방이 이미 배정되어 있으면 원하는 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방을 배정합니다.

전체 방 개수 k와 고객들이 원하는 방 번호가 순서대로 들어있는 배열 room_number가 매개변수로 주어질 때, 
각 고객에게 배정되는 방 번호를 순서대로 배열에 담아 return 하도록 solution 함수를 완성해주세요.

[제한사항]
k는 1 이상 10^12 이하인 자연수입니다.
room_number 배열의 크기는 1 이상 200, 000 이하입니다.
room_number 배열 각 원소들의 값은 1 이상 k 이하인 자연수입니다.
room_number 배열은 모든 고객이 방을 배정받을 수 있는 경우만 입력으로 주어집니다.
예를 들어, k = 5, room_number = [5, 5] 와 같은 경우는 방을 배정받지 못하는 고객이 발생하므로 이런 경우는 입력으로 주어지지 않습니다.
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
	// 1. n-> n + 1링크 
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