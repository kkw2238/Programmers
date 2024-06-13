




/*
#include <iostream>

/*
https://programmers.co.kr/learn/courses/30/lessons/42893
*/

#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

/*
    �� ���������� ���ؼ� �⺻����, �ܺ� ��ũ ��, ��ũ����, �׸��� ��Ī������ ���� �� �ִ�.
    �� ���������� �⺻������ �ش� ���������� �ؽ�Ʈ ��, �˻�� �����ϴ� Ƚ���̴�. (��ҹ��� ����)
    �� ���������� �ܺ� ��ũ ���� �ش� ������������ �ٸ� �ܺ� �������� ����� ��ũ�� �����̴�.
    �� ���������� ��ũ������ �ش� ���������� ��ũ�� �ɸ� �ٸ� ���������� �⺻���� �� �ܺ� ��ũ ���� �����̴�.
    �� ���������� ��Ī������ �⺻������ ��ũ������ ������ ����Ѵ�.

    pages�� HTML ������ ���������� ���ڿ� ���·� ����ִ� �迭�̰�, ���̴� 1 �̻� 20 �����̴�.

    �� �������� ���ڿ��� ���̴� 1 �̻� 1,500 �����̴�.
        ���������� index�� pages �迭�� index�� ������ 0���� �����Ѵ�.

    �� ���������� url�� HTML�� <head> �±� ���� <meta> �±��� ������ �־�����.
        �������, �Ʒ��� ���� meta tag�� ������ �� ���������� url�� https://careers.kakao.com/index �̴�.
        <meta property=og:url content=https://careers.kakao.com/index />

    �� ������������ ��� �ܺ� ��ũ�� <a href=https://careers.kakao.com/index>�� ���¸� ������.
        <a> ���� �ٸ� attribute�� �־����� ���� ������ �׻� href�� ������ ����Ʈ�� url�� ���Եȴ�.
        ���� ��쿡�� �ش� ���������� https://careers.kakao.com/index �� �ܺθ�ũ�� ������ �ִٰ� �� �� �ִ�.
        ��� url�� https:// �θ� �����Ѵ�.

    �˻��� word�� �ϳ��� ���� �ܾ�θ� �־����� ���ĺ� �ҹ��ڿ� �빮�ڷθ� �̷���� �ִ�.
        word�� ���̴� 1 �̻� 12 �����̴�.
        �˻�� ã�� ��, ��ҹ��� ������ �����ϰ� ã�´�.
        ������� �˻�� blind�� ��, HTML ���� Blind��� �ܾ �ְų�, BLIND��� �ܾ ������ �� ��� ��� �ش�ȴ�.
        �˻���� �ܾ� ������ ���ϸ�, �ܾ�� ������ ��ġ�ϴ� ��쿡�� �⺻ ������ �ݿ��Ѵ�.
        �ܾ�� ���ĺ��� ������ �ٸ� ��� ���ڷ� �����Ѵ�.
        ������� �˻�� aba �� ��, abab abababa�� �ܾ� ������ ��ġ�ϴ°� ������, �⺻ ������ 0���� �ȴ�.
        ���� �˻�� aba ���, aba@aba aba�� �ܾ� ������ ������ ��ġ�ϹǷ�, �⺻ ������ 3���̴�.

    ����� �����ٶ�, ������ ��Ī������ ���� ���������� ���� ����� ���� index ��ȣ�� ���� ���� �͸� �����Ѵ�
        ��, ���������� �����̰�, ���� ��Ī������ 3,1,3 �̶�� ���� ���� index ��ȣ�� 0�� �����ϸ� �ȴ�.


*/


#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Site {
    string url;
    int index = 0;
    double baseScore = 0;
    double linkScore = 0;
    double matchingScore = 0;
    vector<string> externSite;
};

string GetURL(string& html)
{
    const string CONTENT_STRING = "<meta property=\"og:url\" content=";
    const string END_STRING = "/>";

    int index = html.find(CONTENT_STRING) + CONTENT_STRING.length() + 1;

    return html.substr(index, html.find(END_STRING, index) - index - 1);
}

double GetBaseScore(string& html, const string& word) {
    double score = 0.0;
    string substr = "";
    auto iter = html.begin();

    while (iter != html.end()) {
        iter = find(iter, html.end(), word[0]);

        substr = string(iter, find_if(iter, html.end(), [](const char c) {
            return !(c >= 'a' && c <= 'z');
        }));

        if (word.compare(substr) == 0) score += 1.0;
        if (iter != html.end()) iter += substr.length();
    }

    return score;
}

vector<string> GetExternSite(string& html) {
    const string HREF_STRING = "<a href=";
    const string END_STRING = ">";

    vector<string> result;

    int index = 0;

    while (index != string::npos) {
        index = html.find(HREF_STRING, index);

        if (index != string::npos) {
            index += HREF_STRING.length() + 1;

            int tmpIndex = html.find(END_STRING, index) - index - 1;
            result.emplace_back(html.substr(index, tmpIndex));
            
            index += tmpIndex;
        }
    }

    return result;
}

