/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12939?language=java
 */

class Solution {
    public String solution(String s) {
        String[] splitStrings = s.split(" ");
        int minimum = Integer.MAX_VALUE;
        int maximum = Integer.MIN_VALUE;

        for(String str : splitStrings) {
            int num = Integer.parseInt(str);

            minimum = Integer.min(minimum, num);
            maximum = Integer.max(maximum, num);
        }

        return String.valueOf(minimum) + " " + String.valueOf(maximum);
    }
}