#include <iostream>

#include "Util.h"

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Union_Find {
public:
	Union_Find() = default;
	Union_Find(const long long start) :
		start_index(start), end_index(start)
	{ }
	long long start_index;
	long long end_index;

	long long Insert(const long long newIndex) {
		++end_index;
		return end_index;
	}

	const bool IsableMerge(const Union_Find& other) const {
		if (other.start_index == end_index + 1) {
			return true;
		}

		if (other.end_index == start_index - 1) {
			return true;
		}

		return false;
	}

	const bool Find(const long long n) const {
		return n >= start_index && n <= end_index;
	}
};

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer(room_number.size());
	int index = 0;
	map<long long, Union_Find> booked_room;

	for (const long long& number : room_number) {
		long long insert_Room_StartIndex = 0;
		auto iter = find_if(booked_room.begin(), booked_room.end(), [&number](map<long long, Union_Find>::value_type const& a) -> bool {
			return a.second.Find(number);
		});

		if (iter == booked_room.end()) {
			booked_room[number] = Union_Find(number);
			answer[index++] = number;
			insert_Room_StartIndex = number;

			iter = prev(booked_room.find(number), 1);
			if (iter != booked_room.end()) {
				if (booked_room[(*iter).first].IsableMerge(booked_room[insert_Room_StartIndex])) {
					booked_room[(*iter).first].end_index = booked_room[insert_Room_StartIndex].end_index;
					booked_room.erase(insert_Room_StartIndex);
					insert_Room_StartIndex = booked_room[(*iter).first].start_index;
				}
			}
		}
		else {
			insert_Room_StartIndex = (*iter).second.start_index;
			answer[index++] = (*iter).second.Insert(number);
		}

		iter = booked_room.upper_bound(insert_Room_StartIndex);
		if (iter != booked_room.end()) {
			if (booked_room[insert_Room_StartIndex].IsableMerge((*iter).second)) {
				booked_room[insert_Room_StartIndex].end_index = (*iter).second.end_index;
				booked_room.erase((*iter).first);
			}
		}
	}
	return answer;
}

int main() {
	long long k = 10;
	vector<long long> room_number = { 1,3,4,1,3,1 };
	cout << solution(k, room_number);
}
