




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
    한 웹페이지에 대해서 기본점수, 외부 링크 수, 링크점수, 그리고 매칭점수를 구할 수 있다.
    한 웹페이지의 기본점수는 해당 웹페이지의 텍스트 중, 검색어가 등장하는 횟수이다. (대소문자 무시)
    한 웹페이지의 외부 링크 수는 해당 웹페이지에서 다른 외부 페이지로 연결된 링크의 개수이다.
    한 웹페이지의 링크점수는 해당 웹페이지로 링크가 걸린 다른 웹페이지의 기본점수 ÷ 외부 링크 수의 총합이다.
    한 웹페이지의 매칭점수는 기본점수와 링크점수의 합으로 계산한다.

    pages는 HTML 형식의 웹페이지가 문자열 형태로 들어있는 배열이고, 길이는 1 이상 20 이하이다.

    한 웹페이지 문자열의 길이는 1 이상 1,500 이하이다.
        웹페이지의 index는 pages 배열의 index와 같으며 0부터 시작한다.

    한 웹페이지의 url은 HTML의 <head> 태그 내에 <meta> 태그의 값으로 주어진다.
        예를들어, 아래와 같은 meta tag가 있으면 이 웹페이지의 url은 https://careers.kakao.com/index 이다.
        <meta property=og:url content=https://careers.kakao.com/index />

    한 웹페이지에서 모든 외부 링크는 <a href=https://careers.kakao.com/index>의 형태를 가진다.
        <a> 내에 다른 attribute가 주어지는 경우는 없으며 항상 href로 연결할 사이트의 url만 포함된다.
        위의 경우에서 해당 웹페이지는 https://careers.kakao.com/index 로 외부링크를 가지고 있다고 볼 수 있다.
        모든 url은 https:// 로만 시작한다.

    검색어 word는 하나의 영어 단어로만 주어지며 알파벳 소문자와 대문자로만 이루어져 있다.
        word의 길이는 1 이상 12 이하이다.
        검색어를 찾을 때, 대소문자 구분은 무시하고 찾는다.
        예를들어 검색어가 blind일 때, HTML 내에 Blind라는 단어가 있거나, BLIND라는 단어가 있으면 두 경우 모두 해당된다.
        검색어는 단어 단위로 비교하며, 단어와 완전히 일치하는 경우에만 기본 점수에 반영한다.
        단어는 알파벳을 제외한 다른 모든 문자로 구분한다.
        예를들어 검색어가 aba 일 때, abab abababa는 단어 단위로 일치하는게 없으니, 기본 점수는 0점이 된다.
        만약 검색어가 aba 라면, aba@aba aba는 단어 단위로 세개가 일치하므로, 기본 점수는 3점이다.

    결과를 돌려줄때, 동일한 매칭점수를 가진 웹페이지가 여러 개라면 그중 index 번호가 가장 작은 것를 리턴한다
        즉, 웹페이지가 세개이고, 각각 매칭점수가 3,1,3 이라면 제일 적은 index 번호인 0을 리턴하면 된다.


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