#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<unsigned int> usedNumberCount;
const unsigned int MAXIMUM_NUM = 32000;

void Initailize(int N) {
    usedNumberCount.resize(MAXIMUM_NUM + 2, 9);
    int index = 1;

    for (int i = 1; i * N <= MAXIMUM_NUM; i = (i * 10) + 1)
        usedNumberCount[i * N] = index++;
    
}

int solution(int N, int number) {
    Initailize(N);

    for (unsigned int i = N; i <= MAXIMUM_NUM; ++i) {
        unsigned int nowCount = usedNumberCount[i];

            cout << i << '\n';
        if (nowCount > 8)  continue;

        unsigned int newCount = nowCount + 1;

        for (unsigned int index = 1; index <= MAXIMUM_NUM; index = (index * 10) + 1) {
            if (i + (N * index) <= MAXIMUM_NUM && usedNumberCount[i + (N * index)] > newCount)
                usedNumberCount[i + (N * index)] = newCount;

            if (i * (N * index) <= MAXIMUM_NUM && usedNumberCount[i * (N * index)] > newCount)
                usedNumberCount[i * (N * index)] = newCount;

            if (i / (N * index) > 0 && usedNumberCount[i / (N * index)] > newCount)
                usedNumberCount[i / (N * index)] = newCount;
            
            if (i + index <= MAXIMUM_NUM && usedNumberCount[i + index] > newCount)
                usedNumberCount[i + index] = newCount + 1;
            if (i * index <= MAXIMUM_NUM && usedNumberCount[i * index] > newCount)
                usedNumberCount[i * index] = newCount + 1;

            if (i / index > 0 && usedNumberCount[i / index] > newCount)
                usedNumberCount[i / index] = newCount + 1;

            ++newCount;
        }
    }

    return usedNumberCount[number] > 8 ? -1 : usedNumberCount[number];
}

/*
int solution(int N, int number) {
    Initailize(N);

    for (int i = N; i <= MAXIMUM_NUM; ++i) {
        int nowCount = usedNumberCount[i];
        if (nowCount > 8)  continue;

        int newCount = nowCount + 1;

        for (int index = 1; index <= MAXIMUM_NUM; index = (index * 10) + 1) {
            if (i + (N * index) <= MAXIMUM_NUM)
                usedNumberCount[i + (N * index)] = newCount;
            if (i * (N * index) <= MAXIMUM_NUM)
                usedNumberCount[i * (N * index)] = newCount;

            if (i / (N * index) > 0)
                usedNumberCount[i / (N * index)] = newCount;
            if (i - (N * index) > 0)
                usedNumberCount[i - (N * index)] = newCount;

            if (i + index <= MAXIMUM_NUM)
                usedNumberCount[i + index] = newCount + 1;
            if (i * index <= MAXIMUM_NUM)
                usedNumberCount[i * index] = newCount + 1;

            if (i / index > 0)
                usedNumberCount[i / index] = newCount + 1;
            if (i - index > 0)
                usedNumberCount[i - index] = newCount + 1;

            ++newCount;
        }
    }

    return usedNumberCount[number] > 8 ? -1 : usedNumberCount[number];
}



*/

void main() {
    int N = 5;
    int number = 12;

    for (int i = 1; i <= MAXIMUM_NUM; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cout <<" ( " << i << ", " << j << " ) " << " = " << solution(7, 1) << '\n';
        }
    }
}