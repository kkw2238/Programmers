/*
	https://school.programmers.co.kr/learn/courses/30/lessons/81301
*/

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(String s) {
        Map<String, String> dict = new HashMap<String,String>() {{
            put("zero" ,"0");
            put("one"  ,"1");
            put("two"  ,"2");
            put("three","3");
            put("four" ,"4");
            put("five" ,"5");
            put("six"  ,"6");
            put("seven","7");
            put("eight","8");
            put("nine" ,"9");
        }};  
         
        char[] charArr = s.toCharArray();

        String alpha = "";
        String result = "";

        for(int i = 0; i < charArr.length; ++i)
        {
            if(Character.isDigit(charArr[i]))
            {
                result += charArr[i];
                continue;
            }

            alpha += charArr[i];
            String val = dict.get(alpha);

            if(val != null)
            {
                result += val;
                alpha = "";
            }
        }

        return Integer.parseInt(result);
    }
}