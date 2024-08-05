/*
 *  https://school.programmers.co.kr/learn/courses/30/lessons/136798?language=java
 */

class Solution {
    public int getDivisorCount(int n) {
        int result = 0;
        final int sqrtN = (int)Math.sqrt((double)n);
    
        for (int i = 1; i <= sqrtN; ++i) {
            if (n % i == 0) {
                result += 2;
                if ((i * i) == n) {
                    --result;
                }
            }
        }
    
        return result;
    }
    
    public int solution(int number, int limit, int power) {
        int answer = 0;
    
        for(int i = 1; i <= number; ++i) {
            int count = getDivisorCount(i);
            if(count > limit) {
                count = power;
            }

            answer += count;
        }
    
        return answer;
    }
}