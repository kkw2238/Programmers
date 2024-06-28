/*
    https://school.programmers.co.kr/learn/courses/30/lessons/77884?language=java
*/
class Solution {
    public int getGDCCount(int n)
    {
        int result = 0;
        int sqrt = (int)Math.sqrt(n);
        for(int i = 1; i <= sqrt + 1; ++i)
        {
            if(n % i == 0)
            {
                result += 2;
            }

            if(i * i == n)
            {
                --result;
            }
        }

        return result;
    }

    public int solution(int left, int right) {
        int answer = 0;

        for(int i = left; i <= right; ++i)
        {
            int n = getGDCCount(i);

            if(n % 2 == 0)
            {
                answer += i;
            }
            else
            {
                answer -= i;
            }
        }

        return answer;
    }
}