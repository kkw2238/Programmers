#include <vector>

using namespace std;

int FindLCM(int num1, int num2) {
	int largest = num1 > num2 ? num1 : num2;
	int smallest = largest == num1 ? num2 : num1;

	for (int i = largest; i <= largest * smallest; i += largest) {
		if (i % smallest == 0)
			return i;
	}

	return num1 * num2;
}

int solution(vector<int> arr) {
	int answer = FindLCM(arr[0], arr[1]);
	for (int i = 2; i < arr.size(); ++i) {
		answer = FindLCM(answer, arr[i]);
	}
	return answer;
}
