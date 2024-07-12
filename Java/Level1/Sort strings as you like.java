/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12915
*/

import java.util.Arrays;

class Solution {
    public String[] solution(String[] strings, int n) {
        Arrays.sort(strings, (a, b) -> {
            char ac = a.toCharArray()[n];
            char bc = b.toCharArray()[n];

            if(ac == bc)
            {
                return a.compareTo(b);
            }

            return a.toCharArray()[n] - b.toCharArray()[n];
        });
        
        return strings;
    }
}