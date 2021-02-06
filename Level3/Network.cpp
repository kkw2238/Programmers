#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    const int ALREADY_VISITED = 1, CONNECT = 1;
    int answer = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; ++i) {
        if (visited[i] == ALREADY_VISITED) 
            continue;

        queue<int> computerQueue;
        computerQueue.push(i);

        while (!computerQueue.empty()) {
            int computerIndex = computerQueue.front();
            computerQueue.pop();

            visited[computerIndex] = ALREADY_VISITED;

            for (int j = 0; j < n; ++j) {
                if (visited[j] != ALREADY_VISITED && computers[computerIndex][j] == CONNECT)
                    computerQueue.push(j);
            }
        }
        ++answer;
    }

    return answer;
}


#include <iostream>
int main() {
    int n = 3;
    vector<vector<int>> computers = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };

    cout << solution(n, computers);
}