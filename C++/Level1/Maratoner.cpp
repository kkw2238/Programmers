/*
    https://programmers.co.kr/learn/courses/30/lessons/42576
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    // 마라토너와 완주자를 정렬한다.
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int maratoner = 0; maratoner < completion.size(); ++maratoner)
    {
        // 동일한 조건으로 정렬을 했기 때문에 해당 인덱스의 완주자와 마라토너의 이름이 다를 경우 해당 인덱스의 마라토너는 완주를 못했다는 뜻이다. 
        if (completion[maratoner].compare(participant[maratoner]) != 0)
        {
            return participant[maratoner];
        }
    }

    // 완주자길이 만큼 찾지 못한 경우 마라토너의 마지막 인덱스가 완주를 하지 못한 상태이다.
    return participant.back();
}

// 이전 코드
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//string solution(vector<string> participant, vector<string> completion) {
//    int maratonerParticiant = 0;
//    int maratonerCompletion = 0;
//    map<string, int> maratoners;
//
//    --maratoners[participant[participant.size() - 1]];
//    for (int i = 0; i < completion.size(); ++i)
//    {
//        if (maratonerParticiant = --maratoners[participant[i]]; maratonerParticiant == 0)
//        {
//            maratoners.erase(participant[i]);
//        }
//        if (maratonerCompletion = ++maratoners[completion[i]]; maratonerCompletion == 0)
//        {
//            maratoners.erase(completion[i]);
//        }
//    }
//
//    return (*maratoners.begin()).first;
//}