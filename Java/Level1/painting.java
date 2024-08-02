/*
    ttps://school.programmers.co.kr/learn/courses/30/lessons/161989?language=java
 */

class Solution {
    public int solution(int n, int m, int[] section) {
        int beforeSection = section[0];
        int answer = 1;
        int nextSection = beforeSection + m - 1;

        for (int i = 1; i < section.length; ++i){
            if(section[i] <= nextSection) {
                continue;
            }

            nextSection = section[i] + m - 1;
            ++answer;
        }

        return answer;
    }
}