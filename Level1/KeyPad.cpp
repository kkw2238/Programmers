/* https://programmers.co.kr/learn/courses/30/lessons/67256 */

#include <string>
#include <vector>

using namespace std;

int LHAND = 10, RHAND = 12;

const vector<int> KEYPAD{ 11, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int Distance(int now, int dest) {
    int result = 0;

    if (now % 3 == 1) {
        now += 1;
        result += 1;
    }
    else if (now % 3 == 0) {
        now -= 1;
        result += 1;
    }

    int step = dest > now ? dest - now : now - dest;
    return result + step / 3;
}

char FindNearlyHand(int dest, string hand) {
    int lHandDistance = Distance(LHAND, dest);
    int rHandDistance = Distance(RHAND, dest);

    if (lHandDistance == rHandDistance) return hand[0] + ('A' - 'a');
    else return lHandDistance < rHandDistance ? 'L' : 'R';
}
 
string solution(vector<int> numbers, string hand) {
    string answer = "";

    for (int number : numbers) {
        if (number == 0 || number % 3 == 2) {
            answer.push_back(FindNearlyHand(KEYPAD[number], hand));

            if (answer.back() == 'L') 
                LHAND = KEYPAD[number];
            else 
                RHAND = KEYPAD[number];
        }
        else if (number % 3 == 1) {
            answer.push_back('L');
            LHAND = number;
        }
        else {
            answer.push_back('R');
            RHAND = number;
        }
    }

    return answer;
}

int main() {
    solution(vector<int>{1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
}