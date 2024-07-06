/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12944?language=java
*/

class Solution {
    public double solution(int[] arr) {
        double answer = 0;
        
        for(int n : arr)
        {
            answer += (double)n;
        }
        
        return answer / (double)arr.length;
    }
}