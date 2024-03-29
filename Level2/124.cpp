#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    const int NOTATION_LENGTH = 3;
    const char notation[NOTATION_LENGTH] = { '4', '1', '2' };
    string answer = "";

    while (n > NOTATION_LENGTH) {
        answer = notation[n % NOTATION_LENGTH] + answer;
        n /= NOTATION_LENGTH;
    }

    answer = notation[n % NOTATION_LENGTH] + answer;
    return answer;
}