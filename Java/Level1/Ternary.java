/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/68935
 */

class Solution {
    public int solution(int n) {
        String result = "";
        int index = 1, answer = 0;

        while(n != 0)
        {
            result = String.valueOf(n % 3) + result;
            n /= 3;
        }

        for(int i = 0; i < result.length(); ++i)
        {
            answer += (result.charAt(i) - '0') * index;
            index *= 3;
        }

        return answer;
    }
}