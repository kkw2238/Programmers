#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(string s) {
    const map<string, int> numberStrN{ 
        { "zero", 0 },
        { "one", 1 }, 
        { "two", 2 }, 
        { "three", 3 }, 
        { "four", 4 }, 
        { "five", 5 }, 
        { "six", 6}, 
        { "seven", 7 }, 
        { "eight", 8 }, 
        { "nine", 9} 
    };

    for (auto [sNum, iNum] : numberStrN)
    {
        while (true) {
            if (int pos = s.find(sNum); pos != -1)
            {
                s.replace(s.find(sNum), sNum.length(), to_string(iNum));
            }
            else
            {
                break;
            }
        }
    }

    return stoi(s);
}

#include <iostream>
int main()
{
    string s = "one4seveneight";

    cout << solution(s);
}