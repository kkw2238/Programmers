/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/131705?language=java
 */

 class Solution {
    int getTrioCount(int[] number, int index, int count, int sum)
    {
        int result = 0;

        if(count == 3)
        {
            return sum == 0 ? 1 : 0;
        }

        for(int i = index + 1; i < number.length; ++i)
        {
            result += getTrioCount(number, i, count + 1, sum + number[i]);
        }

        return result;
    }
    public int solution(int[] number) {
        return getTrioCount(number, -1, 0, 0);
    }
}