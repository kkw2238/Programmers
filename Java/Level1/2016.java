/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12901?language=java
 */

class Solution {
    public String solution(int a, int b) {
        int[] dayOfMonth = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        String[] nameOfDay = { "SUN", "MON", "TUE" ,"WED", "THU", "FRI", "SAT"};
        int nowDay = 5;

        for(int i = 0; i < a - 1; ++i)
        {
            nowDay += dayOfMonth[i];
        }

        nowDay += b - 1;

        return nameOfDay[nowDay % 7];
    }
}