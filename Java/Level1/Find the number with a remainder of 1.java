/*
	https://school.programmers.co.kr/learn/courses/30/lessons/87389
*/

class Solution {
    public int solution(int n) {
        int answer = 0;
        int sqrtN = (int)Math.sqrt(n);
        
        for(int i = 1; i <= sqrtN; ++i)
        {
            if(n % i == 1)
            {
                return i;
            }
            else if(n % (n - i) == 1)
            {
                answer = n - i;
            }
        }
        
        return answer;
    }
}