/*
    https://school.programmers.co.kr/learn/courses/30/lessons/120817?language=java
*/
class Solution {
    public double solution(int[] numbers) {
        double answer = 0;
        
        for(int n : numbers)
        {
            answer += (double)n;
        }
        
        return answer / (double)numbers.length;
    }
}