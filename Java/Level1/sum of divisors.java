/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12928?language=java
 */

 class Solution {
    public int solution(int n) {
        int answer = 0;
        int sqrtNum = (int) Math.sqrt(n);

        for(int i = 1; i <= sqrtNum; ++i)
        {
            if(n % i == 0)
            {
                answer += i + n / i;

                if(i == n / i)
                {
                    answer -= i;
                }
            }
        }

        return answer;
    }
}