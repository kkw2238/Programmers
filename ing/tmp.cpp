# include <iostream>
# include <time.h>
# include <string>

using namespace std;

int main() {
    int iBaseball[9] = {};

    // 순서대로 값을 대입
    for (int i = 0; i < 9; ++i) {
        iBaseball[i] = i + 1;
    }

    srand((unsigned int)time(0));

    // shuffle
    int tmp, i1, i2;
    for (int i = 0; i < 30; ++i) {
        i1 = rand() % 9;
        i2 = rand() % 9;

        tmp = iBaseball[i1];
        iBaseball[i1] = iBaseball[i2];
        iBaseball[i2] = tmp;
    }

    // choice
    int choice[3] = {};
    for (int i = 0; i < 3; ++i) {
        choice[i] = iBaseball[i];
    }

    int input[3];
    string s = "*   *   *";
    int cnt = 0;

    while (1) {
        // quiz
        cout << s << endl;

        // input
        cin >> input[0] >> input[1] >> input[2];

        // check
        int strike = 0, ball = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j && choice[i] == input[j]) {
                    ++strike;
                    s[i * 4] = choice[i] + '0';
                }
                else if (i != j && choice[i] == input[j]) {
                    ++ball;
                }
            }
        }
        ++cnt;

        if (strike == 0 && ball == 0) {
            cout << "OUT" << endl;
        }
        else if (strike == 3) {
            cout << "★☆정답☆★" << endl;
            cout << "총 " << cnt << "회 걸렸습니다^^" << endl;
            break;
        }
        else {
            cout << strike << "S,  " << ball << "B" << endl;
        }

        cout << "현재 " << cnt << "회 실행" << endl;

    }

}