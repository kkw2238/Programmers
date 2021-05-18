/* 
    https://programmers.co.kr/learn/courses/30/lessons/67256 
*/

#include <string>
#include <vector>

using namespace std;

enum { R_HAND_INDEX, L_HAND_INDEX };
const int ZERO_POS = 11;
const int ROW_COUNT = 3;

vector<int> hands_Position{ 12, 10 };

const int Abs(const int n)
{
    if (n < 0)
    {
        return -n;
    }

    return n;
}

int Distance(int nowPos, const int nextPos)
{
    // �ش� ���ڰ� �޼� ������ ��� ( 1, 4, 7 )
    if (nowPos % ROW_COUNT == 1)
    {
        // ����� ���� �ϱ� ���� ������ �������� ��ȯ�Ѵ�.
        nowPos += 2;
    }

    int dist = Abs(nowPos - nextPos);
    // �����Ÿ� = x�Ÿ� + y�Ÿ� => y�Ÿ� = dist / ROW_COUNT, x�Ÿ� = dist % ROW_COUNT
    return dist / ROW_COUNT + dist % ROW_COUNT;
}

int GetNearlyHandIndex(int nextNumber, const string& hand)
{
    if (nextNumber % ROW_COUNT == 2)
    {
        int distance_by_Lhand = Distance(hands_Position[L_HAND_INDEX], nextNumber);
        int distnace_by_Rhand = Distance(hands_Position[R_HAND_INDEX], nextNumber);

        // �������� �� �������
        if (distance_by_Lhand > distnace_by_Rhand)
        {
            return R_HAND_INDEX;
        }
        // �޼��� �� ����� ���
        else if (distance_by_Lhand < distnace_by_Rhand)
        {
            return L_HAND_INDEX;
        }
        else
        {
            // �ڵ��� ù ���ڰ� 'r'�ΰ�� => �������� ���
            if (hand[0] == 'r')
            {
                return R_HAND_INDEX;
            }
            else
            {
                return L_HAND_INDEX;
            }
        }
    }

    return nextNumber % ROW_COUNT;
}

string solution(vector<int> numbers, string hand) {
    const vector<char> HAND_CHARACTER{ 'R', 'L' };
    string answer = "";

    for (int number : numbers)
    {
        // ���ڰ� 0�� ��� ���� 0�� �������� 11�� ��ȯ
        if (number == 0)
        {
            number = ZERO_POS;
        }

        // �ش� �����ǿ��� ���� ����� �� Index�� ���´�.
        int handIndex = GetNearlyHandIndex(number, hand);
        answer += HAND_CHARACTER[handIndex];
        // �ش� ���� ��ġ�� �̵�
        hands_Position[handIndex] = number;
    }

    return answer;
}


/* ���� �ڵ�
#include <string>
#include <vector>

using namespace std;

int LHAND = 10, RHAND = 12;

const vector<int> KEYPAD{ 11, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int Distance(int now, int dest) {
    int result = 0;

    if (now % 3 == 1) {
        now += 1;
        result += 1;
    }
    else if (now % 3 == 0) {
        now -= 1;
        result += 1;
    }

    int step = dest > now ? dest - now : now - dest;
    return result + step / 3;
}

char FindNearlyHand(int dest, string hand) {
    int lHandDistance = Distance(LHAND, dest);
    int rHandDistance = Distance(RHAND, dest);

    if (lHandDistance == rHandDistance) return hand[0] + ('A' - 'a');
    else return lHandDistance < rHandDistance ? 'L' : 'R';
}
 
string solution(vector<int> numbers, string hand) {
    string answer = "";

    for (int number : numbers) {
        if (number == 0 || number % 3 == 2) {
            answer.push_back(FindNearlyHand(KEYPAD[number], hand));

            if (answer.back() == 'L') 
                LHAND = KEYPAD[number];
            else 
                RHAND = KEYPAD[number];
        }
        else if (number % 3 == 1) {
            answer.push_back('L');
            LHAND = number;
        }
        else {
            answer.push_back('R');
            RHAND = number;
        }
    }

    return answer;
}

int main() {
    solution(vector<int>{1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
}
*/