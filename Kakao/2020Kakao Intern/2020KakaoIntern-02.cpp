/*
T ��ó ȸ�縦 ��ϰ� �ִ� ���̾��� �ų� �系 ��Ŀ�� ��ȸ�� �����Ͽ� ����ڿ��� ����� �����ϰ� �ֽ��ϴ�.
�̹� ��ȸ������ ����ڿ��� ���޵Ǵ� ����� ���� ��ȸ�ʹ� �ٸ��� ������ ���� ������� �����Ϸ��� �մϴ�.
��Ŀ�� ��ȸ�� �����ϴ� ��� �����ڵ鿡�Դ� ���ڵ�� 3������ ���깮��(+, -, *) ������ �̷���� ���� ������ ���޵Ǹ�, �������� �̼��� ���޹��� ���Ŀ� ���Ե� �������� �켱������ �����Ӱ� �������Ͽ� ���� �� �ִ� ���� ū ���ڸ� �����ϴ� ���Դϴ�.
��, �������� �켱������ ���� ������ ��, ���� ������ �����ڴ� ����� �մϴ�. ��, + > - > * �Ǵ� - > * > + ��� ���� ������ �켱������ ������ �� ������ +,* > - �Ǵ� * > +,-ó�� 2�� �̻��� �����ڰ� ������ ������ �������� ������ �켱������ ������ ���� �����ϴ�. ���Ŀ� ���Ե� �����ڰ� 2����� ������ �� �ִ� ������ �켱���� ������ 2! = 2�����̸�, �����ڰ� 3����� 3! = 6���� ������ �����մϴ�.
���� ���� ����� ������� �ش� ������ �������� ��ȯ�Ͽ� �����ϸ� ������ ���ڰ� ���� ū �����ڸ� ����ڷ� �����ϸ�, ����ڰ� ������ ���ڸ� ��»������ �����ϰ� �˴ϴ�.

���� ���, ������ �� �׿��� �Ʒ��� ���� ������ ���޹޾Ҵٰ� �����մϴ�.

"100-200*300-500+20"

�Ϲ������� ���� �� �����п��� ��ӵ� ������ �켱������ ������ ���ϱ�� ����� ���� �����ϸ� ���ϱ�� ���ϱ�, ���⿡ ���� �켱������ ���� * > +,- �� �켱������ ���ǵǾ� �ֽ��ϴ�.
��ȸ ��Ģ�� ���� + > - > * �Ǵ� - > * > + ��� ���� ������ �켱������ ������ �� ������ +,* > - �Ǵ� * > +,- ó�� 2�� �̻��� �����ڰ� ������ ������ �������� ������ �켱������ ������ ���� �����ϴ�.
���Ŀ� �����ڰ� 3�� �־������Ƿ� ������ ������ �켱���� ������ 3! = 6�����̸�, �� �� + > - > * �� ������ �켱������ ���Ѵٸ� �ᱣ���� 22,000���� �˴ϴ�.
�ݸ鿡 * > + > - �� ������ �켱������ ���Ѵٸ� ������ �ᱣ���� -60,420 ������, ��Ģ�� ���� ��� �� ����� ������ 60,420���� �˴ϴ�.

�����ڿ��� �־��� ���� ������ ��� ���ڿ� expression�� �Ű������� �־��� ��, ��� �� ���� �� �ִ� ���� ū ��� �ݾ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

[���ѻ���]
expression�� ���̰� 3 �̻� 100 ������ ���ڿ��Դϴ�.
expression�� ���鹮��, ��ȣ���� ���� ������ ���ڿ� 3������ ������(+, -, *) ������ �̷���� �ùٸ� ����ǥ���(������ �� ��� ���̿� �����ȣ�� ����ϴ� ���)���� ǥ���� ������Դϴ�. �߸��� ������� �Է����� �־����� �ʽ��ϴ�.
��, "402+-561*"ó�� �߸��� ������ �ùٸ� ����ǥ����� �ƴϹǷ� �־����� �ʽ��ϴ�.
expression�� �ǿ�����(operand)�� 0 �̻� 999 ������ �����Դϴ�.
��, "100-2145*458+12"ó�� 999�� �ʰ��ϴ� �ǿ����ڰ� ���Ե� ������ �Է����� �־����� �ʽ��ϴ�.
"-56+100"ó�� �ǿ����ڰ� ������ ���ĵ� �Է����� �־����� �ʽ��ϴ�.
expression�� ��� 1�� �̻��� �����ڸ� �����ϰ� �ֽ��ϴ�.
������ �켱������ ��� �����ϴ���, expression�� �߰� ��갪�� ���� �ᱣ���� ������ 263 - 1 ���ϰ� �ǵ��� �Է��� �־����ϴ�.
���� �����ڳ����� �տ� �ִ� ���� �켱������ �� �����ϴ�.

*/

#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void MakeComb(vector<char>& v, int tier, vector<char> comb, vector<vector<char>>& result) {
    if (tier == v.size()) {
        result.push_back(comb);
    }

    for (int i = tier; i < v.size(); ++i) {
        swap(v[tier], v[i]);
        comb.push_back(v[tier]);
        MakeComb(v, tier + 1, comb, result);
        comb.pop_back();
    }
}

long long oper(long long lValue , int oper, int rValue) {
    switch (oper) {
        case '+':
            return lValue + rValue;
        case '-':
            return lValue - rValue;
        case '*':
            return lValue * rValue;
    }
}

long long cal(vector<char>& v, string expression, long long& answer) {
   
    long long result; 
    for(int i = 0; i < 3; ++i) {
        auto iter = expression.begin();
        auto find_iter = expression.begin();

        while (true) {
            find_iter = find(find_iter + 1, expression.end(), v[i]);
            if (find_iter != expression.end()) {
                long long lValue = 0, rValue = 0;
                auto next_oper_iter = find_iter;
                int offset = 1;
                while (distance(find_iter, next_oper_iter) <= 1) {
                    next_oper_iter = find_if(find_iter + offset, expression.end(), [&v, &i](const char c) {
                        if (c == '+' || c == '-' || c == '*') {
                            return true;
                        }
                        return false;
                    });
                    ++offset;
                }

                auto t = find_iter - 1;
                for (t; t > expression.begin(); --t) {
                    if (*t == '+' || *t == '-' || *t == '*') {
                        if (*(t - 1) == '-') continue;
                        if (*t != v[i])
                            break;
                    }
                }

                if (t != expression.begin()) {
                    ++t;
                }
   
                lValue = stoll(string(t, find_iter));
                rValue = stoll(string(find_iter + 1, next_oper_iter));

                lValue = oper(lValue, v[i], rValue);

                int dist = distance(t, next_oper_iter);

                expression.replace(t, next_oper_iter, to_string(lValue));

                find_iter += -dist + to_string(lValue).length();
            }
            else
                break;
        }
    }

    result = stoll(expression);
    result = result < 0 ? -result : result;
    answer = answer > result ? answer : result;

    return answer;
}

#include "Util.h"
long long solution(string expression) {
    long long answer = 0;
    vector<char> operators = { '+', '-', '*' };
    vector<vector<char>> combinationsOper;
    MakeComb(operators, 0, vector<char>(), combinationsOper);

    for (vector<char>& v : combinationsOper) {
        long long calculation = cal(v, expression, answer);
    }
    
    return answer;
}

#include <iostream>
int main() {
    string expression = "100-200*300-500+20";
    cout << solution(expression);
}