Site GetPageInfo(string& html, const string& word) {
    Site siteInfo;

    siteInfo.url = GetURL(html);
    siteInfo.baseScore = GetBaseScore(html, word);
    siteInfo.externSite = GetExternSite(html);

    return siteInfo;
}

int solution(string word, vector<string> pages) {
    map<string, Site> siteInfos;
    int answer = 0;

    transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (int index = 0; index < pages.size(); ++index) {
        transform(pages[index].begin(), pages[index].end(), pages[index].begin(), ::tolower);

        Site site = GetPageInfo(pages[index], word);
        site.index = index;
        siteInfos[site.url] = site;
    }

    for (pair<string, Site> siteInfo : siteInfos) {
        for (string url : siteInfo.second.externSite) {
            if(siteInfos.find(url) != siteInfos.end())
                siteInfos[url].linkScore += siteInfo.second.baseScore / (double)siteInfo.second.externSite.size();
        }
    }

    double bestScore = 0.0;
    for (pair<string, Site> siteInfo : siteInfos) {
        siteInfo.second.matchingScore = siteInfo.second.baseScore + siteInfo.second.linkScore;
        if (siteInfo.second.matchingScore >= bestScore) {
            if (siteInfo.second.matchingScore == bestScore)
                answer = answer < siteInfo.second.index ? answer : siteInfo.second.index;
            else
                answer = siteInfo.second.index;

            bestScore = siteInfo.second.matchingScore;
        }
    }

    return answer;
}

void main()
{
    string word = "Muzi";
    vector<string> pages = {
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"};

    solution(word, pages);
}


/*
struct Site {
    int index = 0;
    double baseScore = 0.0;
    double linkScore = 0.0;
    vector<string> linkSites;
};

void TransformToLower(string& strings) {
    transform(strings.begin(), strings.end(), strings.begin(), [](char c) { return tolower(c); });
}

string GetSiteName(string head) {
    string siteNameStart = "meta property=\"og:url\" content=\"https";
    int startIndex = head.find(siteNameStart) + siteNameStart.length();
    int endIndex = head.find('\"', startIndex);

    return head.substr(startIndex, endIndex - startIndex);
}

vector<string> ExternLink(string& body) {
    string externLinkStart = "<a href=\"https";

    vector<string> result;

    int wordIndex = body.find(externLinkStart) + externLinkStart.length();
    while (true) {
        if (wordIndex == externLinkStart.length() - 1) break;

        int wordLength = body.find("\"", wordIndex) - wordIndex;
        result.push_back(body.substr(wordIndex, wordLength));

        body.erase(wordIndex - externLinkStart.length(), body.find("</a>", wordIndex) + 4);

        wordIndex = body.find(externLinkStart) + externLinkStart.length();
    }

    return result;
}

double BaseScore(string& html, string word) {
    int wordIndex = html.find(word);
    double baseScore = 0.0;

    while (true) {
        if (wordIndex == -1) break;

        if (html[wordIndex - 1] >= 'a' && html[wordIndex - 1] <= 'z') {
            ++wordIndex;
            continue;
        }

        int wordLength = distance(html.begin() + wordIndex, find_if(html.begin() + wordIndex, html.end(),
            [](const char c) { return c < 'a' || c > 'z'; })
        );

        string substring = html.substr(wordIndex, wordLength);
        baseScore += substring.compare(word) == 0 ? 1.0f : 0.0f;
        wordIndex = html.find(word, wordIndex + wordLength);
    }
    return baseScore;
}

Site MakeSiteInfo(string& html, string word, int index) {
    Site site;
    site.index = index;
    site.baseScore = BaseScore(html, word);
    site.linkSites = ExternLink(html);

    return site;
}

int solution(string word, vector<string> pages) {
    map<string, Site> mapSiteInfo;
    double score = 0.0;
    int index = 21;
    TransformToLower(word);

    for (int i = 0; i < pages.size(); ++i) {
        TransformToLower(pages[i]);
        mapSiteInfo[GetSiteName(pages[i])] = MakeSiteInfo(pages[i], word, i);
    }

    for (pair<string, Site> p : mapSiteInfo) {
        for (string site : p.second.linkSites) {
            if (mapSiteInfo.find(site) == mapSiteInfo.end()) continue;

            mapSiteInfo[site].linkScore += p.second.baseScore / (double)p.second.linkSites.size();
        }
    }
    for (pair<string, Site> p : mapSiteInfo) {
        if (p.second.baseScore + p.second.linkScore >= score) {
            if (p.second.baseScore + p.second.linkScore == score)
                index = index < p.second.index ? index : p.second.index;
            else
                index = p.second.index;
            score = p.second.baseScore + p.second.linkScore;
        }
    }

    return index;
}

int main() {
    string word = "Muzi";
    vector<string> pages =
    {
    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tAmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"
    };

    cout << solution(word, pages);
}
*/