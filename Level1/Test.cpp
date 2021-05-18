/*
    https://programmers.co.kr/learn/courses/30/lessons/42840?language=cpp
*/
#include <string>
#include <vector>

using namespace std;

const int STUDENT_COUNT = 3;

vector<int> solution(vector<int> answers) {
    const vector<vector<int>> student_Answers = { { 1, 2, 3, 4, 5 }, { 2, 1, 2, 3, 2, 4, 2, 5 }, { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }};
    vector<int> answer;
    vector<int> scores(STUDENT_COUNT);
   
    for (int qIndex = 0; qIndex < answers.size(); ++qIndex)
    {
        for (int student_id = 0; student_id < STUDENT_COUNT; ++student_id)
        {
            int convert_QIndex = qIndex % student_Answers[student_id].size();

            if (answers[qIndex] == student_Answers[student_id][convert_QIndex])
            {
                ++scores[student_id];
            }
        }
    }

    int max = 0;

    for (int student_id = 0; student_id < STUDENT_COUNT; ++student_id) {
        max = scores[student_id];
        if (scores[student_id] >= max)
        {
            max = scores[student_id];
            answer.push_back(student_id + 1);
        }
    }

    return answer;
}