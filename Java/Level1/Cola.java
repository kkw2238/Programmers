/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/132267?language=java
 */

class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;
        while(n >= a)
        {
            int getBottles = (n / a) * b;

            answer += getBottles;
            n = n % a + getBottles;
        }
        return answer;
    }
}