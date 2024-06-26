/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12922
*/

class Solution {
    public String solution(int n) {
        String answer = new String("수박").repeat(n / 2);
        if(n % 2 == 1)
        {
            answer += "수";
        }
        return answer;
    }
}