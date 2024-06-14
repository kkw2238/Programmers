/*
 *  https://school.programmers.co.kr/learn/courses/30/lessons/12934?language=java
 */

public class integerSquareRoot {
    class Solution {
        public long solution(long n) {
            long range = (long)Math.sqrt(50000000000000d);
            
            for(long i = 1; i <= range; ++i)
            {
                long p = i * i;
                
                if(p == n)
                {
                    return (i + 1) * (i + 1);
                }
                else if(p > n)
                {
                    return -1;
                }
            }
            
            return -1;
        }
    }
}
