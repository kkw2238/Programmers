/*
    https://programmers.co.kr/learn/courses/30/lessons/86048
*/

#include <algorithm>
#include <vector>
#include <list>

using namespace std;

void CheckAcrossBetweenPerson(vector<int>& counting, list<int>& entrance)
{
    for (int person : entrance)
    {
        ++counting[person - 1];
    }
}

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer(enter.size());
    list<int> entrance;

    int leaveIndex = 0;
    int enterIndex = 0;

    while(leaveIndex < leave.size())
    { 
        if (enterIndex < enter.size()) 
        {
            entrance.push_back(enter[enterIndex++]);
        }

        if (leave[leaveIndex] == entrance.back())
        {
            entrance.pop_back();
            answer[leave[leaveIndex++] - 1] += entrance.size();
            CheckAcrossBetweenPerson(answer, entrance);

            auto iter = find(entrance.begin(), entrance.end(), leave[leaveIndex]);
            while (iter != entrance.end())
            {
                entrance.erase(iter);
                answer[leave[leaveIndex++] - 1] += entrance.size();
                CheckAcrossBetweenPerson(answer, entrance);

                if (leaveIndex >= leave.size())
                {
                    break;
                }

                iter = find(entrance.begin(), entrance.end(), leave[leaveIndex]);
            }
        }
    }

    return answer;
}

int main()
{
    solution({ 3, 2, 1 }, { 2, 1, 3 });
}