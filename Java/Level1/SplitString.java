/*
 *  https://school.programmers.co.kr/learn/courses/30/lessons/140108?language=java
 */

class Solution {
    public int solution(String s) {
        int answer = 0, targetCount = 1, nonTargetCount = 0;
        char target = s.charAt(0);

        for (int i = 1; i < s.length(); ++i) {
            if (targetCount == nonTargetCount) {
                ++answer;
                target = s.charAt(i);
            }

            if(target == s.charAt(i)) {
                ++targetCount;
            } else {
                ++nonTargetCount;
            }
        }

        return answer;
    }
}