/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/133499?language=java
 */

import java.util.HashMap;
import java.util.Map;

class Solution {
    public String convertBabbling(String str, Map<Character, String> kindOfBabble) {
        String result = "";
        for (int i = 0; i < str.length();) {
            
            if (!kindOfBabble.containsKey(str.charAt(i))) {
                return "";
            } 
            String value = kindOfBabble.get(str.charAt(i));
            if (i + value.length() >= str.length() || !value.equals(str.substring(i, i + value.length()))) {
                return "";
            }

            result += String.valueOf(str.charAt(i));
            i += kindOfBabble.get(str.charAt(i)).length();
        }
        
        return result;
    }

    public boolean isCollect(String convertedStr) {
        for(int i = 1; i < convertedStr.length(); ++i) {
            if (convertedStr.charAt(i) == convertedStr.charAt(i - 1)) {
                return false;
            }
        }

        return true;
    }

    public int solution(String[] babbling) {
        int answer = 0;
        Map<Character, String> kindOfBabble = new HashMap<>() {{
            put('a', "aya");
            put('y', "ye");
            put('w', "woo");
            put('m', "ma");
        }};

        for (String str : babbling) {
            String convertStr = convertBabbling(str, kindOfBabble);

            if (!convertStr.isEmpty() && isCollect(convertStr)) {
                ++answer;
            }
        }

        return answer;
    }
}