/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12943
*/

class Solution {
    public int collatz(long num) {
        int count = 0;
        
        while(num != 1 && count < 500) {
            if(num % 2 == 0) {
                num = num / 2;    
            } 
            else {
                num = num * 3 + 1;
            }

            ++count;
        }
        
        return count;
    }
    
    public int solution(int num) {
        int answer = collatz((long)num);
        
        return answer >= 500 ? -1 : answer;
    }
}