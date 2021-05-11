#include <string>
#include <vector>

using namespace std;

const int MANHATTEN_DISTANCE = 2;
const int MAX_SIZE = 5;

const int Abs(const int n)
{
    return n < 0 ? -n : n;
}

struct Position {
    Position(int yPos, int xPos)
    {
        y = yPos;
        x = xPos;
    }

    const int GetManhattanToB(const Position& b)
    {   
        return Abs(b.x - x) + Abs(b.y - y);
    }

    int x;
    int y;
};

vector<Position> GetProgrammerPosition(const vector<string>& place)
{
    vector<Position> programmerPos;

    for (int y = 0; y < MAX_SIZE; ++y)
    {
        for (int x = 0; x < MAX_SIZE; ++x)
        {
            if (place[y][x] == 'P')
            {
                programmerPos.emplace_back( y, x );
            }
        }
    }

    return programmerPos;
}

bool HasTableABetweenB(const vector<string>& place, const Position& a, const Position& b)
{
        int xDist = (b.x - a.x) / 2 + (b.x - a.x) % 2;
        int yDist = (b.y - a.y) / 2 + (b.y - a.y) % 2;

    if (place[b.y - yDist][b.x] == 'O' || place[b.y][b.x - xDist] == 'O')
    {
        return true;
    }
    return false;
}

#include <iostream>

bool IsRightManhattan(vector<Position>& programmerPos, const vector<string>& place)
{
    for (int i = 0; i < programmerPos.size(); ++i)
    {
        for (int j = i + 1; j < programmerPos.size(); ++j)
        {
            int manhattenDist = programmerPos[i].GetManhattanToB(programmerPos[j]);
            if ( manhattenDist <= MANHATTEN_DISTANCE)
            {
                if (manhattenDist == 1 || HasTableABetweenB(place, programmerPos[i], programmerPos[j]))
                {
                    cout << programmerPos[i].x << ' ' << programmerPos[i].y << '\n';
                    cout << programmerPos[j].x << ' ' << programmerPos[j].y << '\n';
                    //return false;
                }
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {

    vector<int> answer;

    for (const vector<string>& place : places)
    {
        vector<Position> programmerPos = GetProgrammerPosition(place);
        if (IsRightManhattan(programmerPos, place))
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    return answer;
}

int main()
{
    vector<vector<string>> places{ 
        
        {
            "POPOP", 
            "OPOPO", 
            "POPOP", 
            "OPOPO", 
            "POPOP"
        }
    };

    solution(places);
}