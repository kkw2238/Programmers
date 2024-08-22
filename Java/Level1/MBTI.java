/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=java
 */

import java.util.HashMap;
import java.util.Map;

class Solution {
    public String solution(String[] survey, int[] choices) {
        StringBuilder answer = new StringBuilder();
        Map<Character, Integer> scores = new HashMap<>(){{
            put('R', 0);
            put('T', 0);
            put('C', 0);
            put('F', 0);
            put('J', 0);
            put('M', 0);
            put('A', 0);
            put('N', 0);
        }};

        String[] typePosition = {"RT", "CF", "JM", "AN"};

        for(int i = 0; i < survey.length; ++i){
            if(choices[i] < 4) {
                Integer num = scores.containsKey(survey[i].charAt(0)) ? scores.get(survey[i].charAt(0)) : 0;
                scores.put(survey[i].charAt(0), num + 4 - choices[i]);
            } else if(choices[i] > 4) {
                Integer num = scores.containsKey(survey[i].charAt(1)) ? scores.get(survey[i].charAt(1)) : 0;
                scores.put(survey[i].charAt(1), num + choices[i] - 4);
            }
        }

        for(int i = 0; i < 4; ++i) {
            Integer type1 = scores.get(typePosition[i].charAt(0));
            Integer type2 = scores.get(typePosition[i].charAt(1));

            if(type1 >= type2) {
                answer.append(typePosition[i].charAt(0));
            } else {
                answer.append(typePosition[i].charAt(1));
            } 
        }

        return answer.toString();
    }
}