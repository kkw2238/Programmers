/*
	https://school.programmers.co.kr/learn/courses/30/lessons/142086?language=java
*/

import java.util.HashMap;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        HashMap<Character, Integer> indices = new HashMap<>();

        char[] charArr = s.toCharArray();

        for(int i = 0; i < charArr.length; ++i)
        {
            if(indices.get(charArr[i]) != null)
            {
                answer[i] = i - indices.get(charArr[i]);
                indices.replace(charArr[i], i);
            }
            else
            {
                indices.put(charArr[i], i);
                answer[i] = -1;
            }
        }

        return answer;
    }
}