/*
    https://programmers.co.kr/learn/courses/30/lessons/42576
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    // ������ʿ� �����ڸ� �����Ѵ�.
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int maratoner = 0; maratoner < completion.size(); ++maratoner)
    {
        // ������ �������� ������ �߱� ������ �ش� �ε����� �����ڿ� ��������� �̸��� �ٸ� ��� �ش� �ε����� ������ʴ� ���ָ� ���ߴٴ� ���̴�. 
        if (completion[maratoner].compare(participant[maratoner]) != 0)
        {
            return participant[maratoner];
        }
    }

    // �����ڱ��� ��ŭ ã�� ���� ��� ��������� ������ �ε����� ���ָ� ���� ���� �����̴�.
    return participant.back();
}

// ���� �ڵ�
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