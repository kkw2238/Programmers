#include <string>
#include <vector>
#include <queue>
using namespace std;

template<typename T>
void ClearQueue(T& q) {
    while (!q.empty()) {
        q.pop();
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);

    priority_queue<int> biggest_queue;
    priority_queue<int, vector<int>, greater<int>>smallest_queue;

    int biggoffset = 0, smalloffset = 0;

    for(string& operation : operations) {
        if (operation[0] == 'I') {
            int num = stoi(string(operation.begin() + 2, operation.end()));
            smallest_queue.push(num);
            biggest_queue.push(num);
        }
        else {
            if (operation[2] == '-' && biggoffset < smallest_queue.size()) {
                smallest_queue.pop();
                ++smalloffset;
                if (smallest_queue.size() == biggoffset) {
                    ClearQueue(smallest_queue);
                    biggoffset = 0;
                }
            }
            else if(operation[2] != '-' && smalloffset < biggest_queue.size()) {
                biggest_queue.pop();
                ++biggoffset;
                if (biggest_queue.size() == smalloffset) {
                    ClearQueue(biggest_queue);
                    smalloffset = 0;
                }
            }
        }
    }

    answer[0] = biggest_queue.size() - smalloffset <= 0 ? 0 : biggest_queue.top();
    answer[1] = smallest_queue.size() - biggoffset <= 0 ? 0 : smallest_queue.top();

    return answer;
}

int main() {
    vector<string> operations = { "I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6" };

    solution(operations);
}