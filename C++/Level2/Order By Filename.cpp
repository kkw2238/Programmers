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
        // head 분리
        auto iter = s.begin();
        auto nextPartIter = find_if(iter, s.end(), isdigit);

        head = string(iter, nextPartIter);
            // 나중 Compare 함수에서의 연산을 줄이기 위해 소문자로 변환
        transform(head.begin(), head.end(), head.begin(), tolower);

        // number분리
        iter = find_if(nextPartIter, s.end(), [](const char c) { return !isdigit(c); });
        number = stoi(string(nextPartIter, iter));

        // 원본 파일명도 같이 저장한다.
        originalName = s;

        // 파일 순서를 알기위한 index
        index = fileindex;
    }

    bool operator<(FileName& fn1)
    {
        // 헤드 > 넘버 > 인덱스 기준으로 정렬
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
