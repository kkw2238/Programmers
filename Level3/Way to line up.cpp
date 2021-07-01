/*
    https://programmers.co.kr/learn/courses/30/lessons/12936
*/

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 1 ~ n까지의 factorial을 저장 => 중복 계산을 막기 위한 처리
vector<long long> GetFactorials(int n)
{
    vector<long long> factorials(n + 1, 1);

    for (int i = 2; i <= n; ++i)
    {
        factorials[i] = factorials[i - 1] * i;
    }

    return factorials;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<long long> factorials = GetFactorials(n--);
    // 사용 가능한 숫자
    vector<int> remainingNum(n + 1);
   
    // ( 1 ~ n )까지 채운다.
    iota(remainingNum.begin(), remainingNum.end(), 1);
    // 순영 제일 첫 인덱스를 0으로 정했기에 k를 1 감소
    --k;

    // 모든 숫자가 다 들어갈때까지 반복
    while (answer.size() != factorials.size() - 1)
    {
        // n번째 숫자는 k / (n - 1)! 번쨰 인덱스의 숫자를 사용
        /*
           ex) k = 5 / ramain number 1 2 3
                    => remain number[ k / 2 ]  => 3
        */
        int lineupNumberIndex = k / factorials[n];
        int lineupNumber = remainingNum[lineupNumberIndex];

        answer.emplace_back(lineupNumber);
        // 이미 사용한 숫자는 제거
        remainingNum.erase(remainingNum.begin() + lineupNumberIndex);

        k = k % (long long)factorials[n--];
    }

    return answer;
}

/*
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer(n, 1);
    iota(answer.begin(), answer.end(), 1);

    do {
        --k;
    } while (k > 0 && next_permutation(answer.begin(), answer.end()));

    return answer;
}
*/