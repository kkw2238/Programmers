/*
    https://school.programmers.co.kr/learn/courses/30/lessons/340210?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

vector<string> distributeExpression(string expression, vector<bool>& ableDigit) {
    vector<string> result; 
    int index = expression.find(' ');
    int before = 0;
    int maximumNum = 0;

    while (index > 0) {
        string value = expression.substr(before, index - before);
        result.push_back(value);

        if (isdigit(value[0])) {
            for (char c : value) {
                maximumNum = max(maximumNum, c - '0');
            }
        }

        before = index + 1;
        index = expression.find(' ', index + 1);
    }
    
    for (int i = 0; i < maximumNum; ++i) {
        ableDigit[i] = false;
    }

    return result;
}

int change10digit(string str, int nowDigit) {
    int result = 0;
    int digit = 1;

    for (int i = str.length() - 1; i >= 0; ++i) {
        result += str[i] * digit;
        digit *= nowDigit;
    }

    return result;
}

int changeOtherDigit(int num, int convertDigit) {
    int pos = 1;
    int result = 0;

    while (num > 0) {
        result += (num % convertDigit) * pos;
        num /= convertDigit;
        pos *= 10;
    }

    return result;
}

int calculate(vector<string>& expression, int digit) {
    int num1 = change10digit(expression[0], digit);
    int num2 = change10digit(expression[1], digit);

    if (expression[1][0] == '+') {
        return (num1 + num2);
    }
    else {
        return (num1 - num2);
    }

}

bool checkAbleDigit(vector<string>& expression, int digit) {
    return change10digit(expression[2], digit) == calculate(expression, digit);
}

void checkCorrectExpression(vector<string>& expression, vector<bool>& ableDigit) {
    for (int i = 9; i >= 2; --i) {
        if (ableDigit[i]) {
            ableDigit[i] = checkAbleDigit(expression, i);
        }
    }
}

string getAnswer(vector<string>& question, vector<bool>& isAbledigit) {
    int result = -1;
    for (int i = 9; i >= 2; --i) {
        if (isAbledigit[i]) {
            int num3 = change10digit(question[0], i);
            num3 = changeOtherDigit(num3, i);

            if (result == -1) {
                result = num3;
            }
            else if(result != num3) {
                return "?";
            }
        }
    }
    if (result == -1) {
        return "?";
    }

    return to_string(result);
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<bool> ableDigit(10, true);
    vector<vector<string>> distributedExpression;
    vector<vector<string>> distributedQuestion;

    for (string expression : expressions) {
        vector<string> distribute = distributeExpression(expression, ableDigit);

        if (distribute.back() == "X") {
            distributedQuestion.push_back(distribute);
        }
        else {
            distributedExpression.push_back(expressions);
        }
    }

    for (vector<string>& expression : distributedExpression) {
        checkCorrectExpression(expression, ableDigit);
    }

    for (vector<string>& question : distributedQuestion) {
        string num3 = getAnswer(question, ableDigit);

        answer.push_back(question[0] + " " + question[1] + " " + question[2] + " " + question[3] + " " + num3);
    }
    

    return answer;
}

int main() {
    solution({ "14 + 3 = 17", "13 - 6 = X", "51 - 5 = 44" });
}