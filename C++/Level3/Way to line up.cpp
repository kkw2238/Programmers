/*
    https://programmers.co.kr/learn/courses/30/lessons/12936
*/

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 1 ~ n������ factorial�� ���� => �ߺ� ����� ���� ���� ó��
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
    // ��� ������ ����
    vector<int> remainingNum(n + 1);
   
    // ( 1 ~ n )���� ä���.
    iota(remainingNum.begin(), remainingNum.end(), 1);
    // ���� ���� ù �ε����� 0���� ���߱⿡ k�� 1 ����
    --k;

    // ��� ���ڰ� �� �������� �ݺ�
    while (answer.size() != factorials.size() - 1)
    {
        // n��° ���ڴ� k / (n - 1)! ���� �ε����� ���ڸ� ���
        /*
           ex) k = 5 / ramain number 1 2 3
                    => remain number[ k / 2 ]  => 3
        */
        int lineupNumberIndex = k / factorials[n];
        int lineupNumber = remainingNum[lineupNumberIndex];

        answer.emplace_back(lineupNumber);
        // �̹� ����� ���ڴ� ����
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