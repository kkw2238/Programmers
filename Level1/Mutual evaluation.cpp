/*
	https://programmers.co.kr/learn/courses/30/lessons/83201?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

const char GetGrade(const double score)
{
    if (score >= 90.0)
    {
        return 'A';
    }
    else if (score >= 80.0)
    {
        return 'B';
    }
    else if (score >= 70.0)
    {
        return 'C';
    }
    else if (score >= 50.0)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

string solution(vector<vector<int>> scores) {
    const int student_Count = scores.size();
    string answer = "";

    for (int x = 0; x < student_Count; ++x)
    {
        bool has_same_biggestScore = false;
        bool has_same_smallestScore = false;

        int sum_of_scores = 0;

        int smallest_score = 100;
        int biggest_score = 0;

        for (int y = 0; y < student_Count; ++y)
        {
            sum_of_scores += scores[y][x];
            
            if (scores[y][x] < smallest_score)
            {
                has_same_smallestScore = false;
                smallest_score = scores[y][x];
            }
            else if (scores[y][x] == smallest_score)
            {
                has_same_smallestScore = true;
            }
        }

        if (scores[y][x] > biggest_score)
        {
            has_same_biggestScore = false;
            biggest_score = scores[y][x];
        }
        else if (scores[y][x] == biggest_score)
        {
            has_same_biggestScore = true;
        }

        if ((!has_same_biggestScore && biggest_score == scores[x][x]) || (!has_same_smallestScore && smallest_score == scores[x][x]))
        {
            sum_of_scores -= scores[x][x];
            answer += GetGrade((double)sum_of_scores / (double)(student_Count - 1));
        }
        else
        {
            answer += GetGrade((double)sum_of_scores / (double)student_Count);
        }
    }

    return answer;
}