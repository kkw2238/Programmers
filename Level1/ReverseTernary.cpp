#include <string>
#include <vector>

using namespace std;

string TransformTernary(int n) {
    string result = "";
    const char NUMBER[3] = { '0', '1', '2' };

    while (n > 0) {
        result += NUMBER[n % 3];
        n /= 3;
    }

    return result;
}

int TransformDemical(string& s) {
    int result = 0, digit = 1;
    const int NUMBER_CHARACTER = '0';

    for (int i = s.length() - 1; i > 0; --i) {
        result += (s[i] - NUMBER_CHARACTER) * digit;
        digit *= 3;
    }

    return result;
}

int solution(int n) {
    string convertedTernary = TransformTernary(n);
    return TransformDemical(convertedTernary);
}
