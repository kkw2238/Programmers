/*
	https://school.programmers.co.kr/learn/courses/30/lessons/250121
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<char, int> index{ {'c', 0} , {'d', 1}, {'m', 2}, {'r', 3} };

    for (vector<int>& d : data)
    {
        if (d[index[ext[0]]] < val_ext)
        {
            answer.push_back(d);
        }
    }

    sort(answer.begin(), answer.end(), [&sort_by, &index](vector<int>& a, vector<int>& b)
        {
            return a[index[sort_by[0]]] > b[index[sort_by[1]]];
        });

    return answer;
}