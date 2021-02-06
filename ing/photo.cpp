
#include <string>
#include <map>
#include <vector>

using namespace std;

enum Type { Within = '<', Equal = '=', Without = '>' };

struct dataInfo {
    char name;
    char type;
    int distance;
};

map<char, vector<dataInfo>> DistributeData(vector<string> data) {
    map<char, vector<dataInfo>> result;
    for (string s : data) {
        result[s[0]].push_back({ s[2], s[3], s[4] - '0' + 1 });
    }
    return result;
}

const bool InDistance(const dataInfo d, const const int a, const int b) {
    switch (d.type) {
    case Within:
        return a > b ? a - b < d.distance : b - a < d.distance;
    case Equal:
        return a > b ? a - b == d.distance : b - a == d.distance;
    case Without:
        return a > b ? a - b > d.distance : b - a > d.distance;
    }
    return false;
}

vector<string> SeatDown(char name, string seat, dataInfo d) {
    int index = seat.find(name);
    string tmpSeat = seat;
    vector<string> result;

    if (index != -1 && !InDistance(d, index, seat.find(d.name))) {
        return vector<string>();
    }
    index = 0;

    while (true) {
        index = seat.find('X', index);
        if (index == -1) break;
        tmpSeat[index] = name;

        for (int i = 0; i < seat.length(); ++i) {
            if (InDistance(d, index, i) && seat[i] == 'X') {
                tmpSeat[i] = d.name;
                result.push_back(tmpSeat);
                tmpSeat[i] = 'X';
            }
        }

        tmpSeat = seat;
        ++index;
    }

    return result;
}

vector<string> MakeDataSet(char name, dataInfo d, vector<string>& enabledSeat) {
    if (enabledSeat.size() == 0) {
        enabledSeat.push_back(string(8, 'X'));
    }

    for (string s : enabledSeat) {
        return SeatDown(name, s, d);
    }

}

int Factorial(int x) {
    int result = 1;
    for (int i = 2; i <= x; ++i) {
        result *= i;
    }

    return result;
}

#include "Util.h"
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<string> enabledSeat;
    map<char, vector<dataInfo>> distributedData = DistributeData(data);

    for (pair<char, vector<dataInfo>> d : distributedData) {
        for (dataInfo info : d.second) {
            enabledSeat = MakeDataSet(d.first, info, enabledSeat);
        }
    }

    cout << enabledSeat;

    for (string s : enabledSeat) {
        answer += Factorial(count(s.begin(), s.end(), 'X')) * 2;
    }

    return answer * pow(2, data.size());
}


#include <iostream>

int main() {
    int n = 2;
    vector<string> data = { "N~F=0", "R~T>2" };
    cout << solution(n, data);
}