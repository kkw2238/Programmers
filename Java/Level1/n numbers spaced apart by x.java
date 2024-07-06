/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12954?language=java
*/

class Solution {
    public long[] solution(int x, int n) {
        long[] answer = new long[n];
        
        for(long i = 0; i < n; ++i)
        {
            answer[(int)i] = (long)x + (long)x * i;
        }
        
        return answer;
    }
}