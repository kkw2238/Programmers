/*
	https://programmers.co.kr/learn/courses/30/lessons/17686
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FileName {
public:
    FileName(const string& s, const int fileindex)
    {
        auto iter = s.begin();
        auto nextPartIter = find_if(iter, s.end(), isdigit);

        head = string(iter, nextPartIter);
        transform(head.begin(), head.end(), head.begin(), tolower);

        iter = find_if(nextPartIter, s.end(), [](const char c) { return !isdigit(c); });
        number = stoi(string(nextPartIter, iter));

        originalName = s;
        index = fileindex;
    }

    bool operator<(FileName& fn1)
    {
        if (fn1.head.compare(head) != 0)
        {
            return fn1.head < head;
        }
        else if (fn1.number != number)
        {
            return fn1.number < number;
        }
        return fn1.index < index;
    }

public:
    string head;
    string originalName;
    int number;
    int index;
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<FileName> fileNames;

    int index = 0;
    for (const string& file : files)
    {
        fileNames.emplace_back(file, index++);
    }

    sort(fileNames.begin(), fileNames.end());

    for (const FileName& filename : fileNames)
    {
        answer.push_back(filename.originalName);
    }

    return answer;
}

int main()
{
    vector<string> files{ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    solution(files);
}