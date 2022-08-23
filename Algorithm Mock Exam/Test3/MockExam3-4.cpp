#include <string>
#include <vector>
#include <map>

using namespace std;

vector<bool> isBright;
map<int, vector<int>> roads;

int bright(int index)
{
    int result = 0;
    for (int lightHouseIndex : roads[index])
    {
        if (!isBright[lightHouseIndex])
        {
            isBright[lightHouseIndex] = true;
            ++result;
        }
    }

    return result;
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    int brighten = 0;
    isBright = vector<bool>(n, false);

    for (vector<int>& road : lighthouse)
    {
        roads[road[0]].push_back(road[1]);
        roads[road[1]].push_back(road[0]);
    }

    for (const auto& road : roads)
    {
        if (road.second.size() == 1 && !isBright[road.first])
        {
            brighten += bright(road.second[0]);
            ++answer;
       
    }

    if (brighten != n)
    {

    }

    return answer;
}