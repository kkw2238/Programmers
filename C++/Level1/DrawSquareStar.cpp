/*
    https://programmers.co.kr/learn/courses/30/lessons/12969#qna
*/
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;

    string stars(a, '*');

    for (int i = 0; i < b; ++i)
    {
        cout << stars << '\n';
    }

    return 0;
}