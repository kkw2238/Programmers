#include <string>
#include <vector>

using namespace std;

int Distance(int number, int hand) {
    if (hand % 3 == 0)
        hand -= 2;

    int dist = hand - number > 0 ? hand - number : -(hand - number);

    int y = dist / 3;
    int x = dist % 3;
    return x + y;
}

const char Find_MidLineTouchHand(int number, int& leftTumb, int& rightTumb, string hand) {
    int DL = Distance(number, leftTumb);
    int DR = Distance(number, rightTumb);

    if (DL > DR) {
        rightTumb = number;
        return 'R';
    }
    else if (DL < DR) {
        leftTumb = number;
        return 'L';
    }
    else if(hand[0] == 'l') {
        leftTumb = number;
        return 'L';
    }
    rightTumb = number;
    return 'R';
}

string solution(vector<int> numbers, string hand) {
    const char Left = 'L', Right = 'R';
    string answer = "";
    int leftTumb = 10, rightTumb = 12;

    for (int number : numbers) {
        if (number == 0)        number = 11;
        if (number % 3 == 0) {
            answer += Right;
            rightTumb = number;
        }
        else if (number % 3 == 1) {
            answer += Left;
            leftTumb = number;
        }
        else answer += Find_MidLineTouchHand(number, leftTumb, rightTumb, hand);
    }

    return answer;
}



int main() {
    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "right";

    cout << solution(numbers, hand);
}