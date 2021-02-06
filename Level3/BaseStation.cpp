/*
    https://programmers.co.kr/learn/courses/30/lessons/12979
*/

#include <iostream>
#include <vector>
using namespace std;

const int StartPos(const int pos, const int w) {
    int start = pos - w;
    return start < 0 ? 0 : start;
}

const int EndPos(const int pos, const int w, const int maximum) {
    int end = pos + w;
    return end < maximum ? end : maximum;
}

void BuildStation(const int n, vector<bool>& waveReach, const int pos, const int w) {
    for (int i = StartPos(pos, w); i < EndPos(pos, w, n); ++i) {
        waveReach[i] = true;
    }
}

bool IsEnableBuild(int pos, int w, vector<bool>& waveReach) {
    int rightEnd = EndPos(pos, w, waveReach.size());

    if (!waveReach[pos - w] || !waveReach[rightEnd]) return true;
    if (!waveReach[((pos - w) + pos) / 2] || !waveReach[((rightEnd) + pos) / 2]) return true;
    if (!waveReach[pos - 1] || !waveReach[pos + 1]) return true;
    return !waveReach[pos];
}

int solution(int n, vector<int> stations, int w)
{
    int result = 0;
    vector<bool> waveReach(n);

    for (int station : stations) {
        BuildStation(n, waveReach, station, w);
    }

    for (int i = w; i < n - w - 1; i += w * 2 + 1) {
        if (IsEnableBuild(i, w, waveReach)) {
            BuildStation(n, waveReach, i, w);
            ++result;
        }
    }

    return result;
}

#include <iostream>
int main() {
    int n = 16;
    vector<int> stations = { 9 };
    int w = 2;

    cout << solution(n, stations, w);
}