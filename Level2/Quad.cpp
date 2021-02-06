#include <string>
#include <vector>

using namespace std;

const bool Verify(const vector<vector<int>>& arr) {
    int lastestNumver = arr[0][0];

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            if (lastestNumver != arr[i][j])
                return false;
        }
    }

    return true;
}

vector<int> DistributeQuad(vector<vector<int>>& arr) {
    vector<int> result = { 0, 0 };
    vector<vector<int>> container(arr.size() / 2);

    if (Verify(arr)) {
        ++result[arr[0][0]];
        return result;
    }

    for (int i = 0; i < 4; ++i) {
        int index = 0;
        container = vector<vector<int>>(arr.size() / 2);

        for (int colum = (arr.size() / 2) * (i / 2); colum < arr.size() / 2 * ((i / 2) + 1); ++colum) {
            for (int row = arr[0].size() / 2 * (i % 2); row < arr[0].size() / 2 * ((i % 2) + 1); ++row) {
                container[index].push_back(arr[colum][row]);
            }
            ++index;
        }

        if (!Verify(container)) {
            vector<int> v = DistributeQuad(container);
            result[0] += v[0];
            result[1] += v[1];
        }
        else {
            ++result[container[0][0]];
        }
    }

    return result;
}

vector<int> solution(vector<vector<int>> arr) {
    return DistributeQuad(arr);
}

#include <iostream>
int main() {
    vector<vector<int>> arr = {
        {1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    vector<int> a = solution(arr);
    cout << a[0] << '\t' << a[1];
}